#include <iostream>

using std::cout;
using std::endl;

int main() {

// copy of its value
    int var = 10; // sizeof(var) = usually 4 bytes
    int a = var; // sizeof(p) = usually 4 bytes

    var = 20;

    cout << var << endl;  // 20
    cout << a << endl;    // 10

// pointer is used to refer to the same object, not a copy of its value
    int y = 10; // sizeof(var) = usually 4 bytes
    int* p = &y; // sizeof(*p) = usually 8 bytes on 64-bit systems (*p is not an int. p is an int*, a pointer that stores an address.)

    y = 20;

    cout << y << endl;  // 20
    cout << p << endl;    // 20

// reference
    int x = 1;
    int& ref = x;

    x = 0;

    cout << x << endl;
    cout << ref << endl;

// the pointer is not used to allocate memory. The "new" operator allocates the memory.
    int* pp = new int; // Allocate memory for an integer on the heap(memory stock have not been used).   
    *pp = 42; // Assigning a value to the allocated memory by 'new int;' then the value(42) is placed to the allocated memory.
    // we can also assign like this 'int* p = new int(42);' instead of above.

    int n = 5;
    // Allocate an array of 5 ints at runtime
    int* arr = new int[n];

    std::cin >> arr[0];

    // Store values in the allocated memory
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    // Print the values
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    // Print the address stored in arr
    cout << "\nAddress stored in arr: " << arr << endl;

    // Free the allocated memory
    delete[] arr;

    /*
    Example, suppose new returns address 1000:

        | Stack Memory      | Heap Memory    |
        |-------------------|----------------|
        | arr -----> 1000   | 1000 : arr[0]  |
        |                   | 1004 : arr[1]  |
        |                   | 1008 : arr[2]  |
        |                   | 1012 : arr[3]  |
        |                   | 1016 : arr[4]  |
    */

    return 0;
}