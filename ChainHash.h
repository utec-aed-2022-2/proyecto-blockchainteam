#include <forward_list>
#include <functional>

using namespace std;

const float maxFillFactor = 0.6;
const int maxCollision = 3;

template<typename TK, typename TV>
class ChainHash
{
private:
    struct Entry{
        TK key;
        TV value;
        size_t hashcode;
        Entry(){}
        Entry(TK _k, TV _v, size_t h){
            key = _k;
            value = _v;
            hashcode = h;
        }
    };
    forward_list<Entry>* array; // O(n)
    int capacity;
    int size;
    hash<TK> getHash;

    bool primo(int capacidad){//como se aumenta dependiendo los primos
        for(int i = 2; i*i <= capacidad ;i++){
              if(capacidad % i == 0){
                  return false;
              }
        }
            return true;
    }

public:
    ChainHash(int _capacity = 500){
        this->capacity = _capacity;
        this->array = new forward_list<Entry>[this->capacity];
        this->size = 0;
    }
    float fillFactor(){
        return size / (capacity * maxCollision);
    }


    void rehashing(){
            //TODO
            int new_capacidad = capacity*2;
            while(!primo(new_capacidad)) {
                 new_capacidad++;//aumentar espacio
            }
            auto new_space = new forward_list<Entry>[new_capacidad];

            for(int i = 0; i < capacity ;i++){
              for(auto j:array[i]){
                size_t hashcode = getHash(j.key);
                int index = hashcode % new_capacidad;
                new_space[index].push_front(Entry(j.key,j.value,hashcode));//rellenar el nuevo
                //cambiar el entry por entry(j.key,j.value){}
              }
            }
            delete [] array;//eliminar el anterior
            this->array = new_space;//asignar al nuevo(tiene mas espacio)
            this->capacity = new_capacidad;   //nueva capadidad
    }
    bool insert(TK key, TV value){  // O(n)
        if(fillFactor() >= maxFillFactor){
            rehashing();
        }
        size_t hashcode = getHash(key);
        int index = hashcode % capacity;
        //TODO: evaluar si la llave existe
        int pos = distance(array[index].begin(),array[index].end());

        if(pos == maxCollision){
            rehashing();
        }
        for (auto &i : array[index]) { // O(n)
          if (i.key == key) {
            i.value = value;
            return false;
          }
        }
        array[index].push_front(Entry(key, value, hashcode));
        size++;
        return true;
    }

    TV get(TK key){
        size_t hashcode = getHash(key);
        int index = hashcode % capacity;
        //TODO: iterar en la lista array[index]
        for (auto &i : array[index]) {
            if (i.key == key) {
              return i.value;//valor entrado
            }
        }
        return TV{};//valor no encontrado

    }



    void remove(TK key){
        //TODO
        if(capacity>0){
            size_t hashcode = getHash(key);
            int pos = hashcode % capacity;
            array[pos].remove_if([key](const Entry& j){return j.key ==key;});
            //si se remueve es un true, en caso de no estar da false(no hace nada)
        }

    }


    int bucket_count(){
        return capacity;
    }

    int bucket_size(int i_bucket){
        return std::distance(array[i_bucket].begin(), array[i_bucket].end());
    }

    typename forward_list<Entry>::iterator begin(int i_bucket){
        return array[i_bucket].begin();
    }

    typename forward_list<Entry>::iterator end(int i_bucket){
        return array[i_bucket].end();
    }

    ~ChainHash(){
        //TODO: liberar cada lista
        delete[] this->array;
    }
};