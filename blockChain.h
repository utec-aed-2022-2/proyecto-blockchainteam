#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "bst_m.h"
#include "block.h"

using namespace std;
class BlockChain
{
private:
    forward_list<Block *> chain; // <hashcode, bloque>
    int n_elements;              // number of elements;
    BSTree<int> searchTree;

public:
    BlockChain() { this->n_elements = 0; };
    ~BlockChain() {
        searchTree.~BSTree();
        chain.~forward_list();
        delete this;
    };
    int size();
    bool is_empty();
    // bool find(); //falta implementar
    void insert_block(vector<DataD *> reg);
    void find(string hashcode);
    void modifyDataOfBlock();
    void addNamesToTree();
    void findByName(string name);
};
void BlockChain::insert_block(vector<DataD *> reg)
{
    int index = n_elements + 1;
    string *cod = nullptr;
    if (n_elements == 0)
    {
        cod = nullptr;
    }
    else
    {
        cod = &(chain.front()->get_hash());
    };
    Block *newBlock = new Block(reg, n_elements + 1);
    // newBlock->prev = chain.front();//apunta al anterior
    newBlock->setPrevHashcode(cod);
    chain.push_front(newBlock);
    addNamesToTree();
    // aqui ya tengo la data en el blockchain, ahora tengo que buscar nombres y setearlos al arbol
    this->n_elements++;

    cout << "######################################################################################" << endl
         << endl
         << "\t\t\t\tBLOQUE NRO: " << index << endl
         << endl
         << "NONCE: " << newBlock->get_nonce() << endl
         << "NRO TRANSACCIONES:  " << 4 << endl
         << endl;
    newBlock->show_data();
    string ph;
    if (newBlock->get_prev_hash() == nullptr)
        ph = '0';
    else
        ph = *(newBlock->get_prev_hash());
    cout << "CODIGO HASH PREVIO: " << ph << endl
         << "CODIGO HASH: " << newBlock->get_hash() << endl
         << endl
         << "######################################################################################" << endl
         << endl;
};

void BlockChain::find(string hashcode)
{
    /*
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
    */
}

int BlockChain::size()
{
    return this->n_elements;
}

bool BlockChain::is_empty()
{
    return this->n_elements == 0;
}

void BlockChain::modifyDataOfBlock() // for secure test
{
}

void BlockChain::findByName(string name){
    searchTree.findAndShow(name);
}

void BlockChain::addNamesToTree()
{
    string name;
    int j=0;
    for (auto &it : chain.front()->getDataBlock())
    {
        
        for (auto i : it->get_data())
        {
            for (auto k : i)
            {
                if (!((int(k) > 64 && int(k) < 90) || (int(k) > 96 && int(k) < 123)))
                    break;
                if (k == i.back())
                {
                    // encontre un nombre
                    searchTree.insert(i, chain.front(), j);
                    break;
                }
            }
        }
        j++;
    }
}

#endif