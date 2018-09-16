#include <cstdlib>

template <class T>
class Vector
{
private:
    T* elems;
    int CurrentSize = 2;
    int howMany=0;

    void resize();
    void getAll();
    
public:
    Vector<T>();
    ~Vector<T>();

    void push_back(T elem);
    void removeAt(int pos);
    void removeEnd();
    T find(T elem);
    T operator[](int pos);
    T get_element(int pos);
    


    int size();
    
    T at(int pos);
    
    T front();
    T back();
    void pop_back();
};
template <class T>
Vector<T>::Vector()
{
    elems = new T[CurrentSize];
}

template <class T>
Vector<T>::~Vector()
{
    delete[] elems;
}

template <class T>
T Vector<T>::front(){
    return elems[0];
}

template <class T>
void Vector<T>::removeEnd(){
    howMany--;
}

template <class T>
void Vector<T>::removeAt(int pos){
    for(int i = pos; i<howMany-1; i++){
        elems[i] = elems[i+1];
    }
    howMany--;
}

template <class T>
T Vector<T>::back(){
    return elems[howMany - 1];
}


template <class T>
T Vector<T>::at(int pos){
    return elems[pos];
}

template <class T>
T Vector<T>::operator[](int pos){
    return elems[pos];
}

template <class T>
void Vector<T>::push_back(T elem){
    if(CurrentSize < howMany){
        elems[howMany++] = elem;
    }else{
        resize();
        elems[howMany++] = elem;
    }
}

template <class T>
void Vector<T>::resize(){
    CurrentSize *= 2;
    T* newV;
    newV = new T[CurrentSize];
    for(int i=0; i<CurrentSize/2; i++){
        newV[i] = elems[i];
    }
    delete[] elems;
    elems = newV;
}

template <class T>
T Vector<T>::find(T elem){
    for(int i=0; i<howMany; i++){
        if(elem == elems[i]){
            return i;
        }
    }
    throw "none";
}

template <class T>
T Vector<T>::get_element(int pos){
    if(pos<CurrentSize){
        return elems[pos];
    }else{
        throw "none";
    }
}

template <class T>
int Vector<T>::size(){
    return howMany;
}