/*

BEFORE YOU TRY TO UNDERSTANDING THIS, YOU HAVE TO UNDERSTAND "std::make_shared"!!!

std::make_unique is a utility function in C++ that creates and returns a std::unique_ptr.
It was introduced in C++14 to simplify and enhance the creation of std::unique_ptr objects.

std::unique_ptr is a smart pointer introduced in C++11. It automatically manages
the dynamically allocated resources on the heap.

Using make_unique() doesn't impact performance, but make_shared() improves it slightly.
Indeed, constructing explicitly a shared_ptr() requires two heap allocations: one for the managed object and
the other for the control block that stores data about the ref-counts and the shared_ptr() deleter.
So "std::make_unique:" slightly faster because it doesn’t require managing reference counts.
Uses less memory since there is no control block.

*/

#include <iostream>
#include <memory>

int main() {
    
    // We can also use "auto".
    //auto up = std::make_unique<int>(42);
    std::unique_ptr<int> up = std::make_unique<int>(42); // Create a unique_ptr managing an integer
    
    std::cout << "Value: " << *up << std::endl; // Access the value through unique_ptr
    
    return 0;
}

/*

class MyClass {
public:
    MyClass(int x, int y) : a(x), b(y) {
        std::cout << "MyClass constructed\n";
    }
    void print() const {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }

private:
    int a, b;
};

int main() {
    
    auto up = std::make_unique<MyClass>(10, 20); // Create a unique_ptr for MyClass
    up->print(); // Access MyClass methods using unique_ptr
    
    return 0;
}

*/