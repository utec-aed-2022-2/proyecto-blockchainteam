#include<iostream>
#include<string>
#include "block.h"
using namespace std;

class BlockChain{
 private:
    Block createBlock();
 public:
    vector<Block> listChain;

    BlockChain();

// Functions
    void addBlock(Transaction data){}

    void ValidBlockChain(){}
   
};

BlockChain::BlockChain(){
   Block valor = createBlock();
   listChain.push_back(valor);
}

Block BlockChain::createBlock(){
   
}