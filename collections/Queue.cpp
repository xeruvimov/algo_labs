#include <stdexcept>

#define DEFAULT_CAPACITY 8

using namespace std;

struct Queue {
public:
    void push(char c) {
        if (this->size == this->capacity) {
            increaseCapacity();
        }
        this->data[this->size++] = c;
    }

    char pop() {
        if (this->size == 0) {
            throw runtime_error("Queue is empty");
        }
        char result = this->data[0];
        shiftDataAfterPop();
        this->size--;
        return result;
    }

    unsigned int getSize() {
        return this->size;
    }

private:
    unsigned int size = 0;
    unsigned int capacity = DEFAULT_CAPACITY;
    char *data = new char[DEFAULT_CAPACITY];

    void shiftDataAfterPop() {
        for (int i = 1; i < this->size; ++i) {
            this->data[i - 1] = this->data[i];
        }
    }

    void increaseCapacity() {
        char *temp = new char[this->capacity * 2];
        for (int i = 0; i < this->capacity; i++) {
            temp[i] = this->data[i];
        }
        this->capacity *= 2;
        this->data = temp;
    }
};