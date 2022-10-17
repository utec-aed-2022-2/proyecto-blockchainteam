#include<iostream>
#include<string>
#include <random>
using namespace std;


std::string random_string(std::string::size_type length)
{
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while(length--)
        s += chrs[pick(rg)];

    return s;
}

class Transaction{
 private:
    float cantidadSoles; // O(1)
    string idTransmisor; 
    string idReceptor;
    time_t tiempo; // O(1)
 public:
    Transaction(float mount, string send, string recib, time_t time): 
    cantidadSoles(mount), idTransmisor(send) , idReceptor(recib) , tiempo(time){} // O(1)
    
    float getCantidadSoles() {return cantidadSoles;} // O(1)
    string getIdTransmisor() {return idTransmisor;} // O(1)
    string getidReceptor() {return idReceptor;} // O(1)

};


class Block{ // O(1)
   private:
   string hash;
   string prevHash;
   string nounce;
   Transaction* data;
   public:
   Block(Transaction* tx, string  prev): data(tx), prevHash(prev){} // O(1)
   
   string setHashCentinel() {
      hash = "0000Centinel";
      return hash;
   }
   string generateHash() {
      hash = random_string(20);
      // cout << hash << endl;
      return hash;
   }

   void printBlock(){
      cout << "Block: " << hash << endl;
      cout << "Prev: " << prevHash << endl;
      if(data != nullptr){
      cout << "Monto: " << data->getCantidadSoles() << endl;
      cout << "idTranmisor: " << data->getIdTransmisor() << endl;
      cout << "idReceptor: " << data->getidReceptor() << endl;
      }
      else{
         cout << "Este bloque no cuenta con informacion." << endl;
      }
   }
   Transaction* get_Data(){return data;}
   string getHash() {return hash;}
   string getPrevHash(){return prevHash;}
   };

