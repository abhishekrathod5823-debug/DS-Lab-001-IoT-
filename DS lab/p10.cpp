
#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n)
{
    int minIndex, temp;

    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[100], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of elements!";
        return 0;
    }

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\n1. Bubble Sort";
    cout << "\n2. Selection Sort";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            bubbleSort(a, n);
            cout << "Sorted array using Bubble Sort: ";
            display(a, n);
            break;

        case 2:
            selectionSort(a, n);
            cout << "Sorted array using Selection Sort: ";
            display(a, n);
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}
