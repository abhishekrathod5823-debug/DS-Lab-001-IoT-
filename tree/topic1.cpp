// preorder tree

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

static int idx = -1;

Node *buildTree(int preorder[])
{
    idx++;

    if (preorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
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

int main()
{
    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);

    cout << root->data << endl;
    cout << root->left->data << endl;
    cout << root->right->data << endl;

    cout << "----------------------\n";
    cout << "travel preorder\n";

    preOrder(root);

    return 0;
}
