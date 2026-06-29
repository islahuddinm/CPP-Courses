/* In programming, "stack" and "heap" are two areas of memory where data can be stored during the execution of
a program. Here's a brief overview of each:


Stack: The stack is a region of memory that is used for static memory allocation and is managed by the CPU.
It is typically used to store "local variables," "function calls," and "return addresses".
stack memory doesnt grow while the application/program is running. if data size grows beyond the memory
allocation, it would be error.

"function call" is an action in your program where you invoke or "call" a specific function to execute its code.
It's the mechanism by which your program can perform a task defined in a separate block of code.
"function call" can involve variables or data, which are typically passed to the function as arguments.

"return address" is a critical piece of information used during function calls in a program. It tells
the program where to resume execution after a function finishes its work.

When a function is called, space is allocated on the stack for these items, and when
the function returns, that space is freed. The stack operates in a Last In, First Out (LIFO) manner,
meaning that the last item added to the stack is the first one removed.

"the main function itself is not allocated in stack memory, just local variables, function calls,
and return addresses."


Heap: The heap is a region of memory that is used for dynamic memory allocation. Unlike the stack, which has
a fixed size determined at compile time, the heap is more flexible and can grow or shrink as needed during
the execution of a program. Memory allocated on the heap remains allocated until it is explicitly deallocated
by the program, typically using functions like malloc (in C) or new (in C++) to use heap memory.
Because the heap is more flexible, it can be slower to allocate and deallocate memory on the heap compared to
the stack.

    heap memory can grow while the application/program is running.

    Elements utilizes the memory heap:

        1. Explicit Dynamic Allocations (Raw Pointers)

            int* ptr = new int;          // 'ptr' is on the stack; the integer it points to is on the heap
            int* arr = new int[100];     // Dynamic array allocated on the heap

        2. Standard Template Library (STL) Containers

            - Dynamic Arrays & Strings: std::vector and std::string.
            - Node-Based Containers: std::list, std::forward_list, std::map, std::set, std::multimap, and std::multiset.
            - Hash Tables: std::unordered_map and std::unordered_set.
            - Container Adapters: std::deque, std::queue, and std::stack

                #include <vector>
                void example() {
                    std::vector<int> vec; 
                    vec.push_back(10); // 'vec' control structure is on the stack.
                                    // The element '10' is allocated inside a heap-managed buffer.
                }
        
        3. Smart Pointers

            - std::unique_ptr: Owns a unique resource on the heap.
            - std::shared_ptr: Owns a shared resource on the heap (and creates a "control block" on the heap to track the reference count).
            - std::weak_ptr: Non-owning observer of a std::shared_ptr heap resource.

                #include <memory>
                auto smartPtr = std::make_unique<MyClass>(); // Safely allocates MyClass on the heap

        4. Polymorphic Objects & Abstract Classes

            base pointers (Base*) or references point to instances of derived classes stored on the heap to ensure
            virtual functions trigger correctly at runtime.

                Base* polyObject = new Derived(); // Safeguards derived data structures on the heap

        Summary Reference Table

            | Element Type                       | Where Container/Pointer Lives               | Where Actual Elements/Data Live          |
            | ---------------------------------- | ------------------------------------------- | ---------------------------------------- |
            | Raw Pointer Variables (`int* p`)   | Stack, or data segment if global            | Heap                                     |
            | STL Vector (`std::vector<T>`)      | Stack as a local variable                   | Heap, inside the internal storage buffer |
            | Standard String (`std::string`)    | Stack, subject to Short String Optimization | Heap for long or dynamic text strings    |
            | Smart Pointers (`std::unique_ptr`) | Stack, acting as an automated manager       | Heap                                     |

    Keywords used for memory heap in c++:

        Native C++ Keywords:
            
            - new: Allocates memory on the heap for an object or array and returns a pointer to it.
            - delete: Deallocates memory previously allocated by new to prevent memory leaks.
            - new[]: Allocates memory for an array on the heap.
            - delete[]: Deallocates memory allocated for an array by new[].

        Legacy C-Style Heap Functions:

            - malloc(): Allocates a specified number of bytes on the heap.
            - calloc(): Allocates memory for an array on the heap and initializes all bytes to zero.
            - realloc(): Resizes previously allocated heap memory blocks.
            - free(): Deallocates memory allocated by malloc, calloc, or realloc

        Modern C++ Alternatives:

            - std::make_unique: Safely allocates a single object on the heap using a unique smart pointer.
            - std::make_shared: Safely allocates an object on the heap using a shared smart pointer.
            - std::vector: A standard container that dynamically manages its internal array on the heap automatically


In summary, the stack is used for static memory allocation and manages function call information,
while the heap is used for dynamic memory allocation and allows for more flexible memory management.*/