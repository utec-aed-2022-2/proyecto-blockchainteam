#include "blockchain.h"
#include<chrono>

int menu(BlockChain & cadena);
void test(BlockChain & cadena);
void insert_data(BlockChain & cadena);

int main()
{
    BlockChain cadena = BlockChain();
    int i;
    while (i!=4){
        i = menu(cadena);
    };  
    return 0;
};

int menu(BlockChain &cadena)
{
    int var = 0;
    cout <<endl<<"\t\t\tGENERADOR DE BLOCKCHAIN" << endl
         << endl
         << "1. Generar bloques aleatorios" << endl
         << "2. Insertar transacciones (4 por bloque)" << endl
         << "3. buscar bloque" << endl
         << "4. salir"<<endl;
    do
    {
        cout << "Ingrese Opcion: ";
        cin >> var;
    } while (var != 1 && var != 2 && var != 3 && var != 4);

    if (var == 1){
        cout<<endl<<"\t\t\tGENERANDO BLOQUES ALEATORIOS..."<<endl;
        test(cadena);
    }
    else if (var == 2)
    {
        int v = 0;
        do
        {
            cout << "Cuantas Transacciones ingresara? (multiplo de 4, minimo 4): ";
            cin >> v;
        } while (v <= 0 || v%4!=0);
        for (int i = 0; i < v; i++)
        {
            insert_data(cadena);
        }
    }
    else if(var == 3){
        string c;
        cout<<endl<<"ingrese hashcode: ";cin>>c;
        cadena.find(c);
    }
    else return 4;
};

void insert_data(BlockChain &cadena)
{   
    list<TransactionD *> reg;
    float m;
    string e;
    string r;
    string t;
    string f;
    for (int i = 0; i < 4; i++)
    {
        cout <<endl<<"Transaccion " << i + 1 << ": " << endl;
        cout << "Ingrese monto: "; cin>>m;
        cout << "Persona que envia(solo Nombre): "; cin>>e;
        cout << "Destinatario(Solo Nombre): "; cin>>r;
        char y;
        do{
            cout<<"Desea ingresar fecha y hora automaticamente? (s/n): "; cin>>y;
        }while(y!='s' && y!='n' && y!='S' && y!='N');
        if (y=='n' || y == 'N'){
            cout << "Ingrese Hora: "; cin>>t;
            cout << "Ingrese Fecha: "; cin>>f;
            }
        else{
            time_t ti = std::time(nullptr);
            tm* now = std::localtime(&ti);
            f = to_string(now->tm_mday); f+= '/';
            f += to_string(now->tm_mon + 1); f+= '/';
            f += to_string(now->tm_year-100);

            auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
            t = to_string(now->tm_hour); t+= ':';
            t += to_string(now->tm_min);
            cout<<"Fecha actual: "<<f<<endl;
            cout<<"Hora actual: "<<t<<endl;
        }
        TransactionD *reg1 = new TransactionD(m, e, r, t, f);
        reg.push_back(reg1);
    }
    cadena.insert_block(reg);
};

void test(BlockChain & cadena)
{
    // transacciones
    list<TransactionD *> reg;
    TransactionD *reg1 = new TransactionD(5000, "Pepe", "Pepa", "11:53", "Aug 25, 2022");
    TransactionD *reg2 = new TransactionD(35, "Piero", "Carla", "10:31", "Sep 11, 2001");
    TransactionD *reg3 = new TransactionD(559, "Daniela", "Carla", "13:24", "Jan 19, 2022");
    TransactionD *reg4 = new TransactionD(789, "Andrea", "Sofia", "15:06", "Apr 29, 2022");

    reg = {reg1, reg2, reg3, reg4};
    cadena.insert_block(reg);

    reg1 = new TransactionD(500, "Sara", "Pepa", "16:48", "Oct 23, 2022");
    reg2 = new TransactionD(4578, "Tamara", "Esteban", "12:50", "Apr 16, 2022");
    reg3 = new TransactionD(234.6, "Wilson", "Gabriela", "18:20", "Aug 5, 2022");
    reg4 = new TransactionD(333.3, "Victor", "Katia", "11:28", "Feb 18, 2022");

    reg = {reg1, reg2, reg3, reg4};
    cadena.insert_block(reg);

    reg1 = new TransactionD(56.36, "Victor", "Sara", "9:37", "Jun 5, 2022");
    reg2 = new TransactionD(1000000.63, "Carlos", "Piero", "12:50", "Jun 23, 2022");
    reg3 = new TransactionD(5548, "Esteban", "Pepa", "1:03", "Nov 30, 2022");
    reg4 = new TransactionD(325.20, "Mario", "Pepe", "19:23", "Dec 31, 2022");

    reg = {reg1, reg2, reg3, reg4};
    cadena.insert_block(reg);

    reg1 = new TransactionD(345346.35, "Carla", "Tamara", "7:59", "Mar 25, 2022");
    reg2 = new TransactionD(25978, "Daniela", "Wilson", "6:12", "Apr 5, 2022");
    reg3 = new TransactionD(97245.20, "Gabriela", "Andrea", "8:33", "May 7, 2022");
    reg4 = new TransactionD(1.50, "Esteban", "Sara", "9:50", "Jul 9, 2022");

    reg = {reg1, reg2, reg3, reg4};
    cadena.insert_block(reg);
}