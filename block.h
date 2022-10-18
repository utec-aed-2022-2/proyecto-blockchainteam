#ifndef BLOCK_H
#define BLOCK_H

//#include "librerias.h"
#include "sha256.h"

struct TransactionD
{
private:
    float monto;
    string emisor;
    string receptor;
    string time;
    string date;

public:
    TransactionD() = default;
    TransactionD(float _monto, string _emisor, string _receptor, string _time, string _date)
    {
        this->monto = _monto;
        this->emisor = _emisor;
        this->receptor = _receptor;
        this->time = _time;
        this->date = _date;
    }
    ~TransactionD() = default;
    // getters:
    float get_monto() { return this->monto; };
    string get_emisor() { return this->emisor; };
    string get_receptor() { return this->receptor; };
    string get_time() { return this->time; };
    string get_date() { return this->date; };
};
class Block
{
private:
    list<TransactionD*> registro; // arreglo de registros
    string prev_hashcode;
    string hashcode;
    string generateHashcode();
    int nonce; // iniciar codigo hash con 4 0's
    int index;
    int reg_capacity;

public:
    Block();
    Block(int _index, string _prev_hashcode, list<TransactionD*> reg) // testear otros tamaños
    {
        this->index = _index;
        this->registro = reg;
        this->reg_capacity = 4;
        this->prev_hashcode = _prev_hashcode;
        this->hashcode = generateHashcode();
    };
    ~Block()
    {
        for (auto &it: registro)
        {
            it->~TransactionD();
        }
        registro.~list();
    };
    string get_hash() {return this->hashcode;};
    string get_prev_hash() {return this->prev_hashcode;};
    int get_nonce() {return this->nonce;};
    void show_data();
    int get_index(){return this->index;};
};

string Block::generateHashcode() // el codigo hash depende de todos los valores del conjunto de registros, lo cual lo hace mas seguro
{
    string to_hash = "";
    for (auto &it: registro)
    {
        to_hash += to_string(it->get_monto());
        to_hash += it->get_emisor();
        to_hash += it->get_receptor();
        to_hash += it->get_date();
        to_hash += it->get_time();
    }
    
    string sha;
    clock_t t;
    t=clock();
    cout<<endl<<"Buscando Nonce para Bloque "<<this->index<<"..."<<endl;
    int count=0;
    srand(time(NULL));
    while (true)
    {
        int valor = 1000 + rand() % 9999;
        //cout <<endl<<"testing nonce " << valor << endl;
        string a = to_string(valor);
        string b = to_hash;
        a += b;
        char nuevo[a.size() + 1];
        strcpy(nuevo, a.c_str());
        sha = SHA256(nuevo);
        //cout <<"hashcode: " << sha << endl;
        string c = "";
        c += sha[0];
        c += sha[1];
        c += sha[2];
        c += sha[3];
        count+=1;
        if (c == "0000"){
            double dif = (clock()-t)/(double)CLOCKS_PER_SEC;
            cout<<"!Nonce encontrado en: "<<dif<<" segundos"<<endl
                <<"(Se probaron "<<count<<" Nounces)"<<endl;
            this->nonce = valor;
            break;
        }
    }

    return sha;
};

void Block::show_data(){
    int i=1;
    for(auto &it: registro){
        cout<<"Transaccion "<<i<<":"<<endl
            <<"\tMonto: "<<it->get_monto()<<endl
            <<"\tEnvia: "<<it->get_emisor()<<endl
            <<"\tDestinatario: "<<it->get_receptor()<<endl
            <<"\tFecha y Hora: "<<it->get_date()<<" a las "
            <<it->get_time()<<endl<<endl;
            i+=1;
    }
};

#endif