/*

The explicit keyword in C++ is used to prevent implicit type conversions for constructors or
conversion operators. It ensures that an object cannot be implicitly created or converted when
an argument of a different type is passed.

Explanation:
1. Without explicit, the constructor "File(int id)" can be used for implicit conversion, like "File f2 = 10;".
    - Constructor is Invoked:
        The compiler sees "File f2 = 10;" and checks if it can create a object of "File" class using
        the constructor "File(int id)".

    - Implicit Conversion:
        In "File f2 = 10;", the syntax resembles(menyerupai) assignment, but it is actually a request
        for the compiler to perform an implicit conversion from an "int" to a "File" object by
        calling the constructor. This behavior can lead to subtle bugs if
        unintended(tidak disengaja) conversions happen (e.g., accidentally passing the wrong type).

2. Adding explicit prevents unintended(tidak dimaksud) implicit conversions,
improving code safety and clarity.

Why explicit Blocks This:
The explicit keyword tells the compiler not to allow such implicit conversions. If you try
"File f2 = 10;" when the constructor is marked "explicit", the compiler will produce an error,
preventing unintended behavior.

*/

#include <iostream>
using namespace std;

class File {
public:
    explicit File(int id) { // This is custom constructor.
        cout << "File created with ID: " << id << endl;
    }
};

int main() {

    File f1(10);  // This works fine.
    File f2 = 10; // Error: Conversion from "int" to "File" is not allowed.
    // The error means it try to comvert "int" to "File" with try to calling the constructor.

    return 0;
}
