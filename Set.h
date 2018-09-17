#include <cstdlib>

template <class T>
class Set{
    private:
        T* elements;
        int dimension = 5;
        int size = 0;
        void resize();
    public:
        Set();
        ~Set();
        void add(T other);
        void remove(T other);
        bool find(T other);
        int Length();
        bool Void();
        T operator[](int pos);
};

template <class T>
Set<T>::Set(){
    elements = new T[dimension];
}

template <class T>
Set<T>::~Set(){
    delete[] elements;
}

template <class T>
void Set<T>::add(T other){
    if(!find(other)){
        elements[size++] = other;
    }else{
        throw "already exists";
    }
}

template <class T>
void Set<T>::remove(T other){
    for(int i=0; i<size; i++){
        if(elements[i] == other){
            for(int j = i; j<size-1; j++){
                elements[j] = elements[j+1];
            }
            return;
        }
    }
    throw "non existent";
}

template <class T>
bool Set<T>::find(T other){
    for(int i=0; i<size; i++){
        if(elements[i] == other){
            return true;
        }
    }
    return false;
}

template <class T>
int Set<T>::Length(){
    return size;
}

template <class T>
void Set<T>::resize(){
    dimension *= 2;
    T* newV = new T[dimension];
    for(int i=0; i<size; i++){
        newV[i] = elements[i];
    }
    delete[] elements;
    elements = newV;
}

template <class T>
T Set<T>::operator[](int pos){
    if(pos < size){
        return elements[pos];
    }else{
        throw "out of range";
    }
}