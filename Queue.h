#include <cstdlib>

template <class T>
class Queue{
    private:
        int Front = 0;
        int Back = 0;
        int size = 2;
        int length = 0;
        T* queue;

        void resize();
        void ShiftLeft();
    public:
        Queue();
        ~Queue();

        bool empty();
        int Length();
        T front();
        T back();
        void push(T other);
        T pop();
};

template <class T>
Queue<T>::Queue(){
    queue = new T[size];
}

template <class T>
Queue<T>::~Queue(){
    delete[] queue;
}

template <class T>
bool Queue<T>::empty(){
    return length == 0?true:false;
}

template <class T>
int Queue<T>::Length(){
    return length;
}

template <class T>
T Queue<T>::front(){
    return queue[Front];
}

template <class T>
T Queue<T>::back(){
    return queue[Back-1];
}

template <class T>
void Queue<T>::push(T other){
    if(Back < size){
        queue[Back++] = other;
        length ++;
    }else if(length < size / 2){
        ShiftLeft();
        push(other);
    }else{
        resize();
        push(other);
    }
}

template <class T>
void Queue<T>::resize(){
    size *= 2;
    T* nV = new T[size];
    for(int i = Front; i<Back; i++){
        nV[i] = queue[i];
    }
    delete[] queue;
    queue = nV;
}

template <class T>
void Queue<T>::ShiftLeft(){
    int j = 0;
    for(int i=Front; i<Back; i++){
        queue[j] = queue[i];
    }
    Front = 0;
    Back = length;
}

template <class T>
T Queue<T>::pop(){
    if(Front != Back){
        length --;
        return queue[Front++];
    }else{
        throw "void";
    }
}