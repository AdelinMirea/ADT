#include <cstdlib>

template <class T>
class Stack{
    private:

    T* stack;
    int size = 5;
    int current = 0;

    void resize();

    public:

    Stack();
    ~Stack();

    void push(T elem);
    T pop();
    T top();
    bool empty();
    int Length();
};

template <class T>
Stack<T>::Stack(){
    stack = new T[size];
}

template <class T>
Stack<T>::~Stack(){
    delete[] stack;
}

template <class T>
void Stack<T>::resize(){
    size *= 2;
    T* newV;
    newV = new T[size];
    for(int i=0; i<current; i++){
        newV[i] = stack[i];
    }
    delete[] stack;
    stack = newV;
}

template <class T>
void Stack<T>::push(T elem){
    stack[current++] = elem;
}

template <class T>
T Stack<T>::pop(){
    current --;
    return stack[current];
}

template <class T>
T Stack<T>::top(){
    return stack[current-1];
}

template <class T>
bool Stack<T>::empty(){
    return current==0?true:false;
}

template <class T>
int Stack<T>::Length(){
    return current;
}