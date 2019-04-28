#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
#pragma ide diagnostic ignored "cert-err34-c"

#include <stdio.h>
#include "LabTwo.cpp"


void readBinaryFile(SomeStruct &s, FILE *file) {
    fread((&s.id), sizeof(s.id), 1, file);
    fread((&s.stringOne), sizeof(s.stringOne), 1, file);
    fread((&s.stringTwo), sizeof(s.stringTwo), 1, file);
    fread((&s.lengthArray), sizeof(s.lengthArray), 1, file);
    fread((&s.array), s.lengthArray * sizeof(s.array), s.lengthArray, file);
}

void writeToBinaryFile(SomeStruct &s, FILE *file) {
    fwrite((&s.id), sizeof(s.id), 1, file);
    fwrite((&s.stringOne), sizeof(s.stringOne), 1, file);
    fwrite((&s.stringTwo), sizeof(s.stringTwo), 1, file);
    fwrite((&s.lengthArray), sizeof(s.lengthArray), 1, file);
    fwrite((&s.array), s.lengthArray * sizeof(s.array), s.lengthArray, file);
}

void readTextFile(SomeStruct &s, FILE *file) {
    fscanf(file, "ID: %lf\n", &s.id);
    fscanf(file, "First string: %s\n", s.stringOne);
    s.stringTwo = new char[10];
    fscanf(file, "Second string: %s\n", s.stringTwo);
    fscanf(file, "Arrays length: %d\n", &s.lengthArray);
    s.array = new double[s.lengthArray];
    for (int i = 0; i < s.lengthArray; i++) {
        fscanf(file, "%lf; ", &s.array[i]);
    }
}

void writeToTextFile(SomeStruct *s, FILE *file) {
    fprintf(file, "ID: %lf\nFirst string: %s\nSecond string: %s\nArrays length: %d\n", s->id, s->stringOne,
            s->stringTwo, s->lengthArray);
    for (int i = 0; i < s->lengthArray; i++) {
        fprintf(file, "%lf; ", s->array[i]);
    }
}

void writeStructToConsole(SomeStruct t) {
    outOtherString(t);
    outDoubleArray(&t);
}


FILE *file;

int main() {
    srand(time(0));
    SomeStruct *writeStructs = new SomeStruct[3];
    SomeStruct *readTextStructs = new SomeStruct[3];
    SomeStruct *readBinaryStructs = new SomeStruct[3];

    cout << "Init write structs" << endl;
    for (int i = 0; i < 3; i++) {
        initSomeStruct(writeStructs[i]);
    }

    cout << "Write structs to files" << endl;
    for (int i = 0; i < 3; i++) {
        char *fileName = new char[100];
        sprintf(fileName, "text_%d", i);
        file = fopen(fileName, "wt");
        writeToTextFile(&writeStructs[i], file);
        fclose(file);
        cout << i << " struct was written to text file" << endl;
        sprintf(fileName, "binary_%d", i);
        file = fopen(fileName, "wb");
        writeToBinaryFile(writeStructs[i], file);
        fclose(file);
        cout << i << " struct was written to binary file" << endl;
    }

    cout << "Read structs from text file" << endl;
    for (int i = 0; i < 3; i++) {
        char *fileName = new char[100];
        sprintf(fileName, "text_%d", i);
        file = fopen(fileName, "rt");
        readTextFile(readTextStructs[i], file);
        fclose(file);
        cout << i << " struct was read from text file" << endl;
    }

    cout << "Write structs to binary file" << endl;
    for (int i = 0; i < 3; i++) {
        char *fileName = new char[300];
        sprintf(fileName, "binary_%d", i);
        file = fopen(fileName, "rb");
        readBinaryFile(readBinaryStructs[i], file);
        fclose(file);
        cout << i << " struct was written to binary file" << endl;
    }

    cout << "Output text struct" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " text struct" << endl;
        writeStructToConsole(readTextStructs[i]);
    }

    cout << "Output binary struct" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " binary struct" << endl;
        writeStructToConsole(readBinaryStructs[i]);
    }
    return 0;
}

#pragma clang diagnostic pop