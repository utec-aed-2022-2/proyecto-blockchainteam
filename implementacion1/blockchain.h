#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"


using namespace std;
class BlockChain{
    private:
        forward_list<Block*> chain; // <hashcode, bloque>
        int n_elements; //number of elements;
    public:
        BlockChain(){this->n_elements= 0;};
        ~BlockChain() = default;
        int size();
        bool is_empty();
        //bool find(); //falta implementar
        void insert_block(list<TransactionD*> reg);
        void find(string hashcode);
};
void BlockChain::insert_block(list<TransactionD*> reg)
{   
    int index = n_elements+1; 
    string cod;
    if(n_elements == 0){
        cod = "0";
    }
    else{
        cod = chain.front()->get_hash();
    };
    Block * newBlock = new Block(index, cod, reg);
    chain.push_front(newBlock);
    this->n_elements++;
    
    cout<<"######################################################################################"<<endl
        <<endl<<"\t\t\t\tBLOQUE NRO: "<<index<<endl<<endl
        <<"NONCE: "<<newBlock->get_nonce()<<endl
        <<"NRO TRANSACCIONES:  "<<4<<endl<<endl; 
        newBlock->show_data();
        cout<<"CODIGO HASH PREVIO: "<<newBlock->get_prev_hash()<<endl
        <<"CODIGO HASH: "<<newBlock->get_hash()<<endl<<endl
        <<"######################################################################################"<<endl<<endl;
        
};

void BlockChain::find(string hashcode){
    for(auto &it: chain){
        if(it->get_hash()==hashcode){
            cout<<endl<<"Se encontro el bloque..."<<endl;
            cout<<"######################################################################################"<<endl
            <<endl<<"\t\t\t\tBLOQUE NRO: "<<it->get_index()<<endl<<endl
            <<"NONCE: "<<it->get_nonce()<<endl
            <<"NRO TRANSACCIONES:  "<<4<<endl<<endl; 
            it->show_data();
            cout<<"CODIGO HASH PREVIO: "<<it->get_prev_hash()<<endl
            <<"CODIGO HASH: "<<it->get_hash()<<endl<<endl
            <<"######################################################################################"<<endl<<endl;
            return;
        } 
    }
    cout<<"No se encontro el bloque...\n";
}

int BlockChain::size(){
    return this->n_elements;
}

bool BlockChain::is_empty(){
    return this->n_elements == 0;
}

#endif