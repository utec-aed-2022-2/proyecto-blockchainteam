#include<iostream>
#include<string>
using namespace std;

class Transaction{
 public:
    float mount;
    string transmitterKey;
    string receiverKey;
    time_t time;

    Transaction(float mount, string send, string recib, time_t time): mount(mount), transmitterKey(send) , receiverKey(recib) , time(time){}
};


class Block{
 private:
    int index; // Posicion del bloque
    string codHash; // Codigo hash del bloquew    
    string prev; // codig hash del anterior bloque
    string generateHash();
    Transaction data;

 public:    
    // Constructor
    Block(int index ,Transaction tscion , string  prev);           
    string getHash();
    string getPrev();
    
    bool validateHash();
};

Block::Block(int idx ,Transaction tscion , string  prev)
        : index(idx) , data(tscion) , prev(prev) , codHash(generateHash()) {}


string Block::generateHash(){
    string hash = "HashPara : " +  this -> data.transmitterKey + " >> " + this -> data.receiverKey + " >> " + to_string(this -> data.mount) ;
    return hash; // modificar por nuestro propio hash
}

string Block::getHash(){
    return codHash;
}

string Block::getPrev(){
    return prev;
}




