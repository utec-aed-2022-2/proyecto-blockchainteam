#ifndef blockChain_h
#define blockChain_h

#include<iostream>
#include<string>
#include<vector>
#include "block.h"
using namespace std;

class blockChain{
 private:
    block createGenesisBlock(); // Primer valor del bloque
    vector<block> listChain;

 public:
   blockChain();

   block *get_hash_prev_list();
   void insertBlock(transaction data);
   //void searchBlock();
   void DisplayList();
};

blockChain::blockChain(){
   block genesis = createGenesisBlock();
   listChain.push_back(genesis); // agregamos el primer valor
}

block blockChain::createGenesisBlock(){
    time_t tiempo;
    // Inicio transaccion 
    transaction init(0, "Genesis", "Genesis", time(&tiempo));    
    block genesis(0, init, " ");
    return genesis;
}


string blockChain:: *get_hash_prev_list(){
 return  listChain.back(). get_Hash(); 
 // Obtener el último elemnto de la lista para encontrar el hash del prev
}

void blockChain::insertBlock(transaction data){
   // Verificar que ninguno de los bloques haya sido modificado

   int index = size(this -> listChain);
   string prev = get_prev_list(); // Verifica solo el anterior, necesitamos que verifique todas
   block newBlock(index , data , prev);
   listChain.push_back(newBlock);
   
}

//void blockChain::searchBlock(){
   //BlockEncontrado.DisplayList
//}

void blockChain::DisplayList(){
   //Mosrar
  // vector<block> i = listChain.begin();
  // for (i ; i != chain.end(); ++i){
  //      block currentBlock = i;
  //      cout<<"\n\nBlock ===================================";
  // //     cout<<"\nAmount: ", currentBlock.getData().mount;//
   //     cout<<"\nSenderKey: ", currentBlock.getData().transmitterKey;
   //     cout<<"\nReceiverKey: ", currentBlock.getData().receiverKey;
   //     cout<<"\nTimestamp: ", currentBlock.getData().time;
   //     cout<<"\nHash: ", currentBlock.getHash();
//    }
   cout << "pipip";
}

#endif
