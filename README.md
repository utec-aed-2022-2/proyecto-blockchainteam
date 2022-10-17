[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8855166&assignment_repo_type=AssignmentRepo)


# Introducción  
El proyecto planteado consiste en la creación una aplicación de transferencias. La aplicación tiene por nombre **Transfierete** , el objetivo es poder realizar transacciones de dinero desde un usuario a otro de manera segura, como una alternativa segura para los usarios.  

Como ya mencionado antes, el proyecto brindará la seguridad en los siguientes datos:  

- La identidad e información de los usuarios  
- Los montos que transfiere y recibe 


# Descripción  
Para el realce del proyecto, se hace uso de la tecnología basada en BlockChain. Esta misma consiste en la creación de bloques enlazados, y cada bloque tendrá la información necesaria para que las transacciones se realicen de manera segura, evitando así que la información sea modificada u obtenida por otros usuarios.

# Importancia  
El manejo de BlockChain a travez de bloques es sumamente importante debido a que es:

 - **No modificable**: Cada bloque depende del código encriptado del anterior, para así cuando se intente modificar algún bloque, primero se tendría que validar el anterior y así sucesivamente.
 
 - **No renocible**: La información de los usuarios que realizan la transacción permanecerá oculta a través de un código encriptado. Así cuidar la integridad de nuestros usuarios.

 - **Nueva tecnología**: La importancia aquí es que, el BlockChain puede adaptarse a nuevas tecnologias y actualemnte se considera una de las mas confiables y seguras para el transporte de información.  

# Organización  
[Link de tareas asignadas](https://github.com/users/wanly13/projects/2/views/1)

# Estructuras  

![](estructura.JPG)

# Complejidad Big O  

## Insertar (BLockChain)
```
string addBlock(Transaction* _data){  
    Block* block =  new Block(_data,LastHashId); // O(1)
    LastHashId = block->generateHash(); O(n)
    Structure.insert(block->getHash(), block);  O(n)
    return block->getHash(); O(1)
   }

>> Complejidad = O(n)
```

## Buscar  
```
Block* getBlockByHash(string hash) //O(K)
   {
      Block* block = Structure.get(hash);
      // cout << block->   ();
            // cout << block->get_Data()->getCantidadSoles();
      return block;
      // cout << block->data << endl;
   }
   
```  

# Comparación (Con índices | Sin índices)  


# Conclusiones  
En conclusión la tecnología del BLockChain tiene la posibilidad de brindar la confidencialidad de nuestros usuarios y así mismo puede brindar la seguridad de cada uno de los datos. Esta tecnología puede llegar a ser la nueva alternativa que muchos usuarios obtarian ya que puede ser usado en distintas ramas ya sea legales, sociales, financieras y entre otros. 


# Referencias  

- ¿QUÉ es y CÓMO funciona el BLOCKCHAIN? en 6 MINUTOS. TIENES QUE SABERLO ¡YA! 📖💰. (2018, 28 marzo). [Vídeo]. YouTube. Recuperado 17 de octubre de 2022, de https://www.youtube.com/watch?v=C5NZnD12yjg  

- Los Beneficios del Blockchain. (2022, 11 agosto). Campus Internacional de Blockchain. Recuperado 17 de octubre de 2022, de https://www.campusblockchain.es/los-beneficios-del-blockchain/  

- MD5 Implementation in C++ - Programming Algorithms. (2015, 11 septiembre). Recuperado 17 de octubre de 2022, de https://www.programmingalgorithms.com/algorithm/md5/cpp/  
