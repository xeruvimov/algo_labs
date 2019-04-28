#include <stdexcept>

#define DEFAULT_CAPACITY 8

using namespace std;

struct LoopQueue {
public:
    void push(char c) {
        if (this->size == this->capacity) {
            throw runtime_error("LoopQueue is full");
        }
        this->data[this->tail] = c;
        this->size++;
        if (this->tail + 1 == this->capacity) {
            this->tail = 0;
        } else {
            this->tail++;
        }
    }

    char pop() {
        if (this->size == 0) {
            throw runtime_error("LoopQueue is empty");
        }
        char result = this->data[this->head];
        if (this->head + 1 == this->capacity) {
            this->head = 0;
        } else {
            this->head++;
        }
        this->size--;
        return result;
    }

    unsigned int getSize() {
        return this->size;
    }


private:
    unsigned int head = 0;
    unsigned int tail = 0;

    unsigned int size = 0;
    unsigned int capacity = DEFAULT_CAPACITY;
    char *data = new char[DEFAULT_CAPACITY];
};