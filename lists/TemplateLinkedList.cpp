#include <stdexcept>
#include "nodes.h"

using namespace std;

template<class T>
struct GenericNode {
    T data;

    GenericNode *next = NULL;
};

template<class T>
struct TemplateLinkedList {
public:
    void push(T c) {
        auto *newNode = new GenericNode<T>;
        newNode->data = c;

        if (this->size == 0) {
            this->head = newNode;
            this->tail = this->head;
        } else {
            this->tail->next = newNode;
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
            delete this->tail->next;
        }
        this->size--;
    }

    struct Iterator {
        GenericNode<T> *nextNode;

        explicit Iterator(TemplateLinkedList &list) {
            this->nextNode = list.getHead();
        }

        bool hasNext() {
            return this->nextNode != NULL;
        }

        T next() {
            if (this->nextNode == NULL) {
                throw runtime_error("No such element exception");
            }
            T result = this->nextNode->data;
            this->nextNode = this->nextNode->next;
            return result;
        }
    };

    Iterator *getIterator() {
        return new Iterator(*this);
    }

    virtual ~TemplateLinkedList() {
        GenericNode<T> *nextNode = this->head->next;
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
    GenericNode<T> *head = NULL;
    GenericNode<T> *tail = NULL;

    GenericNode<T> *getHead() {
        return this->head;
    }
};