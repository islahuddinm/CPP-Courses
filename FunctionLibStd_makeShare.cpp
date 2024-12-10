/*

std::make_shared() is a function that creates and returns a shared pointer (std::shared_ptr) and
wrap to the std::shared_ptr object of specific type after dynamically creating it.

std::shared_ptr essentially "wraps" the raw pointer (int*) to the object,
providing smart memory management capabilities.

std::shared_ptr is a smart pointer that manages the lifetime of a dynamically allocated object
using shared ownership. "Managing the lifetime of dynamically allocated objects" means
controlling when these objects are created and destroyed in memory to ensure proper resource usage and
to avoid issues like memory leaks, dangling pointers, or double deletions.

    What Happens During the Lifetime of an Object?
        1. Creation:
        A dynamically allocated object is created using operators like new or memory allocation functions
        like malloc. This allocates memory for the object on the heap. For example:

            cpp example
            
            int* ptr = new int(10); // Dynamically allocate an integer

        2. Usage:
        The object exists in memory and can be accessed or modified through a pointer during its lifetime.

        3. Destruction:
        The memory allocated to the object must be explicitly freed (e.g., using delete) to
        return it to the system. For example:

            cpp example

            delete ptr; // Free memory

    Why Managing Lifetime is Important?    
        1. Prevent Memory Leaks:
        If memory is allocated dynamically but not freed, it remains unusable until the program exits,
        leading to memory leaks. Example:

            cpp example
            
            int* ptr = new int(42);
            // Forgot to delete ptr
        
        2. Avoid Dangling(Teruntai) Pointers:
        If memory is freed while a pointer still points to it, dereferencing the pointer results in
        undefined behavior. Example:

            cpp example
            
            int* ptr = new int(42);
            delete ptr; // Memory is freed
            *ptr = 10;  // Undefined behavior (dangling pointer)
        
        3. Prevent Double Deletion:
        Deleting the same memory twice results in undefined behavior. Example:

            cpp example
            
            int* ptr = new int(42);
            delete ptr;
            delete ptr; // Error: Double deletion

    How std::shared_ptr Helps?
        std::shared_ptr manages the lifetime of a dynamically allocated object by:

        1. Automatically deleting the object when no longer needed.
        2. Using reference counting to determine when an object can be safely destroyed.
        
        With std::shared_ptr, you don't have to explicitly call delete for the object,
        as it is handled internally when the last std::shared_ptr sharing ownership of the object is destroyed.

        Example below:

*/

#include <memory>
#include <iostream>

int main() {
    
    {
        std::shared_ptr<int> sp = std::make_shared<int>(42); // Memory allocated
        std::cout << "Value: " << *sp << "\n";
    } // `std::shared_ptr` automatically deletes the object here
    
    std::cout << "Object destroyed automatically\n";
    
    return 0;
}

/*

Example: Custom Class

    #include <iostream>
    #include <memory>

    class MyClass {
    public:
        MyClass(int x, int y) : a(x), b(y) {
            std::cout << "MyClass constructed\n";
        }
        void print() {
            std::cout << "a: " << a << ", b: " << b << std::endl;
        }

    private:
        int a, b;
    };

    int main() {
        auto sp = std::make_shared<MyClass>(10, 20); // Create a shared_ptr for MyClass
        sp->print(); // Access MyClass methods using shared_ptr
        return 0;
    }

Example: new + std::shared_ptr

    std::shared_ptr<int> sp(new int(42)); // Explicit use of new

Example: std::make_shared

    auto sp = std::make_shared<int>(42); // Cleaner and safer

Example in array:

    // This is pointer
    employee *collection[] = {&employee1, &employee2, &employee3};
    
    // This is smart pointer
    std::shared_ptr<employee> collection = {std::make_shared<employee1>("Mike", "Amazon", 26),
                                            std::make_shared<employee2>("Sandrina", "Amazon", 32, "Math")};
    for (employee *ref : collection) {
        ref->working();
    }

*/
