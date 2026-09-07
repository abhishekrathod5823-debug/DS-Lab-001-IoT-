#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % MAX == front)
    {
        cout << "Queue Overflow!" << endl;
        return;
    }

    cout << "Enter value: ";
    cin >> value;

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    queue[rear] = value;
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow!" << endl;
        return;
    }

    cout << queue[front] << " deleted." << endl;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    int i = front;

    while (true)
    {
        cout << queue[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

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
