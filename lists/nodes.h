struct DoubleLinkNode {
    SomeStruct data{};
    DoubleLinkNode *next = NULL;
    DoubleLinkNode *prev = NULL;
};

struct LinkNode {
    SomeStruct data{};
    LinkNode *next = NULL;
};