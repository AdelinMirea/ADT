#include "Test.h"
#include <iostream>
using namespace std;


void Test::testAll(){
    testVector();
    testHeap();
    testCollection();
    testSLinkedList();
}

void Test::testVector(){
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    assert(v[0] == 1);
    assert(v.size() == 5);

    v.removeEnd();

    assert(v.size() == 4);

    v.removeAt(0);

    assert(v.size() == 3);
    assert(v.get_element(0) == 2);
    assert(v.find(2) == 0);
    try{
        assert(v.find(15) == -1);
    }catch(...){
        assert(true);
    }
    assert(v.front() == 2);
    assert(v.back() == v[v.size()-1]);
}

void Test::testHeap(){
    Heap<int> h;

    h.add(1);
    h.add(2);
    h.add(3);
    h.add(4);
    h.add(5);
    //h.print();

    int t = h.remove();
    assert(t == 5);
    //h.print();
}

void Test::testCollection(){
    Collection<int> c;
    c.add(1);
    c.add(2);
    c.add(3);
    c.add(1);
    c.add(4);
    c.add(1);
    assert(c.dim() == 6);

    assert(c.find(1) == true);

    c.remove(1);
    assert(c.dim() == 5);
    assert(c.voidCollection() == false);
}

void Test::testSLinkedList(){
    LinkedList<int> l;
    
    l.add(1);
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    l.add(6);
    l.first();
   
    assert(l.find(5) == true);
    assert(l.find(6) == true);
    assert(l.Lenght() == 6);
    
}