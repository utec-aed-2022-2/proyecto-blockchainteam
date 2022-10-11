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

    void addBlock(Transaction data){}

    void ValidBlockChain(){}

};

