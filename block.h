#include<iostream>
#include<string>
using namespace std;

class Transaction{
 public:
    float mount;
    string transmitterKey;
    string receiverKey;
};


class Block{
 private:
    int index;
    string generateHash(); // Transacciones
    string codHash; // Codigo hash del bloque
    string prev; // codig hash del anterior bloque

 public:    
    // Constructor
    Block(int index ,Transaction tscion , string  prev);
    
    string getHash(){}
    string getPrev(){}
    
    Transaction data;
    bool validateHash(){}
};

Block::Block(int index ,Transaction tscion , string  prev){
    this -> index = index;
    this -> data = tscion;
    this -> prev = prev;
    this -> codHash = generateHash();
}

string Block::generateHash(){
    return "CodigoHashGenerado";
}

string Block::getHash(){
    return codHash;
}

string Block::getPrev(){
    return codHash;
}

string Block::validateHash(){
    if (codHash) return true;
}


