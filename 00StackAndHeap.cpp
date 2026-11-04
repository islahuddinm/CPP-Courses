

/*

Alokasi = proses penentuan jatahan (seperti barang, uang, sumber daya, atau kuota).

First, what is memory?

    When you run a program, your computer needs somewhere to temporarily store data.

    For example, imagine this C++ program:
    
        int main() {
            int age = 20;
            return 0;
        }

    The variable age contains the value 20. Your computer needs memory to store that value while the program runs.
    That memory is usually provided by RAM.

Stack and Heap:

    Stack and Heap are two areas of memory that a running program typically uses to store data.
    or "stack" and "heap" are two areas of memory where data can be stored during the execution of a program.
    
    The main difference of both is how memory is allocated, managed, and released.

    Heap memory = an area of memory where a program can request storage dynamically while it is running.
    In C++, you can request heap memory. Unlike a normal stack allocation, heap memory does not automatically disappear
    when the function that requested it finishes. Its lifetime is controlled by memory management.

        How to request heap memory?

            Example, request Heap Memory using the new operator:

                </> c++

                    int* p = new int(20);

                Step 1: Request memory

                    </> c++
                    
                        new int(20);

                    When the CPU executes the compiled program, the new operation causes the program
                    to use a memory allocator.

                    The allocator:

                        1. Looks for available memory that can hold an integer.
                        2. Reserves(menyimpan/mencadangkan) that memory for your program.
                        3. Initializes the integer with 20.
                        4. Returns the memory address.

                        For example, imagine the allocator returns address 0x5000.

                            Heap Memory

                                Address        Value
                                +------------+-------+
                                | 0x5000     |  20   |
                                +------------+-------+

                            The address is just an example. Real addresses are chosen by the system.

                Step 2: Store the address in a pointer

                    </> c++
                    
                        int* p = new int(20);

                    The pointer p stores the address of the allocated integer.

                        STACK                       HEAP
                        +-------------+            +-------------+
                        | p           |            |             |
                        |             |            |             |
                        | 0x5000      |----------->| 20          |
                        |             |            |             |
                        +-------------+            +-------------+

                                                    Address:
                                                    0x5000

                    The pointer variable p is typically stored on the stack because it is a local variable.
                    The integer 20 created using new is stored on the heap.

                Step 3: Access the value

                    </> c++

                        cout << *p;

                    *p means: access the integer located at the address stored in p.

                Step 4: Release heap memory

                    </> c++
                    
                        // Release heap memory
                        delete p;
                        p = nullptr;

                    The delete operator releases the dynamically allocated integer.
                    Once released, the memory can be reused by the memory allocator.
                    p still exists until its own lifetime ends, but its old address must no longer be dereferenced.
                    You can set p = nullptr; after deleting it to avoid accidentally using the old address.

            Example, When you run the program:

                The operating system starts the program and provides it with a virtual address space.

                When the program reaches:

                    </> c++
                    
                        int* p = new int(20);

                    It requests memory through the heap allocator.

                    Assuming int occupies 4 bytes:

                        BEFORE new int(20)

                            HEAP
                            +----------------------+
                            | Available memory     |
                            +----------------------+


                        AFTER new int(20)

                            HEAP
                            +----------------------+
                            | Allocated: 4 bytes   |
                            | Value: 20            |
                            +----------------------+
                            | Available memory     |
                            +----------------------+

        What does "automatically disappear" mean?
            
            In programming, automatically disappear means that the program automatically ends
            the lifetime(masa hidupnya) of some data and makes its memory available for reuse,
            without you explicitly requesting deallocation.

            For example:

                </> c++
                
                    void example() {
                        int a = 10;
                    }

                    int main() {
                        example();
                        return 0;
                    }

                Here's what happens:

                    Step 1: main() calls example().
                    Step 2: example() starts running.
                    Step 3: The variable a is created with value 10.
                    Step 4: example() finishes running.
                    Step 5: The variable a automatically stops existing. Its stack space can be reused.

                    Illustration:

                        WHILE example() IS RUNNING

                            Stack Memory
                            +--------------------+
                            | a = 10             |
                            +--------------------+


                        AFTER example() FINISHES

                            Stack Memory
                            +--------------------+
                            | Space available    |
                            | for reuse          |
                            +--------------------+

                        You do not need to write "delete a;".

        What does "not automatically disappear" mean?

            It means the allocated memory remains(tetap) allocated(teralokasi) until it is explicitly released or
            managed by an ownership mechanism.

            Example:

                </> c++
                
                    void example() {
                        int* p = new int(20);
                    }

                    int main() {
                        example();
                        return 0;
                    }

                Here's what happens:

                    Step 1: main() calls example().
                    Step 2: example() starts running.
                    Step 3: new int(20) allocates heap memory.
                    Step 4: The pointer p stores the address of that heap memory.
                    Step 5: example() finishes running.
                    Step 6: The local pointer p automatically stops existing, but the heap allocation remains allocated.

                Illustration:
                
                    WHILE example() IS RUNNING

                        STACK                      HEAP
                        +--------------+           +--------------+
                        | p = 0x5000   |---------->| 20           |
                        +--------------+           +--------------+


                    AFTER example() FINISHES

                        STACK                      HEAP
                        +--------------+           +--------------+
                        | p no longer  |           | 20           |
                        | exists       |           | Still        |
                        |              |           | allocated    |
                        +--------------+           +--------------+

                    Because the pointer is lost(hilang), the program can no longer release(melepaskan) that allocation normally.
                    This is called a memory leak. To avoid that, you can write "delete p;" or use modern C++ automatic ownership tools.
                    The pointer variable p is typically stored on the stack because it is a local variable.

        What does "when the function that requested it finishes" mean?

            A function finishes when it completes its execution and returns control to the function that called it.

            For example:
            
                void example() {
                    int a = 10;
                    // Function finishes here
                }

                int main() {
                    example();

                    // Program continues here

                    return 0;
                }

        When i write codes by using a heap request like this:

            int main() {

                int* p = new int(20);
                delete p;

                return 0;
            }

            It means it would have a less size of the program when the program is compiled
            but the program size would be growing when i am running the program?

                You're partially correct! The important thing is that program file size and
                program memory usage are two different things.

                A more accurate statement is:

                    When I compile my C++ program, the executable contains instructions for allocating heap memory.
                    When I run the program, those instructions can cause the program's memory usage to increase.
                    However, the executable file size itself does not increase.


What is a definiton of automatically disappear?

"when the function that requested it finishes"
what does finish mean?

What is memory allocation

*/


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