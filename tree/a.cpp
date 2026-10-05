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
        right = left = NULL;
    }
};

static int idx = -1;
Node *buildeTree(int preoder[])
{
    idx++;
    if (preoder[idx] == -1)
    {
        return NULL;
    }
    Node *root = new Node(preoder[idx]);
    root->left = buildeTree(preoder);
    root->right = buildeTree(preoder);

    return root;
}
int main()
{
    int preorder[] = {1, 2, 1, 1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildeTree(preorder);

    cout << "root : " << root->data;
    return 0;
}