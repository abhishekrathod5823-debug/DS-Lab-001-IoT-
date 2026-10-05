// AVL tree

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

// Get height of a node
int getHeight(Node *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

// Get balance factor
int getBalance(Node *root)
{
    if (root == NULL)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

// Right Rotation
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

// Left Rotation
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// Insert node
Node *insert(Node *root, int val)
{
    // Normal BST insertion
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
        // Duplicate goes to right
        root->right = insert(root->right, val);
    }

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && val < root->left->data)
    {
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 && val >= root->right->data)
    {
        return leftRotate(root);
    }

    // LR Case
    if (balance > 1 && val >= root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && val < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find inorder successor
Node *getIS(Node *root)
{
    Node *current = root;

    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

// Delete node
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    // Search for node
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // Node has 0 or 1 child
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

        // Node has 2 children
        Node *temp = getIS(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    // Update height
    root->height = 1 + max(getHeight(root->left),
                           getHeight(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // LR Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // RL Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder after insertion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 40);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
