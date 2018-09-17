#include <cstdlib>

template <class T>
class Collection{

private:
    T* elems;
    int size = 5;
    int current = 0;
    void resize();

public:
    Collection();
    ~Collection();

    void add(T elem);
    void remove(T elem);
    bool find(T elem);
    int dim();
    bool voidCollection();

};

template <class T>
Collection<T>::Collection(){
    elems = new T[size];
}

template <class T>
Collection<T>::~Collection(){
    delete[] elems;
}

template <class T>
void Collection<T>::resize(){
    T* others = new T[size*2];
    size *= 2;
    for(int i=0; i<current; i++){
        others[i] = elems[i];
    }
    delete[] elems;
    elems = others;
}

template <class T>
void Collection<T>::add(T elem){
    if(current + 1 >= size){
        resize();
    }
    elems[current++] = elem;
}

template <class T>
void Collection<T>::remove(T elem){
    bool removed = false;
    for(int i=0; i<current; i++){
        if(elems[i] == elem){
            for(int j = i; j<current-1; j++){
                elems[j] = elems[j+1];
            }
            current --;
            removed = true;
            break;
        }
    }
    if(!removed){
        throw "none";
    }
}

template <class T>
bool Collection<T>::find(T other){
    for(int i=0; i<current; i++){
        if(elems[i] == other){
            return true;
        }
    }
    return false;
}

template <class T>
int Collection<T>::dim(){
    return current;
}

template<class T>
bool Collection<T>::voidCollection(){
    if(current == 0){
        return true;
    }else{
        return false;
    }
}