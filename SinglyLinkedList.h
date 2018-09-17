#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class Node{
public:
    Node* next;
    T data;

    Node(T data, Node<T>* next);
    Node();
};

template <class T>
Node<T>::Node(T Data, Node<T>* Next){
    data = Data;
    next = Next;
}

template <class T>
Node<T>::Node(){
    next = nullptr;
}

template <class T>
class LinkedList{
private:
    Node<T>* head = nullptr;
    Node<T> it;
    int size = 0;
public:

    LinkedList();
    ~LinkedList();

    void first();
    T elem();
    void next();


    void add(T elem);
    void remove(T elem);
    bool find(T elem);
    int Lenght();

};

template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
}

template <class T>      
LinkedList<T>::~LinkedList(){
    while(head!=nullptr){
        Node<T>* p = head;
        head = head->next;
        delete p;
    }
}

template <class T>
void LinkedList<T>::add(T elem){
    Node<T>* p = new Node<T>(elem, nullptr);
    p->next = head;
    head = p;
    size++;
}

template <class T>
void LinkedList<T>::remove(T elem){
    //TODO
}

template <class T>
bool LinkedList<T>::find(T elem){
    Node<T> it;
    it = *head;
    while(it.next != nullptr){
        if(it.data == elem){
            return true;
        }
        it = *it.next;
    }
    return false;
}

template <class T>
int LinkedList<T>::Lenght(){
    return size;
}

template <class T>
void LinkedList<T>::first(){
    it = *head;
}

template <class T>
T LinkedList<T>::elem(){
    if(size != 0){
        return it.data;
    }
}

template <class T>
void LinkedList<T>::next(){
    if(it.next != nullptr){
        it = *it.next;
    }
}