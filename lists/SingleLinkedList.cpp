#include <stdexcept>

using namespace std;

//todo ОПЯТЬ ВЕСЬ РОТ В ПАМЯТИ
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

private:
    size_t size = 0;
    LinkNode *head = nullptr;
    LinkNode *tail;

    LinkNode *getHead() {
        return this->head;
    }
};