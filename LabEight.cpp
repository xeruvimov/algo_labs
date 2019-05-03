#include <iostream>
#include "LabSix.cpp"
#include "lists/TemplateLinkedList.cpp"

using namespace std;

TemplateLinkedList<double> *list;

void printList() {
    auto itr = list->getIterator();
    while (itr->hasNext()) {
        cout << itr->next() << ' ';
    }
    cout << endl;
    delete itr;
}

void initList() {
    list = new TemplateLinkedList<double>;
    initTestData();
    for (double &i: data) {
        list->push(i);
    }
}

//return -1 if s not found
int linearSearchArray(const double array[], double s) {
    for (int i = 0; i < DEFAULT_SIZE; ++i) {
        if (array[i] == s) {
            return i;
        }
    }
    return -1;
}

//return -1 if s not found
int binarySearchArray(const double array[], double s) {
    int first = 0;
    int last = DEFAULT_SIZE;
    int mid;
    while (first < last) {
        mid = first + (last - first) / 2;
        if (s <= array[mid]) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }

    if (last < DEFAULT_SIZE && array[last] == s) {
        return last;
    } else {
        return -1;
    }
}

//return -1 if s not found
template<class T>
int linearSearchList(TemplateLinkedList<T> *l, T s) {
    int result = 0;
    auto itr = l->getIterator();
    while (itr->hasNext()) {
        if (itr->next() == s) {
            delete itr;
            return result;
        }
        result++;
    }
    delete itr;
    return -1;
}

void testLinearSearchOnArray() {
    cout << "\n--------------TEST LINER SEARCH ON ARRAY--------------\n";
    initTestData();
    printData();
    auto search = data[rand() % DEFAULT_SIZE];
    cout << "Searching value is " << search << endl;
    cout << "On position " << linearSearchArray(data, search) << endl;

    search = -(rand() % 10);
    cout << "Searching value is " << search << endl;
    cout << "On position " << linearSearchArray(data, search);
    cout << "\n--------------TEST LINER SEARCH ON ARRAY--------------\n";
}

void testLinearSearchOnList() {
    cout << "\n--------------TEST LINER SEARCH ON LIST--------------\n";
    initList();
    printList();
    auto search = data[rand() % DEFAULT_SIZE];
    cout << "Searching value is " << search << endl;
    cout << "On position " << linearSearchList(list, search) << endl;

    search = -(rand() % 10);
    cout << "Searching value is " << search << endl;
    cout << "On position " << linearSearchList(list, search);
    cout << "\n--------------TEST LINER SEARCH ON LIST--------------\n";
    delete list;
}

void testBinarySearchOnArray() {
    cout << "\n--------------TEST BINARY SEARCH ON ARRAY--------------\n";
    initTestData();
    shellSort(data);
    printData();
    auto search = data[rand() % DEFAULT_SIZE];
    cout << "Searching value is " << search << endl;
    cout << "On position " << binarySearchArray(data, search) << endl;

    search = -(rand() % 10);
    cout << "Searching value is " << search << endl;
    cout << "On position " << binarySearchArray(data, search);
    cout << "\n--------------TEST BINARY SEARCH ON ARRAY--------------\n";
}

int main() {
    srand(time(0));
    testLinearSearchOnArray();
    testLinearSearchOnList();
    testBinarySearchOnArray();
    return 0;
}