#include <iostream>
#include "collections/Queue.cpp"
#include "collections/LoopQueue.cpp"
#include "collections/ArrayStack.cpp"
#include "collections/LinkedStack.cpp"
#include "LabTwo.cpp"

using namespace std;

void testQueue() {
    cout << "\nTest Queue\n";
    Queue queue;
    cout << "Push 5 random char\n";
    for (int i = 0; i < 5; ++i) {
        char t = getRandomChar();
        cout << "Push char: " << t << endl;
        queue.push(t);
    }
    cout << "Pop all data from Queue\n";
    for (int j = 0; j < 5; ++j) {
        cout << queue.pop();
    }
    cout << endl;
}

void testLoopQueue() {
    cout << "\nTest LoopQueue\n";
    LoopQueue loopQueue;
    cout << "Push 5 random char\n";
    for (int i = 0; i < 5; ++i) {
        char t = getRandomChar();
        cout << "Push char: " << t << endl;
        loopQueue.push(t);
    }
    cout << "Pop all data from LoopQueue\n";
    for (int j = 0; j < 5; ++j) {
        cout << loopQueue.pop();
    }
    cout << endl;
}

void testArrayStack() {
    cout << "\nTest ArrayStack\n";
    ArrayStack arrayStack;
    cout << "Push 5 random char\n";
    for (int i = 0; i < 5; ++i) {
        char t = getRandomChar();
        cout << "Push char: " << t << endl;
        arrayStack.push(t);
    }
    cout << "Pop all data from ArrayStack\n";
    for (int j = 0; j < 5; ++j) {
        cout << arrayStack.pop();
    }
    cout << endl;
}

void testLinkedStack() {
    cout << "\nTest LinkedStack\n";
    LinkedStack linkedStack;
    cout << "Push 5 random char\n";
    for (int i = 0; i < 5; ++i) {
        char t = getRandomChar();
        cout << "Push char: " << t << endl;
        linkedStack.push(t);
    }
    cout << "Pop all data from LinkedStack\n";
    for (int j = 0; j < 5; ++j) {
        cout << linkedStack.pop() << endl;
    }
    cout << endl;
}

int main() {
    srand(time(0));
    testQueue();
    testLoopQueue();
    testArrayStack();
    testLinkedStack();
}