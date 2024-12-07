#include <iostream>
#include <string.h>
using namespace std;

class Complex {
    int real;
    int imagine;
public:
    Complex(int x = 0, int y = 0) : real(x), imagine(y) {}

    void setReal(int _Real) { real = _Real; }
    int getReal() const { return real; }

    void setImage(int _Imagine) { imagine = _Imagine; }
    int getImagine() const { return imagine; }

    void print() {
        cout << real;
        if (imagine > 0) {
            cout << "+" << imagine << "j" << endl;
        } else if (imagine < 0) {
            cout << imagine << "j" << endl;
        }
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imagine + c.imagine);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imagine - c.imagine);
    }

    Complex operator+(int x) {
        return Complex(real + x, imagine);
    }

    Complex operator-(int x) {
        return Complex(real - x, imagine);
    }

    bool operator==(Complex x) {
        return this->getReal() == x.getReal() && this->getImagine() == x.getImagine();
    }

    Complex& operator+=(Complex x) {
        real += x.getReal();
        imagine += x.getImagine();
        return *this;
    }

    Complex operator++() { // Prefix increment
        ++real;
        return *this;
    }

    Complex operator++(int) { // Postfix increment
        Complex temp = *this;
        real += 1;
        return temp;
    }

};


int main() {
    Complex c1(1, 5);
    Complex c2(10, 15);

    Complex c3 = c1 + c2;
    Complex c4 = c2 - c1;
    Complex c5 = c1+10;
    Complex c6 = c2-5;


    c3.print();
    c4.print();
    c5.print();
    c6.print();


    cout << "----------------After (==) ----------------" << endl;
    bool isEqual=(c3==c4);
    cout << (isEqual) << endl;

    cout << "----------------Before (+=) ----------------" << endl;
    c3.print();

    cout << "----------------After (+=) ----------------" << endl;
    c3 += c4;
    c3.print();

    cout << "----------------After c++ ----------------" << endl;
    c3++;
    c3.print();

    cout << "----------------After ++c ----------------" << endl;
    ++c3;
    c3.print();

    return 0;
}
