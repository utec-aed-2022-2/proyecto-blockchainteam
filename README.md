[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8855166&assignment_repo_type=AssignmentRepo)


# Introducción  
Con el paso de los años el dinero fue tomando miles de formas, desde pesados metales hasta papel con valor impreso en el. Su forma mas compacta conocida hasta la fecha es el dinero digital.

 Con el fin de explotar este concepto de la mejor forma, nuestro proyecto planteado consiste en la creación una aplicación de transferencias. La aplicación tiene por nombre *Transfierete* , el objetivo es poder realizar transacciones de dinero desde un usuario a otro de manera segura, como una alternativa segura para los usarios.  

Como ya mencionado antes, el proyecto brindará la seguridad en los siguientes datos:  

- La identidad e información de los usuarios.  
- Los montos que transfiere y recibe.


# Descripción  
Para el realce del proyecto, se hace uso de la tecnología basada en BlockChain. Esta misma consiste en la creación de bloques enlazados, y cada bloque tendrá la información necesaria para que las transacciones se realicen de manera segura, evitando así que la información sea modificada u obtenida por otros usuarios.

# Importancia  
El manejo de BlockChain a través de bloques es sumamente importante debido a que es:

 - **No modificable**: Cada bloque depende del código encriptado del anterior, para así cuando se intente modificar algún bloque, primero se tendría que validar el anterior y así sucesivamente.
 
 - **No reconocible**: La información de los usuarios que realizan la transacción permanecerá oculta a través de un código encriptado. Así cuidar la integridad de nuestros usuarios.

 - **Nueva tecnología**: La importancia aquí es que, el BlockChain puede adaptarse a nuevas tecnologías y actualmente se considera una de las mas confiables y seguras para el transporte de información.  

# Organización  
[Link de tareas asignadas](https://github.com/orgs/utec-aed-2022-2/projects/13)

Tareas Asignadas:  
![](tareas.JPG)

# Estructuras  

![](estructura.jpeg)

DESCRIPCIÓN ESTRUCTURAS:  

- **block.h** : Contiene el registro de todas las *Transacciones*, adicionalmente contiene su *hash único* y el *hash anterior* (Ambos generados mediante una _**structura sha256**_).  
- **blockchain.h** : Contiene el registro de todas las *Transacciones*,
- **Transaction.h** : Contiene los datos de las transacciones y es conectada con cada bloque. En este apartado se puede tener mas de una transacción dentro de un bloque. 
- **sha256.h** : Se realiza el método de encriptación para la generación del Hash y prevHash.
- **md5.h** : Se usa para realizar el método de encriptación para la base de datos (PostressSQL), con el fin de tener un backup de las transacciones de forma segura e inaccesible para cualquier persona.  
- **mysql.cpp** : El archivo se encarga de realizar la conexión entre la base de datos en la nube del servicio AWS. 

# Conplejidad Big O  

## Insertar (BLockChain)

- Partiendo del concepto de listas enlazadas, la complejidad del insert será 
O(1), ya que se sacara el hash del ultimo bloque existente para vincularlo con el nuevo bloque el cual se insertara al inicio.
```c++
void BlockChain::insert_block(vector<DataD *> reg)
{
    int index = n_elements + 1;
    string *cod = nullptr;
    if (n_elements == 0)
    {
        cod = nullptr;
    }
    else
    {
        cod = &(chain.front()->get_hash());
    };
    Block *newBlock = new Block(reg, n_elements + 1);
    // newBlock->prev = chain.front();//apunta al anterior
    newBlock->setPrevHashcode(cod);
    chain.push_front(newBlock);
    addNamesToTree();
    // aqui ya tengo la data en el blockchain, ahora tengo que buscar nombres y setearlos al arbol
    this->n_elements++;

    cout << "######################################################################################" << endl
         << endl
         << "\t\t\t\tBLOQUE NRO: " << index << endl
         << endl
         << "NONCE: " << newBlock->get_nonce() << endl
         << "NRO TRANSACCIONES:  " << 4 << endl
         << endl;
    newBlock->show_data();
    string ph;
    if (newBlock->get_prev_hash() == nullptr)
        ph = '0';
    else
        ph = *(newBlock->get_prev_hash());
    cout << "CODIGO HASH PREVIO: " << ph << endl
         << "CODIGO HASH: " << newBlock->get_hash() << endl
         << endl
         << "######################################################################################" << endl
         << endl;
};

>> Complejidad = O(1)

```
## Búsqueda del Nonce

Para obtener el Hashcode del bloque, usamos el método de encriptación SHA256.

De forma general, para obtener el código hash usamos todos los datos de la transacción, el índice del bloque, y el Código hash del bloque anterior (En caso de ser el bloque 1, el código hash previo es '0'), y posteriormente procedemos a concatenarlos en un string. Luego, iniciamos un bucle (se especifica más adelante) en donde se buscará un número(nonce) aleatorio en un rango determinado(1000 - 9999) que al concatenarse con el string previo y, al obtener el código hash de ese string (llamando a la función SHA256), se obtenga un Hashcode que inicie con 4 ceros.  

```c++
string Block::createHashcode() // el codigo hash depende de todos los valores del conjunto de registros, lo cual lo hace mas seguro
{
    string to_hash = "";
    for (auto &it : registro)
    {
        to_hash += to_string(it->get_monto());
        to_hash += it->get_emisor();
        to_hash += it->get_receptor();
        to_hash += it->get_date();
        to_hash += it->get_time();
    }

    string sha;
    clock_t t;
    t = clock();
    cout << endl
         << "Buscando Nonce para Bloque " << this->index << "..." << endl;
    int count = 0;
    srand(time(NULL));
    while (true)
    {
        int valor = 1000 + rand() % 9999;
        string a = to_string(valor);
        string b = to_hash;
        a += b;
        char nuevo[a.size() + 1];
        strcpy(nuevo, a.c_str());
        sha = SHA256(nuevo);
        string c = "";
        c += sha[0];
        c += sha[1];
        c += sha[2];
        c += sha[3];
        count += 1;
        if (c == "0000")
        {
            double dif = (clock() - t) / (double)CLOCKS_PER_SEC;
            cout << "!Nonce encontrado en: " << dif << " segundos" << endl
                 << "(Se probaron " << count << " Nounces)" << endl;
            this->nonce = valor;
            break;
        }
    }

    return sha;
};
```



### La función SHA256(Secure Hash Algorithm of 256 bytes)

> Este algoritmo de encriptación es muy usado actualmente, y se dice que es el reemplazo del algoritmo de encriptación md5, debido a su seguridad y rapidez. No nos hemos adentrado a fondo a entender cómo funciona este algoritmo, por lo que la implementación de la función SHA256 que se usa en este proyecto no es propia. 

La función que usamos en el proyecto retorna el código hash a partir de un conjunto de caracteres(string). Volviendo al punto anterior (inicialización del bucle), una vez que ya tenemos el Hashcode (del string con el nonce concatenado), procedemos a realizar una evaluación del primer carácter, último carácter, carácter central, y el anterior al central. Para que el código hash sea válido, verificamos que se cumplan ciertas condiciones aritméticas con el código ASCII de estos caracteres. La cantidad de condiciones y el tipo de complejidad de estas repercuten en el tiempo de búsqueda del nonce apropiado. Si aumentamos las condiciones, y si las hacemos más "complejas”, el tiempo de búsqueda aumentará considerablemente.
Una vez encontremos el nonce apropiado, procedemos a reemplazar los primeros cuatro valores del string Hashcode con '0000', y retornamos la cadena.

```c++
//...
 string SHA256(char* data) 
{
	int strLen = strlen(data);
	SHA256_CTX ctx;
	unsigned char hash[32];
	string hashStr = "";

	SHA256Init(&ctx);
	SHA256Update(&ctx, (unsigned char*)data, strLen);
	SHA256Final(&ctx, hash);

	char s[3];
	for (int i = 0; i < 32; i++) {
		sprintf(s, "%02x", hash[i]);
		hashStr += s;
	}
	//cond
	int val = 1 + rand() % 999999;
	int a = int(hashStr[0]);
	a+=int(hashStr[hashStr.size()/2]);
	int b = int(hashStr[hashStr.size()-1]);
	b += int(hashStr[(hashStr.size()/2)-1]);
	if((a+b)>300 && (a+b)%2!=0 && (a>b) && (a*9)%7>5 && (b*7)%9>=8 && ((a*b)%9)+2 < 8 && (a/b)%2!=0 && val>4444 && val<4480) 
	{
		string hashcode = "0000";
		for(int i=4;i<hashStr.size();i++){
			hashcode+=hashStr[i];
		}
		return hashcode;
	}
	else
		return hashStr;
}
```



## Buscar  (BST).

Para realizar el método de la busqueda, nos basamos en la suma de los codigos ascci del nombre (Quien seria nuestro índice para la búsqueda)

```c++
void findAndShow(string name){
        int x = 0;
        for(auto i:name){
            x+=int(i);
        }
        int count=1;
        NodeBT<T> *its = find(this->root, x);
        if (its != nullptr){
            if (its->name == name){
               cout<<"Se encontro el Nombre..."<<endl
                   <<"Mostrando Informacion..."<<endl<<endl;
                for(auto i: its->whereToFind)
                {
                    cout<<"Data #"<<count<<':'<<endl;
                    for(auto l: (i.first->getDataBlock()[i.second]->get_data())){
                        cout<<l<<", ";
                    }
                    count++;
                    cout<<endl<<endl;
                }
            } 
            else cout<<"El nombre no se encuentra el el BlockChain"<<endl;
        }
       
        
    }
```  
>> Complejidad = O(n)


# Conclusión
En conclusión la tecnología del BLockChain tiene la posibilidad de brindar la confidencialidad de nuestros usuarios y así mismo puede brindar la seguridad de cada uno de los datos. Esta tecnología puede llegar a ser la nueva alternativa que muchos usuarios obtarian ya que puede ser usado en distintas ramas ya sea legales, sociales, financieras y entre otros. 


# Referencias  

- ¿QUÉ es y CÓMO funciona el BLOCKCHAIN? en 6 MINUTOS. TIENES QUE SABERLO ¡YA! 📖💰. (2018, 28 marzo). [Vídeo]. YouTube. Recuperado 17 de octubre de 2022, de https://www.youtube.com/watch?v=C5NZnD12yjg  

- Los Beneficios del Blockchain. (2022, 11 agosto). Campus Internacional de Blockchain. Recuperado 17 de octubre de 2022, de https://www.campusblockchain.es/los-beneficios-del-blockchain/  

- MD5 Implementation in C++ - Programming Algorithms. (2015, 11 septiembre). Recuperado 17 de octubre de 2022, de https://www.programmingalgorithms.com/algorithm/md5/cpp/  
