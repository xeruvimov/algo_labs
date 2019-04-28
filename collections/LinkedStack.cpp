#include <stdexcept>

using namespace std;

struct Node {
    char data;
    Node *nextNode;
    Node *prevNode;
};

struct LinkedStack {
public:
    void push(char c) {
        Node *newNode = new Node;
        newNode->data = c;

        if (this->size == 0) {
            this->head = newNode;
            this->tail = this->head;
        } else {
            newNode->prevNode = this->tail;
            this->tail = newNode;
        }

        this->size++;
    }

    char pop() {
        if (this->size == 0) {
            throw runtime_error("LinkedStack is empty");
        }

        char result = this->tail->data;

        if (this->size == 1) {
            this->head = nullptr;
            this->tail = this->head;
        } else {
            this->tail = this->tail->prevNode;
        }

        this->size--;
        return result;
    }

    unsigned int getSize() {
        this->size;
    }

private:
    unsigned int size = 0;

    Node *head = nullptr;
    Node *tail;
};

