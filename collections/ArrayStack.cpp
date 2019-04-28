#include <stdexcept>

#define DEFAULT_CAPACITY 8

using namespace std;

struct ArrayStack {
public:
    void push(char c) {
        if (this->size == this->capacity) {
            increaseCapacity();
        }
        this->data[this->size++] = c;
    }

    char pop() {
        if (this->size == 0) {
            throw runtime_error("ArrayStack is empty");
        }
        return this->data[--(this->size)];
    }

    unsigned int getSize() {
        return this->size;
    }

private:
    unsigned int size = 0;
    unsigned int capacity = DEFAULT_CAPACITY;
    char *data = new char[DEFAULT_CAPACITY];

    void increaseCapacity() {
        char *temp = new char[this->capacity * 2];
        for (int i = 0; i < this->capacity; i++) {
            temp[i] = this->data[i];
        }
        this->capacity *= 2;
        this->data = temp;
    }
};