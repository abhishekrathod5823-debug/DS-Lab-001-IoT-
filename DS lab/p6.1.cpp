#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class list
{
    Node *head;
    Node *tail;

public:
    list()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        // Node newNode(val);// static

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head; //(*newNode).next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        // Node newNode(val);// static

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "LL is empty..";
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "LL empty..";
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    list ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    // 3->2->1->null

    ll.push_back(8);
    ll.push_back(5);
    // 3->2->1->8->5->null

    ll.pop_front();
    // 2->1->8->5->null

    ll.print();
    // 2->1->8->5->null

    ll.pop_back();
    // 2->1->8->null

    ll.print();

    return 0;
}