#include <iostream>
using namespace std;

class Example {
public:
    void displayNumbers(int n) {
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
            if (i % 5 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }

    void checkNumber(int num) {
        if (num > 0) {
            cout << num << " is positive." << endl;
        } else if (num < 0) {
            cout << num << " is negative." << endl;
        } else {
            cout << num << " is zero." << endl;
        }
    }
};

int main() {
    Example example;
    example.displayNumbers(10);
    example.checkNumber(5);
    example.checkNumber(-3);
    example.checkNumber(0);

    return 0;
}
