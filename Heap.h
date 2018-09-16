#include <cstdlib>

#include <iostream>
using namespace std;

template <class T>
class Heap{
private:
    T* elems;
    int size = 2;
    int current = 1;
    void resize();
    void checkUp();
    void checkDown();
    bool relation(T el1, T el2);
public:

    Heap();
    ~Heap();

    //adds an element at the end
    void add(T elem);

    //removes the first element
    T remove();

    //void print();
};

template <class T>
Heap<T>::Heap(){
    elems = new T[size];
}

template <class T>
Heap<T>::~Heap(){
    delete[] elems;
}

template <class T>
void Heap<T>::resize(){
    size *= 2;
    T* newV;
    newV = new T[size];
    for(int i=0; i<size/2; i++){
        newV[i] = elems[i];
    }
    delete[] elems;
    elems = newV;
}

template<class T>
void Heap<T>::add(T elem){
    if(current >= size){
        resize();
    }
    elems[current++] = elem;
    checkUp();
}

template<class T>
T Heap<T>::remove(){
    T elem = elems[1];
    elems[1] = elems[current-1];
    current--;
    checkDown();
    return elem;
}

template <class T>
void Heap<T>::checkUp(){
    int i = current - 1;
    int parent = i / 2;
    T elem = elems[i];
    while(!relation(elems[parent], elem) && parent >= 1){
        elems[i] = elems[parent];
        i = parent;
        parent = i/2;
    }
    elems[i] = elem;
}

template<class T>
void Heap<T>::checkDown(){
    int pos = 1;
    int elem = elems[pos];
    int i = pos;
    int j = 2 * pos;
    while(j < current){
        if(j < current){
            if(!relation(elems[j], elems[j+1])){
                j = j+1;
            }if(elems[j]<=elem){
                j = current + 1;
            }else{
                elems[i] = elems[j];
                i = j;
                j = 2 * i; 
            }
        }
    }
    elems[i] = elem;
}

template<class T>
bool Heap<T>::relation(T el1, T el2){
    return el1 >= el2;
}
/*
template <class T>
void Heap<T>::print(){
    for(int i=1; i<current; i++){
        cout<<elems[i]<<endl;
    }
}
*/