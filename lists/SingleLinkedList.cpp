#include <stdexcept>

using namespace std;

struct SingleLinkedList {
public:
    void push(SomeStruct c) {
        auto *newNode = new LinkNode;
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
        LinkNode *nextNode;

        explicit Iterator(SingleLinkedList &singleLinkedList) {
            this->nextNode = singleLinkedList.getHead();
        }

        bool hasNext() {
            return this->nextNode != NULL;
        }

        SomeStruct next() {
            if (this->nextNode == NULL) {
                throw runtime_error("No such element exception");
            }
            SomeStruct result = this->nextNode->data;
            this->nextNode = this->nextNode->next;
            return result;
        }
    };

    Iterator *getIterator() {
        return new Iterator(*this);
    }

    virtual ~SingleLinkedList() {
        LinkNode *nextNode = this->head->next;
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
    LinkNode *head = NULL;
    LinkNode *tail = NULL;

    LinkNode *getHead() {
        return this->head;
    }
};