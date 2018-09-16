#include "Test.h"

void Test::testAll(){
    testVector();
    testHeap();
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