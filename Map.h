#include <cstdlib>
#include "MapPair.h"

template <class T>
class Map{
    private:
        Pair<T>* elems;
        int size = 5;
        int current = 0;
        void resize();
        
    public:
        Map();
        ~Map();

        void add(Pair<T> other);
        void add(int key, T value);

        int find(Pair<T> other);

        int find(int key);

        void remove(Pair<T> other);
        void remove(int key);

        int Length();

        bool Void();

        //Keys, Values, Pairs?

        T element(int key);
};

template <class T>
Map<T>::Map(){
    elems = new Pair<T>[size];
}

template <class T>
Map<T>::~Map(){
    delete[] elems;
}

template <class T>
void Map<T>::resize(){
    size*= 2;
    Pair<T>* nVect;
    nVect = new Pair<T>[size];

    for(int i=0; i<current; i++){
        nVect[i] = elems[i];
    }
    delete[] elems;
    elems = nVect;
}

template <class T>
void Map<T>::add(Pair<T> other){
    if(find(other.getKey()) == -1){
        elems[current++] = other;
    }
}

template <class T>
void Map<T>::add(int key, T value){
    if(find(key) == -1){
        elems[current++] = new Pair<T>(key, value);
    }
}

template <class T>
int Map<T>::find(Pair<T> other){
    return find(other.getKey());
}

template <class T>
int Map<T>::Length(){
    return current;
}

template <class T>
bool Map<T>::Void(){
    if(current != 0){
        return false;
    }else{
        return true;
    }
}

template <class T>
void Map<T>::remove(Pair<T> other){
    remove(other.getKey());
}

template <class T>
void Map<T>::remove(int key){
    int pos = find(key);
    for(int i = pos; i< current - 1; i++){
        elems[i] = elems[i+1];
    }
    current--;
}

template <class T>
T Map<T>::element(int key){
    int pos = find(key);
    if(pos != -1){
        return elems[pos].getValue();
    }
}

template <class T>
int Map<T>::find(int key){
    for(int i=0; i<current; i++){
        if(elems[i].getKey() == key){
            return i;
        }
    }
    return -1;
}
