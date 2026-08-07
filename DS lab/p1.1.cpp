#include <iostream>
using namespace std;

#define MAX 100

class ArrayOperations {
    int arr[MAX];
    int size;

public:
    ArrayOperations() {
        size = 0;
    }

    // Insert an element
    void insert(int element, int position) {
        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position] = element;
        size++;

        cout << "Element inserted successfully." << endl;
        
    }

    // Delete an element
    void deleteElement(int position) {

        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;

        cout << "Element deleted successfully." << endl;
    }

    // Traverse the array
    void traverse() {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }

        cout << "Array elements are: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Search an element
    void search(int element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                cout << "Element found at position " << i << endl;
                return;
            }
        }

        cout << "Element not found." << endl;
    }
};

int main() {
    ArrayOperations obj;
    int choice, element, position;

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to insert: ";
            cin >> element;
            cout << "Enter position (0-based index): ";
            cin >> position;
            obj.insert(element, position);
            break;

        case 2:
            cout << "Enter position to delete (0-based index): ";
            cin >> position;
            obj.deleteElement(position);
            break;

        case 3:
            obj.traverse();
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> element;
            obj.search(element);
            break;

        case 5:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}