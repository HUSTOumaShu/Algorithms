#include <iostream>
using namespace std;

struct tNode
{
    int data;
    tNode *pLeft;
    tNode *pRight;
};

tNode *root; // root of tree

tNode *newNode(int data)
{
    tNode *node = new tNode;
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}

// insert new node into tree
void insertNode(tNode *p, int value)
{
    tNode *node = newNode(value);
    if (p->pLeft == NULL)
        p->pLeft = node;
    else if (p->pRight == NULL)
        p->pRight = node;
    else
    {
        node->pLeft = p->pLeft;
        p->pLeft = node;
    }
}

// insert new node into root
void insertNewRoot(int value)
{
    tNode *node = newNode(value);
    node->pLeft = root;
    root = node;
}

// Duyet cay nhi phan
void NLR(tNode *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        NLR(root->pLeft);
        NLR(root->pRight);
    }
}
void LNR(tNode *root)
{
    if (root != NULL)
    {
        LNR(root->pLeft);
        cout << root->data << " ";
        LNR(root->pRight);
    }
}
void LRN(tNode *root)
{
    if (root != NULL)
    {
        LRN(root->pLeft);
        LRN(root->pRight);
        cout << root->data << " ";
    }
}

int main()
{
    root = newNode(1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root->pLeft, 4);
    insertNode(root->pLeft, 5);
    insertNode(root->pLeft->pRight, 6);
    insertNode(root->pLeft->pRight, 7);
    NLR(root);
    cout << endl;
    LNR(root);
    cout << endl;
    LRN(root);
    cout << endl;
}
