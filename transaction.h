#ifndef transaction_h
#define transaction_h

#include<iostream>
#include<string>
using namespace std;
struct  transaction{

    float mount;
    string transmitterKey;
    string receiverKey;
    time_t time;
    // Constructores
    transaction(){};

    transaction(float mount, string send, string recib, time_t time): mount(mount), transmitterKey(send) , receiverKey(recib) , time(time){}
};

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 267435a9e6fa2fb009bb9511148f27b997a3afce
