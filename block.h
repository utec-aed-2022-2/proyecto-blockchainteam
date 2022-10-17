#ifndef block_h
#define block_h

#include<iostream>
#include<string>
#include "transaction.h"
using namespace std;

class block{
 private:
    int index; // Posicion del bloque
    string codHash; // Codigo hash del bloquew    
    string prev; // codig hash del anterior bloque
    string generateHash();
    transaction data;

 public:    
    // Constructor
    block(int index ,transaction tscion , string  prev);           
    string getHash(){return codHash;}
    string getPrev(){return prev;}
    transaction getData(){return data;}
};

block::block(int idx ,transaction tscion , string  prev)
        : index(idx) , data(tscion) , prev(prev) , codHash(generateHash()) {}


string block::generateHash(){
    string hash = "HashPara : " +  this -> data.transmitterKey + " >> " + this -> data.receiverKey + " >> " + to_string(this -> data.mount) ;
    return hash; // modificar por nuestro propio hash
}

#endif


