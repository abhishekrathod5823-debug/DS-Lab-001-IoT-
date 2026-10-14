
#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int a[100], n, key, result;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of elements!";
        return 0;
    }

    cout << "Enter elements in ascending order:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    result = binarySearch(a, n, key);

    if (result == -1)
    {
        cout << "Element not found.";
    }
    else
    {
        cout << "Element found at position " << result + 1;
    }

    cout << endl;
    return 0;
}
