#include <assert.h>

#include "Vector.h"
#include "Heap.h"
#include "Collection.h"
#include "SinglyLinkedList.h"
#include "Set.h"
#include "Map.h"

class Test{
private:
    void testVector();
    void testHeap();
    void testCollection();
    void testSLinkedList();
    void testSet();
    void testMap();

public:

    void testAll();
};