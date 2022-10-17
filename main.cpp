#include<iostream>
using namespace std;

#include "block.h"
#include "blockChain.h"

void prueba(){
    blockChain listBlock;

    time_t time1;
    transaction data1(1.5,"Wanly","Renzo",time(&time1));
    listBlock.insertBlock(data1);

    time_t time2;
    transaction data2(0.2,"Jean","Luis",time(&time2));
    listBlock.insertBlock(data2);

    listBlock.DisplayList();
}

int main(){
    //prueba();
    cout<<"hola mundo";
}


/*
cada bloque es identificable por un hash
(Crear bloque)
    - Debe tener un prev
    

BlockChain -> lista de bloques
(Crear estructura BlockChain)

(Crear algoritmo hash)
    - Para generar codigo identificable 
    - Para verificar la integridad de un blque


*/
