#include <stdexcept>
#include "../LabTwo.cpp"
#include "nodes.h"

using namespace std;

struct LinkedList {
public:
    void push(SomeStruct c) {
        auto *newNode = new DoubleLinkNode;
        newNode->data = c;

        if (this->size == 0) {
            this->head = newNode;
            this->tail = this->head;
        } else {
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }

        this->size++;
    }

    void deleteLast() {
        if (this->size == 0) {
            throw runtime_error("Delete from empty LinkedList");
        }

        if (this->size == 1) {
            delete head;
            this->head = nullptr;
            this->tail = this->head;
        } else {
            this->tail = this->tail->prev;
            delete this->tail->next;
        }
        this->size--;
    }

    struct Iterator {
        DoubleLinkNode *nextNode;
        DoubleLinkNode *prevNode;

        explicit Iterator(LinkedList &linkedList) {
            this->nextNode = linkedList.getHead();
            this->prevNode = NULL;
        }

        bool hasNext() {
            return this->nextNode != NULL;
        }

        bool hasPrevious() {
            return this->prevNode != NULL;
        }

        SomeStruct next() {
            if (this->nextNode == NULL) {
                throw runtime_error("No such element exception");
            }
            SomeStruct result = this->nextNode->data;
            this->prevNode = this->nextNode;
            this->nextNode = this->nextNode->next;
            return result;
        }

        SomeStruct previous() {
            if (this->prevNode == NULL) {
                throw runtime_error("No such element exception");
            }
            SomeStruct result = this->prevNode->data;
            this->nextNode = this->prevNode;
            this->prevNode = this->prevNode->prev;
            return result;
        }
    };

    Iterator *getIterator() {
        return new Iterator(*this);
    }

    virtual ~LinkedList() {
        DoubleLinkNode *nextNode = this->head->next;
        for (int i = 0; i < size; ++i) {
            delete this->head;
            this->head = NULL;
            if (nextNode != NULL) {
                this->head = nextNode;
                nextNode = this->head->next;
            }
        }
    }

private:
    size_t size = 0;
    DoubleLinkNode *head = NULL;
    DoubleLinkNode *tail = NULL;

    DoubleLinkNode *getHead() {
        return this->head;
    }
};