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

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ",";
    preOrder(root->left);
    preOrder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ",";
}

int main()
{
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = BSTbuild(arr, n);

    cout << "---travel---\n";

    cout<<"inorder : ";
    inorder(root);
    cout << endl;

    cout << "preorder : ";
    preOrder(root);
    cout << endl;

    cout << "postorder : ";
    postorder(root);
    cout << endl;
    return 0;
}
