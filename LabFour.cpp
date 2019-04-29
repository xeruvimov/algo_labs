#include <iostream>
#include "collections/Queue.cpp"
#include "collections/LoopQueue.cpp"
#include "collections/ArrayStack.cpp"
#include "collections/LinkedStack.cpp"
#include "LabTwo.cpp"

using namespace std;

void testQueue() {
    cout << "Test Queue";
    Queue queue;
    cout << "Push 5 random char";
    for (int i = 0; i < 5; ++i) {
        char t = getRandomChar();
        cout << "Push char: " << t;
        queue.push(t);
    }
    cout << "Pop all data from Queue";
    for (int j = 0; j < queue.getSize(); ++j) {
        cout << queue.pop();
    }
}

void testLoopQueue() {
    cout << "Test LoopQueue";
    LoopQueue loopQueue;
    cout << "Push 5 random char";
    for (int i = 0; i < 5; ++i) {
        char t = getRandomChar();
        cout << "Push char: " << t;
        loopQueue.push(t);
    }
    cout << "Pop all data from LoopQueue";
    for (int j = 0; j < loopQueue.getSize(); ++j) {
        cout << loopQueue.pop();
    }
}

void testArrayStack() {
    cout << "Test ArrayStack";
    ArrayStack arrayStack;
    cout << "Push 5 random char";
    for (int i = 0; i < 5; ++i) {
        char t = getRandomChar();
        cout << "Push char: " << t;
        arrayStack.push(t);
    }
    cout << "Pop all data from ArrayStack";
    for (int j = 0; j < arrayStack.getSize(); ++j) {
        cout << arrayStack.pop();
    }
}

void testLinkedStack() {
    cout << "Test LinkedStack";
    LinkedStack linkedStack;
    cout << "Push 5 random char";
    for (int i = 0; i < 5; ++i) {
        char t = getRandomChar();
        cout << "Push char: " << t;
        linkedStack.push(t);
    }
    cout << "Pop all data from LinkedStack";
    for (int j = 0; j < linkedStack.getSize(); ++j) {
        cout << linkedStack.pop();
    }
}

int main() {
    srand(time(0));
    testQueue();
    testLoopQueue();
    testArrayStack();
    testLinkedStack();
}