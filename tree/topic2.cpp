// inorder tree

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
    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    cout << "inoder : ";
    inorder(root);
    cout << endl;
    cout << "preorder : ";
    postorder(root);

    return 0;
}
