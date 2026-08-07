#include <iostream>
using namespace std;

int main() {
    int arr[5], *ptr;

    cout << "Enter 5 array elements: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    ptr = arr + 4;

    cout << "Array elements in reverse order are: ";
    for (int i = 0; i < 5; i++) {
        cout << *ptr << " ";
        ptr--;
    }

    return 0;
}