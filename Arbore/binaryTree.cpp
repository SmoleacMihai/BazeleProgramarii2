// Binary Tree in C++

#include <stdlib.h>

#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// New node creation
node *newNode(int data)
{
    node *newElement = (node *)malloc(sizeof(node));
    newElement->data = data;
    newElement->left = NULL;
    newElement->right = NULL;
}

// Traverse Preorder
void traversePreOrder(struct node *temp)
{
    if (temp != NULL)
    {
        cout << " " << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}

// Traverse Inorder
void traverseInOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traverseInOrder(temp->left);
        cout << " " << temp->data;
        traverseInOrder(temp->right);
    }
}

// Traverse Postorder
void traversePostOrder(struct node *temp)
{
    if (temp != NULL)
    {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << " " << temp->data;
    }
}

node *CreateBinaryTree()
{
    int nr;
    cout << "Valoarea: ";
    cin >> nr;
    if (nr != 0)
    {
        node *newElement = newNode(nr);
        cout << "Left descendent of  " << newElement->data << " :" << endl;
        newElement->left = CreateBinaryTree();
        cout << "Introduceti descendentul drept al nodului " << newElement->data << " :" << endl;
        newElement->right = CreateBinaryTree();
        return newElement;
    }
}

bool isEmpty(node *root)
{
    return root == NULL;
}

int findMaxValue(node *root)
{
    if (isEmpty(root))
    {
        return -1;
    }
    int maxim = root->data;

    int lmaxim = findMaxValue(root->left);
    int rmaxim = findMaxValue(root->right);
    if (lmaxim > maxim)
        maxim = lmaxim;
    if (rmaxim > maxim)
        maxim = rmaxim;
    root = root->right;
    return maxim;
}

int main()
{
    struct node *root = CreateBinaryTree();

    cout << "\nPreorder traversal: ";
    traversePreOrder(root);
    cout << "\nInorder traversal: ";
    traverseInOrder(root);
    cout << "\nPostorder traversal: ";
    traversePostOrder(root);

    cout << "\nMaxim: " << findMaxValue(root);
}