#include "lists/LinkedList.cpp"
#include "lists/SingleLinkedList.cpp"
#include "lists/LoopLinkedList.cpp"

#define DEFAULT_SIZE_ARRAY 3

using namespace std;

SomeStruct *data;

void initTestArray() {
    data = new SomeStruct[DEFAULT_SIZE_ARRAY];
    cout << "--------------TEST DATA--------------\n";
    for (int i = 0; i < DEFAULT_SIZE_ARRAY; ++i) {
        initSomeStruct(data[i]);
    }
    cout << "--------------TEST DATA--------------\n";
}

void printSomeStruct(SomeStruct s) {
    outDoubleArray(&s);
    outOtherString(s);
    cout << endl;
}

void testLoopLinkedList() {
    cout << "\n--------------TEST LoopLinkedList--------------\n";
    auto *loopLinkedList = new LoopLinkedList;
    for (int i = 0; i < DEFAULT_SIZE_ARRAY; ++i) {
        loopLinkedList->push(data[i]);
    }

    auto *itr = loopLinkedList->getIterator();

    cout << "Going on LoopLinkedList to forward twice\n";
    for (int j = 0; j < DEFAULT_SIZE_ARRAY * 2; ++j) {
        printSomeStruct(itr->next());
    }

    delete itr;
    delete loopLinkedList;
    cout << "--------------TEST LoopLinkedList--------------\n";
}

void testSingleLinkedList() {
    cout << "\n--------------TEST SingleLinkedList--------------\n";
    auto *singleLinkedList = new SingleLinkedList;
    for (int i = 0; i < DEFAULT_SIZE_ARRAY; ++i) {
        singleLinkedList->push(data[i]);
    }

    auto *itr = singleLinkedList->getIterator();

    cout << "Going on SingleLinkedList to forward\n";
    while (itr->hasNext()) {
        printSomeStruct(itr->next());
    }

    delete itr;
    delete singleLinkedList;
    cout << "--------------TEST SingleLinkedList--------------\n";
}

void testLinkedList() {
    cout << "\n--------------TEST LinkedList--------------\n";
    auto *linkedList = new LinkedList;
    for (int i = 0; i < DEFAULT_SIZE_ARRAY; ++i) {
        linkedList->push(data[i]);
    }

    LinkedList::Iterator *itr = linkedList->getIterator();

    cout << "Going on LinkedList to forward\n";
    while (itr->hasNext()) {
        printSomeStruct(itr->next());
    }

    cout << "Going on LinkedList to back\n";
    while (itr->hasPrevious()) {
        printSomeStruct(itr->previous());
    }

    delete itr;
    delete linkedList;
    cout << "--------------TEST LinkedList--------------\n";
}

int main() {
    srand(time(0));
    initTestArray();
    testSingleLinkedList();
    testLinkedList();
    testLoopLinkedList();
    delete data;
    return 0;
}