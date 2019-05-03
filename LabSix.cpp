#include <iostream>
#include <algorithm>
#include "LabTwo.cpp"

#define DEFAULT_SIZE 20

using namespace std;

double data[DEFAULT_SIZE];

void initTestData() {
    for (double &i : data) {
        i = getRandomDouble(0.1, 100.0);
    }
}

void printData() {
    for (double &i : data) {
        cout << i << ' ';
    }
    cout << endl;
}

void sortPartArray(double *array, int startIndex, int increment) {
    for (int i = startIndex; i < DEFAULT_SIZE - 1; i += increment) {
        for (int j = min(i + increment, DEFAULT_SIZE - 1); j - increment >= 0; j -= increment) {
            if (array[j - increment] > array[j]) {
                swap(array[j], array[j - increment]);
            } else {
                break;
            }
        }
    }
}

void insertionSort(double array[]) {
    for (int i = 1; i < DEFAULT_SIZE; i++)
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
            swap(array[j - 1], array[j]);
}

void shellSort(double array[]) {
    int increment = DEFAULT_SIZE / 2;
    while (increment >= 1) {
        for (int startIndex = 0; startIndex < increment; ++startIndex) {
            sortPartArray(array, startIndex, increment);
        }
        increment /= 2;
    }
}

void testShellSort() {
    cout << "\n--------------TEST SHELL SORT--------------\n";
    initTestData();
    cout << "New array of double" << endl;
    printData();
    cout << "\nResult of sort array" << endl;
    shellSort(data);
    printData();
    cout << "\nResult of sort already sorted array" << endl;
    shellSort(data);
    printData();
    cout << "\nRevers array" << endl;
    reverse(data, data + DEFAULT_SIZE);
    printData();
    cout << "\nResult of sort revers order array" << endl;
    shellSort(data);
    printData();
    cout << "\n--------------TEST SHELL SORT--------------\n";
}

void testInsertionSort() {
    cout << "\n--------------TEST INSERTION SORT--------------\n";
    initTestData();
    cout << "New array of double" << endl;
    printData();
    cout << "\nResult of sort array" << endl;
    insertionSort(data);
    printData();
    cout << "\nResult of sort already sorted array" << endl;
    insertionSort(data);
    printData();
    cout << "\nRevers array" << endl;
    reverse(data, data + DEFAULT_SIZE);
    printData();
    cout << "\nResult of sort revers order array" << endl;
    insertionSort(data);
    printData();
    cout << "\n--------------TEST INSERTION SORT--------------\n";
}

int main() {
    srand(time(0));
    testShellSort();
    testInsertionSort();
    return 0;
}

