#include "../LabTwo.cpp"

struct DoubleLinkNode {
    SomeStruct data{};
    DoubleLinkNode *next = NULL;
    DoubleLinkNode *prev = NULL;
};

struct LinkNode {
    SomeStruct data{};
    LinkNode *next = NULL;
};

struct TreeNode {
    int data;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
};