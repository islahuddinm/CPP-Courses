

/*

Alokasi = proses penentuan jatahan (seperti barang, uang, sumber daya, atau kuota).

    Memory allocation = the process of reserving(mencadangkan) a portion(sebagian) of memory for a program to store data.
    In simple terms, when a program needs memory to store information, some memory space must be made available for that data.

    Example of Memory Allocation:

        Imagine you write this C++ code:

            int main() {
                int age = 20;
                return 0;
            }

        When the program runs, the variable age needs memory to store the value 20.
        Assume an int occupies 4 bytes on your computer. The program needs 4 bytes of storage for that integer.
        
        Illustraion:
        
            BEFORE ALLOCATION

                Memory
                +----------+------------------+
                | Address  | Status           |
                +----------+------------------+
                | 0x1000   | Available        |
                | 0x1001   | Available        |
                | 0x1002   | Available        |
                | 0x1003   | Available        |
                +----------+------------------+

            AFTER ALLOCATION

                Memory
                +----------+------------------+
                | Address  | Status           |
                +----------+------------------+
                | 0x1000   | Allocated        |
                | 0x1001   | Allocated        |
                | 0x1002   | Allocated        |
                | 0x1003   | Allocated        |
                +----------+------------------+

                These 4 bytes can store the integer 20.

            This is a simplified illustration. A compiler may store age in a CPU register or
            optimize it away instead of allocating stack memory.

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

            Conclusion:

                - Automatically disappear: The program automatically ends a variable's lifetime and can reuse its memory.
                - Not automatically disappear: The allocation stays allocated until something releases it.
                - Function finishes: The function completes execution and control returns to its caller.

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

    Stack memory = an area of memory used by a running program to manage function calls and typically store local variables.

        What is stack memory used for?

            Stack memory commonly stores:

                | Data                | Description                                                           |
                | ------------------- | --------------------------------------------------------------------- |
                | Local variables     | Variables declared inside a function                                  |
                | Function parameters | Values passed to a function                                           |
                | Return addresses    | Addresses telling the CPU where to continue after a function finishes |
                | Saved registers     | CPU register values that need to be preserved                         |
                | Temporary data      | Additional data needed while executing a function                     |

            Not every local variable or parameter is physically stored on the stack.
            The compiler may use CPU registers instead.

        How does stack memory work?

            Consider this C++ program:

                void example() {
                    int a = 10;
                    int b = 20;
                }

                int main() {
                    example();
                    return 0;
                }

            Let's examine what happens:

                Step 1: The program starts `main()`. The program creates a stack frame for `main()`.
                Step 2: `main()` calls `example()`. The program creates another stack frame for `example()`.
                Step 3: `example()` executes.

                    STACK MEMORY
                    +------------------------+
                    | example() Stack Frame  |
                    |                        |
                    | a = 10                 |
                    | b = 20                 |
                    +------------------------+
                    | main() Stack Frame     |
                    +------------------------+

                Step 4: `example()` finishes.

                    The stack frame belonging to `example()` is removed automatically.

                    STACK MEMORY
                    +------------------------+
                    | Available stack space  |
                    +------------------------+
                    | main() Stack Frame     |
                    +------------------------+

                Step 5: `main()` continues. The program executes `return 0;` and finishes.

        What is a stack frame?

            A stack frame is an area of stack memory associated with a particular function call.

            For example:

                </> c++
                
                    void functionA() {
                        int a = 10;
                    }

                    void functionB() {
                        int b = 20;
                        functionA();
                    }

                    int main() {
                        functionB();
                        return 0;
                    }

                While functionA() is running, the stack conceptually looks like this:

                                STACK
                    +---------------------------+
                    | functionA() Stack Frame   | <- Top
                    | a = 10                    |
                    +---------------------------+
                    | functionB() Stack Frame   |
                    | b = 20                    |
                    +---------------------------+
                    | main() Stack Frame        |
                    +---------------------------+

                The stack follows a principle called LIFO (Last In, First Out).

                    That means:

                        - functionA() was called last, so it normally finishes first.
                        - functionB() finishes afterward.
                        - main() finishes last.

        What happens to stack memory when a function finishes?

            When a function returns, its stack frame is normally removed automatically.

            For example:

                </> c++
                
                    void example() {
                        int age = 20;
                    }

                    int main() {
                        example();
                        return 0;
                    }


                While example() is running, age exists.
                After example() finishes, age no longer exists, and its storage can be reused.

                This does not mean the computer immediately changes all the bits in that memory to zero.
                It means that the memory is no longer reserved(disimpan/dicadangkan) for that function's stack frame.

        Where is stack memory located?

            Stack memory is not a separate physical device.
            It is typically part of a running program's virtual memory, backed by RAM as needed.

            Illustration:
            
                COMPUTER
                    |
                    v
                RAM
                    |
                    v
                Running Program
                    |
                    +---- Program Instructions
                    |
                    +---- Global / Static Data
                    |
                    +---- Stack Memory
                    |        |
                    |        +---- Function Calls
                    |        +---- Local Variables
                    |        +---- Return Addresses
                    |
                    +---- Heap Memory
                                |
                                +---- Dynamic Allocations

    Stack memory vs. heap memory

        | Feature      | Stack Memory                                 | Heap Memory                         |
        | ------------ | -------------------------------------------- | ----------------------------------- |
        | Purpose      | Function calls and automatic local data      | Dynamic allocations                 |
        | Allocation   | Usually automatic                            | Requested during execution          |
        | Deallocation | Usually automatic                            | Managed separately                  |
        | Lifetime     | Normally tied to function execution or scope | Can outlive the allocating function |
        | Example      | `int a = 10;`                                | `int* p = new int(20);`             |

    For this case, why do i need heap memory if i can use stack memory?

        Exampe, case:
        
            int main() {
                int* p = new int(20);
                delete p;
                return 0;
            }

            or

            int main() {
                int p = 20;
                return 0;
            }

        For this case, you do not need heap memory. Using an ordinary local variable is simpler and generally better.
        So your reasoning is correct: for these two programs, heap allocation provides no useful advantage.

    Why do we need a heap memory?

        We need heap memory because programs sometimes need to store data whose(yang) size or
        lifetime(masa hidupnya) cannot be conveniently(dengan mudah) determined(ditentukan) "in advance (sebelumnya)".
        Stack memory is useful for local variables and function calls, but it has limitations.
        Heap memory provides more flexibility.

        The reasons we need Heap Memory:

            1. Problem: Stack Memory Has a Limited Size

                Imagine you want to store 1,000,000 integers.

                int main() {
                    int numbers[1000000];
                    return 0;
                }

                If each integer occupies 4 bytes, the array needs approximately 4 MB of memory.
                On some systems, this may exceed(melampaui) the available stack space and cause a stack overflow.
                Heap memory is generally better suited for large dynamic allocations.

            2. Solution: Use Heap Memory
            
                int main() {
                    int* numbers = new int[1000000];

                    delete[] numbers;
                    return 0;
                }

                Here:

                    1. new int[1000000] requests heap memory for 1,000,000 integers.
                    2. numbers stores the address of the first integer.
                    3. The program can access the allocated array.
                    4. delete[] numbers releases the allocated memory.
                
                Illustration:

                    STACK MEMORY                  HEAP MEMORY
                    +------------------+          +---------------------+
                    | numbers          |          | Integer 0           |
                    |                  |          | Integer 1           |
                    | Address: 0x5000  |--------->| Integer 2           |
                    +------------------+          | ...                 |
                                                  | Integer 999999      |
                                                  +---------------------+

                    The addresses are illustrative.

            3. Problem: We Don't Always Know How Much Memory We Need

                Imagine a program asks the user how many numbers they want to store.

                The user might enter:

                    - 10 numbers
                    - 100 numbers
                    - 100,000 numbers

                We cannot know the requested number before the program runs.
                Heap memory allows us to allocate an amount based on the user's input.

                For example:

                    </> c++
                    
                        #include <iostream>
                        using namespace std;

                        int main() {
                            int n;

                            cout << "How many numbers? ";
                            cin >> n;

                            if (n <= 0) {
                                return 1;
                            }

                            int* numbers = new int[n];

                            cout << "Memory allocated!" << endl;

                            delete[] numbers;
                            return 0;
                        }
                    
                    if the user enters 100, the program requests enough heap memory for 100 integers.
                    If the user enters 1000, the program requests enough for 1,000 integers.

                Important:
                
                    The ability to handle runtime sizes is not exclusive to manually allocating heap memory.
                    Modern C++ commonly uses std::vector, which manages dynamic storage automatically.

            4. Problem: Data Sometimes Needs to Survive After a Function Finishes

                Consider this example:

                    int* createNumber() {
                        int* p = new int(20);
                        return p;
                    }

                    int main() {
                        int* number = createNumber();

                        // The allocated integer still exists here.
                        std::cout << *number;

                        delete number;
                        return 0;
                    }

                When createNumber() finishes, its local pointer p stops existing.
                However, the heap allocation containing 20 remains available through the pointer returned to main().
                This lets the data survive beyond the function that created it.

            5. Do We Always Need to Use new?

                No. Modern C++ usually provides safer ways to use heap memory.

                For example:

                    #include <vector>
                    using namespace std;

                    int main() {
                        vector<int> numbers(1000000);

                        return 0;
                    }

                std::vector normally allocates its elements on the heap and automatically releases that storage
                when the vector is destroyed. You do not need to manually write delete[].

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