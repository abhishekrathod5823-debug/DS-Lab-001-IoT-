#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

    void insertRecursive(Node* current, int val) {
        if (val < current->val) {
            if (current->left == nullptr) {
                current->left = new Node(val);
            } else {
                insertRecursive(current->left, val);
            }
        } else if (val > current->val) {
            if (current->right == nullptr) {
                current->right = new Node(val);
            } else {
                insertRecursive(current->right, val);
            }
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Getter to access root safely from main
    Node* getRoot() const {
        return root;
    }

    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
        } else {
            insertRecursive(root, val);
        }
    }

    // Inorder Traversal: Left -> Root -> Right
    void inorder(Node* current) const {
        if (current != nullptr) {
            inorder(current->left);
            cout << current->val << " ";
            inorder(current->right);
        }
    }

    // Preorder Traversal: Root -> Left -> Right
    void preorder(Node* current) const {
        if (current != nullptr) {
            cout << current->val << " ";
            preorder(current->left);
            preorder(current->right);
        }
    }

    // Postorder Traversal: Left -> Right -> Root
    void postorder(Node* current) const {
        if (current != nullptr) {
            postorder(current->left);
            postorder(current->right);
            cout << current->val << " ";
        }
    }
};

int main() {
    BinarySearchTree bst;
    int elements[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; ++i) {
        bst.insert(elements[i]);
    }

    cout << "BST Traversals (without vector):\n";

    cout << "* Inorder:   ";
    bst.inorder(bst.getRoot());
    cout << "\n";

    cout << "* Preorder:  ";
    bst.preorder(bst.getRoot());
    cout << "\n";

    cout << "* Postorder: ";
    bst.postorder(bst.getRoot());
    cout << "\n";

    return 0;
}