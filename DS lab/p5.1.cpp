#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if (rear == MAX - 1)
    {
        cout << "Queue Overflow!" << endl;
        return;
    }

    cout << "Enter value: ";
    cin >> value;

    if (front == -1)
        front = 0;

    queue[++rear] = value;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow!" << endl;
        return;
    }

    cout << queue[front] << " deleted." << endl;
    front++;

    if (front > rear)
        front = rear = -1;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";

    cout << endl;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
