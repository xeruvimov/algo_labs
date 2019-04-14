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
    fscanf(file, "ID: %lf\n", s.id);
    fscanf(file, "First string: %s\n", s.stringOne);
    s.stringTwo = new char[10];
    fscanf(file, "Second string: %s\n", s.stringTwo);
    fscanf(file, "Arrays length: %d\n", s.lengthArray);
    s.array = new double[s.lengthArray];
    for (int i = 0; i < s.lengthArray; i++) {
        fscanf(file, "%lf; ", s.array[i]);
    }
    cout << "Struct was read from text file" << endl;
}

void writeToTextFile(SomeStruct *s, FILE *file) {
    fprintf(file, "ID: %lf\nFirst string: %s\nSecond string: %s\nArrays length: %d\n", s->id, s->stringOne,
            s->stringTwo, s->lengthArray);
    for (int i = 0; i < s->lengthArray; i++) {
        fprintf(file, "%lf; ", s->array[i]);
    }
    cout << "Struct was written to text file" << endl;
}

void writeStructToConsole(SomeStruct t) {
    outDoubleArray(&t);
    outOtherString(t);
}

int main() {
    srand(time(0));
    FILE *file = fopen("test.txt", "wt");

    SomeStruct writeStructure;
    initSomeStruct(writeStructure);
    writeToTextFile(&writeStructure, file);
    fclose(file);
    file = fopen("test.txt", "rt");
    SomeStruct readStructure;
    readTextFile(readStructure, file);
    fclose(file);
    writeStructToConsole(readStructure);

    return 0;
}

#pragma clang diagnostic pop