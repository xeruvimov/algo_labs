#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nullptr"

#include <search.h>
#include "nodes.h"

using namespace std;

struct BinaryTree {
public:

    void insert(int data);

    void upwardShow();

    void downwardShow();

    void consistentShow();

    TreeNode *search(int data);

    virtual ~BinaryTree();

    void destroyTree();

    TreeNode *deleteNode(int data);

private:
    TreeNode *head = NULL;

    static TreeNode *deleteNode(TreeNode *node, int data);

    static void destroyTree(TreeNode *node);

    static void insert(int data, TreeNode *node);

    static void upwardShow(TreeNode *node);

    static void downwardShow(TreeNode *node);

    static void consistentShow(TreeNode *node);

    static TreeNode *search(int data, TreeNode *node);
};

void BinaryTree::insert(int data, TreeNode *node) {
    if (data < node->data) {
        if (node->left != NULL)
            insert(data, node->left);
        else {
            node->left = new TreeNode;
            node->left->data = data;
        }
    } else if (data >= node->data) {
        if (node->right != NULL)
            insert(data, node->right);
        else {
            node->right = new TreeNode;
            node->right->data = data;
        }
    }
}

void BinaryTree::insert(int data) {
    if (this->head == NULL) {
        this->head = new TreeNode;
        this->head->data = data;
    } else {
        insert(data, this->head);
    }
}

void BinaryTree::upwardShow(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    upwardShow(node->left);
    upwardShow(node->right);

    cout << node->data << ' ';
}

void BinaryTree::downwardShow(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    cout << node->data << ' ';

    downwardShow(node->left);
    downwardShow(node->right);
}

void BinaryTree::consistentShow(TreeNode *node) {
    if (node == NULL) {
        return;
    }

    consistentShow(node->left);
    cout << node->data << ' ';
    consistentShow(node->right);
}

void BinaryTree::upwardShow() {
    if (this->head == NULL) {
        return;
    }

    upwardShow(this->head->left);
    upwardShow(this->head->right);

    cout << this->head->data << ' ';
}

void BinaryTree::downwardShow() {
    if (this->head == NULL) {
        return;
    }

    cout << this->head->data << ' ';

    downwardShow(this->head->left);
    downwardShow(this->head->right);
}

void BinaryTree::consistentShow() {
    if (this->head == NULL) {
        return;
    }

    consistentShow(this->head->left);
    cout << this->head->data << ' ';
    consistentShow(this->head->right);
}

//return NULL if data not found
TreeNode *BinaryTree::search(int data, TreeNode *node) {
    if (node != NULL) {
        if (data == node->data)
            return node;
        if (data < node->data)
            return search(data, node->left);
        else
            return search(data, node->right);
    } else {
        return NULL;
    }
}

TreeNode *BinaryTree::search(int data) {
    if (this->head != NULL) {
        if (data == this->head->data)
            return this->head;
        if (data < this->head->data)
            return search(data, this->head->left);
        else
            return search(data, this->head->right);
    } else {
        return NULL;
    }
}

BinaryTree::~BinaryTree() {
    destroyTree();
}

void BinaryTree::destroyTree() {
    destroyTree(this->head);
}

void BinaryTree::destroyTree(TreeNode *node) {
    if (node != NULL) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

TreeNode *BinaryTree::deleteNode(TreeNode *node, int data) {
    if (node == NULL) {
        return node;
    }
    if (data == node->data) {
        TreeNode *tmp;
        if (node->right == NULL) {
            tmp = node->left;
        } else {
            TreeNode *ptr = node->right;
            if (ptr->left == NULL) {
                ptr->left = node->left;
                tmp = ptr;
            } else {
                TreeNode *pmin = ptr->left;
                while (pmin->left != NULL) {
                    ptr = pmin;
                    pmin = ptr->left;
                }
                ptr->left = pmin->right;
                pmin->left = node->left;
                pmin->right = node->right;
                tmp = pmin;
            }
        }
        delete node;
        return tmp;
    } else if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else {
        node->right = deleteNode(node->right, data);
    }
    return node;
}

TreeNode *BinaryTree::deleteNode(int data) {
    return deleteNode(this->head, data);
}


#pragma clang diagnostic pop