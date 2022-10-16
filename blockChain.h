#include<iostream>
#include<string>
#include "block.h"
using namespace std;

class BlockChain{
 private:
    Block createGenesisBlock(); // Primer valor del bloque
    vector<Block> listChain;

 public:

   BlockChain();
   Block get_prev_list();
   void insertBlock(Transaction data);
   void searchBlock();
   void DisplayList();
};

BlockChain::BlockChain(){
   Block genesis = createGenesisBlock();
   listChain.push_back(genesis); // agregamos el primer valor
}

Block Blockchain::createGenesisBlock(){
    time_t r_time;
    // Inicio transaccion 
    Transaction init(0, "Genesis", "Genesis", time(&r_time));    
    Block genesis(0, init, 0);
    return genesis;
}


string BlockChain:: get_prev_list(){
 return this -> listChain.back() -> get_Hash(); 
 // Obtener el último elemnto de la lista para encontrar el hash del prev
}

void BlockChain::insertBlock(Transaction data){
   int index = size(this -> listChain);
   string prev = get_prev_list();
   Block newBlock(index , data , prev);
   listChain.pushback(newBlock);
   
}

void BlockChain::searchBlock(){
   //BlockEncontrado.DisplayList
}

void BlockChain::DisplayList(){
   //Mosrar
   vector<Block> i = listChain.begin();
   for (i ; i != chain.end(); ++i){
        Block currentBlock = i;
        cout<<"\n\nBlock ===================================";
        cout<<"\nIndex: %d", currentBlock.getIndex();
        cout<<"\nAmount: %f", currentBlock.data.mount;
        cout<<"\nSenderKey: %s", currentBlock.data.transmitterKey;
        cout<<"\nReceiverKey: %s", currentBlock.data.receiverKey;
        cout<<"\nTimestamp: %ld", currentBlock.data.time;
        cout<<"\nHash: %zu", currentBlock.getHash();
    }
}

