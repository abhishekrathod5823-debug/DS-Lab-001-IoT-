// delete node on BST

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

Node *BSTbuild(int arr[], int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << ",";
    inorder(root->right);
}

Node *getIS(Node *root)
{
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *delNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > key)
    {
        root->left = delNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = delNode(root->right, key);
    }
    else
    { // delete
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *IS = getIS(root->right);

            root->data = IS->data;
            root->right = delNode(root->right, IS->data);
        }
    }
    return root;
}

int main()
{

    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = BSTbuild(arr, n);

    inorder(root);
    cout << endl;
    root = delNode(root, 6);

    inorder(root);

    return 0;
}