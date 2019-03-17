#include <cstdlib>
#include <iostream>

using namespace std;

struct SomeStruct { //lol ну и правила
    char *stringTwo;
    double id;
    double *array;
    int lengthArray;
    char stringOne[10];
};

double getRandomDouble(double fMin, double fMax);

char getRandomChar();

SomeStruct initSomeStruct(SomeStruct &t);

void initDoubleArray(SomeStruct *t);

void outDoubleArray(SomeStruct *t);

void initOtherString(SomeStruct &t);

void outOtherString(SomeStruct &t);

void deletAll(SomeStruct *t);


SomeStruct initSomeStruct(SomeStruct &t) {
    initDoubleArray(&t);
    outDoubleArray(&t);
    initOtherString(t);
    outOtherString(t);
    return t;
}

double getRandomDouble(double fMin, double fMax) {
    double f = (double) rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void initDoubleArray(SomeStruct *t) {
    cout << "random 10 values of double" << endl;
    t->array = new double[10];
    t->lengthArray = 10;
    for (int i = 0; i < t->lengthArray; ++i) {
        t->array[i] = getRandomDouble(1.0, 10.0);
    }
}

void outDoubleArray(SomeStruct *t) {
    for (int i = 0; i < t->lengthArray; ++i) {
        cout << t->array[i] << ' ';
    }
    cout << endl;
}

char getRandomChar() {
    static char c = 'A' + rand() % 24;
    return c;
}

void initOtherString(SomeStruct &t) {
    cout << "randomize data to char arrays and id" << endl;
    for (char &i : t.stringOne) {
        i = getRandomChar();
    }

    t.stringTwo = new char[10];
    for (int j = 0; j < 10; ++j) {
        t.stringTwo[j] = getRandomChar();
    }

    t.id = getRandomDouble(0, 100);
}

void outOtherString(SomeStruct &t) {
    for (char &i : t.stringOne) {
        cout << i;
    }
    cout << endl;

    for (int j = 0; j < 10; ++j) {
        cout << t.stringTwo[j];
    }
    cout << endl;
    cout << "id - " << t.id << endl;
}

void deletAll(SomeStruct *t) {
    delete[] t->stringTwo;
    delete t->array;
}
