#include <iostream>
using namespace std;

class Complex {
    float real;
    float imaginary;

public:
    Complex(float r = 0, float i = 0) {
    real = r;
    imaginary = i;
}
    void addComplex(float r, float i) {
        real += r;
        imaginary += i;
    }

    void subtractComplex(float r, float i) {
        real -= r;
        imaginary -= i;
    }

    void display() {
        if (real != 0) {
            cout << real;
            if (imaginary > 0) {
                cout << "+";
            }
        } else if (imaginary == 0) {
            cout << "0";
        }

        if (imaginary != 0) {
            cout << imaginary << "i";
        }

        cout << endl;
    }

};




void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "swapByValue: a = " << a << ", b = " << b << endl;
}

void swapByAddress(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    cout << "swapByAddress: a = " << *a << ", b = " << *b << endl;
}

void swapByReference(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "swapByReference: a = " << a << ", b = " << b << endl;
}



int main() {
   /* int real=0; int imaginary=0;
    cout << "Please Enter the Real number:" << endl;
    cin >> real;
    cout << "Please Enter the Imaginary number:" << endl;
    cin >> imaginary;

    Complex c1(real, imaginary);

    cout << "Original complex number: ";
    c1.display();

    c1.addComplex(1, 2);
    cout << "After addition: ";
    c1.display();

    c1.subtractComplex(2, 3);
    cout << "After subtraction: ";
    c1.display();*/


    return 0;
}
