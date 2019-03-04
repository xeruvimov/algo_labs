#include <iostream>

using namespace std;

int main() {
    char charArray[3];
    char *charPointer;
    double doubleArray[3];
    double **doubleArrayPointer;
    int intTreeArray[3][3][3];
    int (*intTwoArrayPointer)[3][3];

    //1
    for (char i : charArray) {
        cout << i << ' ';
    }

    //2
    cout << "Input 3 char\n";
    for (char &i : charArray) {
        cin >> i;
    }

    //3
    cout << "Result\n";
    for (char i : charArray) {
        cout << i << ' ';
    }
    cout << endl;

    //4
    charPointer = charArray;
    cout << "Address charArray " << &charArray << endl;
    cout << "Address charPointer " << &charPointer << endl;

    cout << "Data in charPointer ";
    for (int k = 0; k < 3; ++k) {
        cout << *(charPointer + k) << ' ';
    }
    cout << endl;

    //5
    cout << "Data in charArray with ptr: ";
    for (int k = 0; k < 3; ++k) {
        cout << *(charArray + k) << ' ';
    }


    //6
    for (double d : doubleArray) {
        cout << d << ' ';
    }

    for (double &d : doubleArray) {
        cin >> d;
    }

    for (double d : doubleArray) {
        cout << d << ' ';
    }

    //7
    int arraySize;
    cout << "\nInput size of char array ";
    cin >> arraySize;
    charPointer = new char[arraySize];

    cout << "\nData in new char array ";
    for (int j = 0; j < arraySize; ++j) {
        cout << *(charPointer + j) << ' ';
    }

    cout << "\nInput data in new char array of size " << arraySize << ": ";
    for (int j = 0; j < arraySize; ++j) {
        cin >> *(charPointer + j);
    }

    for (int j = 0; j < arraySize; ++j) {
        cout << *(charPointer + j) << ' ';
    }

    //8
    delete charPointer;

    int length, width;
    cout << "\nInput size of double two array: ";
    cin >> length >> width;
    doubleArrayPointer = new double *[length];

    cout << "\nInput data in this array: ";
    for (int l = 0; l < length; ++l) {
        doubleArrayPointer[l] = new double[width];
        for (int i = 0; i < width; ++i) {
            cin >> doubleArrayPointer[l][i];
        }
    }

    cout << "Data in this array:\n";
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << doubleArrayPointer[i][j] << ' ';
        }
        cout << endl;
    }
    delete doubleArrayPointer;

    //9
    cout << "Random element array #5: " << intTreeArray[0][0][2] << endl;

    //10
    cout << "Else random element array #5: " << *(*(*(intTreeArray + 1) + 1) + 1) << endl;

    //11 ???
    intTwoArrayPointer = intTreeArray;
    cout << "Test" << *(intTwoArrayPointer+1)[0][0];

    return 0;
}