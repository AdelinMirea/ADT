#include <cstdlib>
#include "PriorityPair.h"

template <class T>
class PriorityQueue{
    private:
        int Front = 0;
        int Back = 0;
        int size = 2;
        int length = 0;
        PriorityPair<T>* queue;

        void resize();
        void ShiftLeft();
    public:
        PriorityQueue();
        ~PriorityQueue();

        bool empty();
        int Length();
        T front();
        T back();
        void push(PriorityPair<T> ot);
        T pop();
};

template <class T>
PriorityQueue<T>::PriorityQueue(){
    queue = new PriorityPair<T>[size];
}

template <class T>
PriorityQueue<T>::~PriorityQueue(){
    delete[] queue;
}

template <class T>
bool PriorityQueue<T>::empty(){
    return length == 0?true:false;
}

template <class T>
int PriorityQueue<T>::Length(){
    return length;
}

template <class T>
T PriorityQueue<T>::front(){
    return queue[Front].getValue();
}

template <class T>
T PriorityQueue<T>::back(){
    return queue[Back-1].getValue();
}

template <class T>
void PriorityQueue<T>::push(PriorityPair<T> other){
    if(Back < size){
        if(length == 0){
            queue[Back++] = other;
            length++;
        }else{
            for(int i=Front; i<Back; i++){
                if(other.getPriority() > queue[i].getPriority()){
                    for(int j = Back-1; j >= i; j--){
                        queue[j+1] =queue[j]; 
                    }
                    queue[i] = other;
                    Back++;
                    length++;
                    break;
                }
            }
        }
    }else if(length < size / 2){
        ShiftLeft();
        push(other);
    }else{
        resize();
        push(other);
    }
}

template <class T>
void PriorityQueue<T>::resize(){
    size *= 2;
    PriorityPair<T>* nV = new PriorityPair<T>[size];
    for(int i = Front; i<Back; i++){
        nV[i] = queue[i];
    }
    delete[] queue;
    queue = nV;
}

template <class T>
void PriorityQueue<T>::ShiftLeft(){
    int j = 0;
    for(int i=Front; i<Back; i++){
        queue[j] = queue[i];
    }
    Front = 0;
    Back = length;
}

template <class T>
T PriorityQueue<T>::pop(){
    if(Front != Back){
        length --;
        return queue[Front++].getValue();
    }else{
        throw "void";
    }
}