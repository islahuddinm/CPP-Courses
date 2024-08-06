/* 

The [] in a lambda function in C++ is known as the capture clause. It allows the lambda function to
capture variables from the surrounding scope so they can be used within the lambda's body.

Here’s what each possible capture mode inside the [] can do:

[]: An empty capture clause, meaning the lambda does not capture any variables from the surrounding scope.
[=]: Captures all variables used in the lambda by value.
[&]: Captures all variables used in the lambda by reference.
[x]: Captures only the variable x by value.
[&x]: Captures only the variable x by reference.
[=, &x]: Captures all variables by value, but captures x by reference.
[&, x]: Captures all variables by reference, but captures x by value.

[]: The capture clause is used to capture variables from the surrounding scope that the lambda might need to
access.

(int x, int y): This is the parameter list, just like in a regular function, where x and y are
the parameters passed to the lambda function.

{ return x + y; }: The function body, which performs the operation (in this case, adding the two parameters)
and returns the result.

Capture by Value ([=]):
- Makes a copy of the captured variables.
- Changes inside the lambda do not affect the original variables.
- Safe for read-only operations on captured variables.
- Capturing by value creates a new copy of the variable, which is stored at a different memory address
from the original variable.

Capture by Reference ([&]):
- Works with the original variables, not copies.
- Changes inside the lambda do affect the original variables.
- Suitable for operations where the lambda needs to modify or update variables in the surrounding scope.
- Capturing by value does not creates a new copy of the variable, which refer to the same location in memory.
No new memory is allocated for the variable when captured by reference.

*/

#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    // Example 1: No capture
    auto no_capture = []() {
        std::cout << "No variables captured!" << std::endl;
    };
    no_capture();

    // Example 2: Capture by value
    auto capture_by_value = [a]() {
        std::cout << "Captured by value: a = " << a << std::endl;
    };
    capture_by_value();

    // Example 3: Capture by reference
    auto capture_by_reference = [&b]() {
        b = 30; // modifying b
        std::cout << "Captured by reference: b = " << b << std::endl;
    };
    capture_by_reference();
    std::cout << "After lambda execution, b = " << b << std::endl;

    // Example 4: Capture all by value
    auto capture_all_by_value = [=]() {
        std::cout << "Captured all by value: a = " << a << ", b = " << b << std::endl;
    };
    capture_all_by_value();

    // Example 5: Capture all by reference
    auto capture_all_by_reference = [&]() {
        a = 15; // modifying a
        b = 25; // modifying b
        std::cout << "Captured all by reference: a = " << a << ", b = " << b << std::endl;
    };
    capture_all_by_reference();
    std::cout << "After lambda execution, a = " << a << ", b = " << b << std::endl;

    // Example 6: Capture a by value and b by reference
    auto mixed_capture = [=, &b]() {
        std::cout << "a captured by value: a = " << a << std::endl;
        b = 35; // modifying b
        std::cout << "b captured by reference: b = " << b << std::endl;
    };
    mixed_capture();
    std::cout << "After lambda execution, b = " << b << std::endl;

    return 0;
}
