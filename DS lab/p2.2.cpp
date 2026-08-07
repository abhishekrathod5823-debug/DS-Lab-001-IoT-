#include <iostream>
using namespace std;

void callByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside Call by Value: a = " << a
         << ", b = " << b << endl;
}

void callByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside Call by Reference: a = " << a
         << ", b = " << b << endl;
}

int main() {
    int x = 10, y = 20;

    cout << "Before Call by Value: x = " << x << ", y = " << y << endl;
    callByValue(x, y);
    cout << "After Call by Value: x = " << x << ", y = " << y << endl;

    cout << endl;

    cout << "Before Call by Reference: x = " << x << ", y = " << y << endl;
    callByReference(x, y);
    cout << "After Call by Reference: x = " << x << ", y = " << y << endl;

    return 0;
}