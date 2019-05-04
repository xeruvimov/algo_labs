#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"
#include "lists/BinaryTree.cpp"

#define DEFAULT_SIZE 15

using namespace std;

int data[DEFAULT_SIZE];
BinaryTree *tree;

void initTestData() {
    for (int &i : data) {
        i = rand() % 100;
    }
}

void initTree() {
    tree = new BinaryTree;
    for (int &i : data) {
        tree->insert(i);
    }
}

void printTestArray() {
    for (int &i : data) {
        cout << i << ' ';
    }
    cout << endl;
}

void testSearch() {
    auto search = data[7];
    cout << endl << "Search element " << search << endl;

    TreeNode *resultSearch = tree->search(search);
    if (resultSearch != NULL) {
        cout << "Searching data in node on address: " << resultSearch << endl;
    } else {
        cout << "Element not found" << endl;
    }

    search = -1;
    cout << "Search element " << search << endl;

    resultSearch = tree->search(search);
    if (resultSearch != NULL) {
        cout << "Searching data in node on address: " << resultSearch << endl;
    } else {
        cout << "Element not found" << endl;
    }
}

void testDelete() {
    cout << endl << "Delete elements: " << data[3] << ' ' << data[8] << ' ' << data[13] << endl;
    tree->deleteNode(data[3]);
    tree->deleteNode(data[8]);
    tree->deleteNode(data[13]);
    tree->downwardShow();
}

void testTree() {
    cout << "\n--------------TEST BINARY TREE--------------\n";
    initTestData();
    cout << "Init test data array" << endl;
    printTestArray();
    initTree();

    cout << "Upward show tree" << endl;
    tree->upwardShow();

    cout << endl << "Downward show tree" << endl;
    tree->downwardShow();

    cout << endl << "Consistent show tree" << endl;
    tree->consistentShow();

    testDelete();
    testSearch();
    cout << "\n--------------TEST BINARY TREE--------------\n";
    delete tree;
}

int main() {
    srand(time(0));
    testTree();
    return 0;
}
#pragma clang diagnostic pop