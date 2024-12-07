#include <iostream>
using namespace std;


typedef struct Slice {
    int start;
    int end;
    int counter;
} Slice;

class List {
private:
    int len;
    int* items;

public:
    List() : len(0), items(nullptr) {}

    void listPush(int num) {
        int* temp = items;
        items = new int[++len];
        for (int i = 0; i < len - 1; i++) {
            items[i] = temp[i];
        }
        items[len - 1] = num;
        delete[] temp;
    }

    int listPop(int& value) {
        if (len == 0) return false;
        value = items[--len];
        int* temp = items;
        items = new int[len];
        for (int i = 0; i < len; i++) {
            items[i] = temp[i];
        }
        delete[] temp;
        return true;
    }

    void listDisplay() const {
        for (int i = 0; i < len; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    bool operator==(const List& l) const {
        if (len != l.len) return false;
        for (int i = 0; i < len; i++) {
            if (items[i] != l.items[i]) return false;
        }
        return true;
    }

    void operator[](Slice s) const {
        if (s.end <= len) {
            for (int i = s.start; i < s.end; i += s.counter) {
                cout << items[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Slice out of range" << endl;
        }
    }

    void operator=(const List& l) {
        delete[] items;
        items = new int[l.len];
        for (int i = 0; i < l.len; i++) {
            items[i] = l.items[i];
        }
        len = l.len;
    }

    ~List() {
        delete[] items;
    }
};

int main() {
    List l1, l2;

    l1.listPush(60);
    l1.listPush(50);
    l1.listPush(70);
    l1.listPush(80);

    // Display elements
    cout << "List 1: ";
    l1.listDisplay();

    // Slicing
    Slice s = {1, 4, 2};  // Create a Slice object
    l1[s];

    return 0;
}
