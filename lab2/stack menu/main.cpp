#include <iostream>
#include <limits>
#include <cctype> // For isalpha
#include <thread>  // sleep_for
#include <chrono>  // seconds
#include <conio.h>
#include <windows.h>
#include <cstring>
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ESC 27
#define w 15
#define r 4
#define Enter 13
using namespace std;
struct Employee {
    string name;
    char gender;
    int salary;
    int id;
};

class Stack {
    int *arr;
    int size;
    int top;

public:
    Stack() : size(0), top(-1), arr(nullptr) {}

    Stack(int Size) {
        size = Size;
        top = -1;
        arr = new int[size];
    }
     // Copy constructor
    Stack(const Stack &other) {
        size = other.size;
        top = other.top;
        arr = new int[size];
        for (int i = 0; i <= top; i++) {
            arr[i] = other.arr[i];
        }
        objectCount++;
        cout << "Copy Constructor Called. Total Objects: " << objectCount << endl;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack full" << endl;
        } else {
            top++;
            arr[top] = x;
            cout << "Added element no: " << top + 1 << " = " << arr[top] << endl;
        }
    }

    void pop(Employee s[], int &employeeCount) {
        if (top >= 0) {
            cout << "Removed Employee No: " << top + 1 << endl;
            cout << "ID: " << s[top].id << endl;
            cout << "Name: " << s[top].name << endl;
            cout << "Salary: " << s[top].salary << endl;
            cout << "Gender: " << (s[top].gender == 'm' ? "Male" : "Female") << endl;

            int employeeIndex = top;
            memset(&s[employeeIndex], 0, sizeof(Employee));
            employeeCount--;
            top--;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    void printStack() {
        cout << "\nArray Print\n";
        cout << "------------------\n";
        for (int i = 0; i <= top; i++) {
            cout << "Element no: " << i + 1 << " = " << arr[i] << endl;
        }
    }

     // Static function to return active object count
    static int getObjectCount() {
        return objectCount;
    }

    ~Stack() {
        delete[] arr;
        std::cout << "Deleted Successfully" << std::endl;
    }
};
// Initialize static member
int Stack::objectCount = 0;

// 1. viewContent (Pass by Reference)
void viewContentByReference(Stack &stack) {
    cout << "\n[viewContentByReference] Function Called\n";
    stack.printStack();
}

// 2. viewContent (Pass by Value and Without Copy Constructor)
void viewContentByValueWithoutCopy(Stack stack) {
    cout << "\n[viewContentByValueWithoutCopy] Function Called\n";
    stack.printStack();
}

// 3. viewContent (Pass by Value and With Copy Constructor)
void viewContentByValueWithCopy(Stack stack) {
    cout << "\n[viewContentByValueWithCopy] Function Called\n";
    stack.printStack();
}




void scanEmployeeArray(Employee s[], int stackSize, Stack* stack);
void printEmployeeArray(Employee s[]);
void SetColor(int ForgC);
void gotoxy(int x, int y);
int c = 0;

int main() {
    int position = 0;
    int stackSize=0;
    Employee Employees[100];


    cout << "Welcome, Enter Number Of Stack to Start\n";
    while (true) {
        cin >> stackSize;

        if (cin.fail()|| stackSize <= 0) { /* fail detects if the input is not an integer*/
            cout << "Invalid input. Please enter a positive integer:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discards invalid input from the buffer to prevent an infinite loop.
        } else {
            break;
        }
    }
    Stack *stack = new Stack(stackSize);


    while (1) {
        system("cls");
        gotoxy(2, 4);
        if (position == 0)
            SetColor(r);
        else
            SetColor(w);
        cout << "Push\n";

        gotoxy(2, 8);
        if (position == 1)
            SetColor(r);
        else
            SetColor(w);
        cout << "Display\n";

        gotoxy(2, 12);
        if (position == 2)
            SetColor(r);
        else
            SetColor(w);
        cout << "Pop\n";

        gotoxy(2, 16);
        if (position == 3)
            SetColor(r);
        else
            SetColor(w);
        cout << "Exit\n";

        char op = getch();
        if (op == -32) {
            op = getch();
            switch (op) {
                case UP:
                case LEFT:
                    position = (position - 1 + 4) % 4;
                    break;
                case DOWN:
                case RIGHT:
                    position = (position + 1) % 4;
                    break;
            }
        } else if (op == Enter) {
            switch (position) {
                case 0: {
                    system("cls");
                    gotoxy(5, 2);
                    SetColor(w);
                    scanEmployeeArray(Employees, stackSize , stack);
                    //getch();
                    break;
                }
                case 1: {
                    system("cls");
                    gotoxy(2, 2);
                    SetColor(w);
                    cout << "Display\n";
                    printEmployeeArray(Employees);
                    getch();
                    break;
                }
                case 2: {
                    system("cls");
                    gotoxy(2, 2);
                    SetColor(w);
                    cout << "Pop from stack:\n";
                    stack->pop(Employees, c);
                    getch();
                    break;
                }
                case 3: {
                    system("cls");
                    gotoxy(2, 4);
                    SetColor(w);
                    cout << "Goodbye\n";
                    delete stack;
                    return 0;
                }
            }
        }
    }
    return 0;
}

void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void scanEmployeeArray(Employee s[], int stackSize, Stack* stack) {
    if (c == stackSize) {
        cout << "\nThe Stack Is Full :)" << endl;
        return;
    }
    for (int i = c; i < stackSize; i++) {
         while (true) {
            cout << "Enter ID [" << (c + 1) << "]\n----------------\n";
            cin >> s[c].id;

            if (cin.fail() || s[c].id <= 0) {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive integer.\n";
            } else {
                break;
            }
        }
        cin.ignore();
        bool validName = false;
        while (!validName) {
            cout << "Enter name [" << (c + 1) << "]\n----------------\n";
            getline(cin, s[c].name);

            validName = true;
            for (int j = 0; s[c].name[j] != '\0'; ++j) {
                if (!isalpha(s[c].name[j]) && s[c].name[j] != ' ') { // Check for alphabetic or space
                    validName = false;
                    cout << "Invalid name. Please use only letters and spaces.\n";
                    break;
                }
            }
        }
        while (true) {
            cout << "Enter Salary [" << (c + 1) << "]\n----------------\n";
            cin >> s[c].salary;

            if (cin.fail() || s[c].salary <= 0) {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter a positive integer.\n";
            } else {
                break; // Valid input
            }
        }
          while (true) {
            cout << "Enter Gender [" << (c + 1) << "] (m/f)\n----------------\n";
            cin >> s[c].gender;

            s[c].gender = tolower(s[c].gender); // Convert to lowercase for case-insensitivity
            if (s[c].gender == 'm' || s[c].gender == 'f') {
                break; // Valid input
            } else {
                cout << "Invalid input. Please enter 'm' or 'f' only.\n";
            }
        }

        cin.ignore();
        stack->push(s[c].id);

        c++;

        if (c == stackSize) {
            cout << "\nThe Stack Is Full :)" << endl;
            break;
        }

        cout << "\nTo stop, press ESC. Press any other button to continue\n";


        if (getch() == ESC) break;

        system("cls");
    }
}



void printEmployeeArray(Employee s[]) {
    cout << "Number of Employees: " << c << "\n";
    for (int i = 0; i < c; i++) {
        cout << "-------------- Employee " << i + 1 << " ------------\n";
        cout << "Name [" << i + 1 << "]: " << s[i].name << "\n";
        cout << "Age [" << i + 1 << "]: " << s[i].salary << "\n";
        cout << "ID [" << i + 1 << "]: " << s[i].id << "\n";
        cout << "Gender [" << i + 1 << "]: " << s[i].gender << "\n";
    }
}
