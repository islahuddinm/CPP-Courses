

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


        Stack Memory

            • What it is: A region of memory that operates in a Last-In, First-Out (LIFO) structure, much like a stack of plates or books.
            • What it stores: Local variables, function parameters, and return addresses for active function calls.
            • How it works: When a function is called, a block of memory (a "stack frame") is pushed onto the stack. When the function finishes, that block is automatically popped off and the memory is freed.
            • Key Characteristics:
                • Speed: Very fast to access and allocate (just moving a stack pointer).
                • Size: Limited and fixed in size (per thread, often around 1 MB).
                • Management: Automatic; you do not need to manually allocate or delete stack memory.
                • Risk: Stack overflow, which happens if a program uses too much stack space, such as through infinite recursion.

        Heap Memory

            • What it is: A large, flexible pool of memory used for dynamic memory allocation.
            • What it stores: Objects, large data structures, strings, or any data whose size is not known at compile time or that needs to outlive the function that created it.
            • How it works: You explicitly request memory at runtime (using keywords like new or functions like malloc), and you receive a pointer or reference to that memory stored on the stack.
            • Key Characteristics:
                • Speed: Slower to allocate and access than the stack due to lookup overhead and pointer dereferencing.
                • Size: Vastly larger, limited mostly by total system RAM or virtual memory.
                • Management: Depends on the language. In languages like C/C++, you must manually free the memory (delete or free). In languages like Java or Python, an automatic Garbage Collector cleans up unreferenced objects.
                • Risk: Memory leaks (if manual memory is never freed) or fragmentation (free memory breaking into small, scattered blocks).

        Quick Comparison:

            Feature	      |  Stack Memory	                          |  Heap Memory
            ------------------------------------------------------------------------------------------------------------------
            Structure	  |  LIFO (Last-In,                           |  First-Out)	Unordered / Dynamic pool
            Speed	      |  Fast	                                  |  Slower
            Lifetime	  |  Tied to the scope of the function/block  |	 Persistent until explicitly freed or garbage-collected
            Size Limit	  |  Small / Fixed	                          |  Large / Flexible
            Main Danger	  |  Stack overflow	                          |  Memory leaks / fragmentation

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

    Pass by pointer & pass by reference are they using dynamic memory allocation?

        No. Pass by pointer and pass by reference do not automatically use dynamic memory allocation (heap memory).
        Both are ways to allow a function to access an existing variable without copying its value.

        Let's compare them:

            1. Pass by Pointer

                </> c++

                    #include <iostream>
                    using namespace std;

                    void change(int* p) {
                        *p = 50;
                    }

                    int main() {
                        int a = 20;

                        change(&a);

                        cout << a;  // Output: 50
                        return 0;
                    }

                What happens?

                    1. int a = 20; creates a local variable, typically stored on the stack.
                    2. &a obtains the memory address of a.
                    3. change(&a) passes that address to the function.
                    4. int* p receives the address.
                    5. *p = 50; changes the value stored at that address.

                Illustration:

                    MAIN FUNCTION                 CHANGE FUNCTION

                    STACK MEMORY                 STACK / REGISTER
                    +----------------+           +----------------+
                    | a = 20         |<----------| p              |
                    | Address: 0x100 |           | Value: 0x100   |
                    +----------------+           +----------------+

                    After *p = 50:

                    a = 50

                No heap allocation is required.

            2. Pass by Reference

                </> c++
                
                    #include <iostream>
                    using namespace std;

                    void change(int& ref) {
                        ref = 50;
                    }

                    int main() {
                        int a = 20;

                        change(a);

                        cout << a;  // Output: 50
                        return 0;
                    }

                What happens?

                    1. int a = 20; creates a local variable.
                    2. change(a) passes a by reference.
                    3. int& ref becomes another name for the existing variable a.
                    4. ref = 50; changes a directly.

                Illustration:
                
                    STACK MEMORY
                    +----------------------+
                    | Variable: a          |
                    | Value: 20            |
                    +----------------------+
                            ^
                            |
                    ref refers to a
                            |
                            v
                        ref = 50

                    Result: a = 50

                Again, no heap allocation is required.

            3. When Does Dynamic Memory Allocation Happen?

                Dynamic memory allocation occurs when you explicitly request it, such as by using new, or
                when a library or container requests it internally.

                For example:

                    int main() {
                        int* p = new int(20);

                        delete p;
                        return 0;
                    }

                Here, new int(20) requests heap memory.

            4. Can Pointers and References Access Heap Memory?

                Yes! Both pointers and references can access data stored on the heap.

                </> c++
                
                    #include <iostream>
                    using namespace std;

                    void change(int& ref) {
                        ref = 50;
                    }

                    int main() {
                        int* p = new int(20);

                        change(*p);

                        cout << *p;  // Output: 50

                        delete p;
                        return 0;
                    }

                In this example:

                    - new int(20) dynamically allocates an integer on the heap.
                    - p stores its address.
                    - change(*p) passes that heap-allocated integer by reference.
                    - ref = 50 changes its value.
                    - delete p releases the heap allocation.
                    
                The reference does not allocate heap memory. The new expression does.

    When do i use the heap memory, other than for containers?

        You can use heap memory for individual objects, not just containers or arrays.
        Heap memory is particularly useful when you need to control an object's lifetime, store large objects, or
        create different kinds of objects while a program is running.

        1. Example: Creating an enemy in a game

            Imagine you're developing a game using C++.
            An enemy can appear while the game runs and disappear when the player defeats it.

            </> c++

                #include <iostream>
                using namespace std;

                struct Enemy {
                    int health = 100;
                };

                Enemy* createEnemy() {
                    return new Enemy;
                }

                int main() {
                    Enemy* enemy = createEnemy();

                    cout << enemy->health << endl;

                    // Enemy is defeated
                    delete enemy;

                    return 0;
                }

            How it works:

                1. `main()` calls `createEnemy()`.
                2. `new Enemy` allocates heap memory for an enemy object.
                3. `createEnemy()` returns the object's address.
                4. The enemy remains allocated after `createEnemy()` finishes.
                5. `main()` can continue using the enemy.
                6. `delete enemy` releases the allocation when it is no longer needed.

            Illustration:

                            STACK                    HEAP
                              |                        |
                main()        |                        |
                    |         |                        |
                    v         |                        |
                createEnemy() |                        |
                    |         |                        |
                    +-------->|                +-------------+
                            |                  | Enemy       |
                            |                  | health=100  |
                            |                  +-------------+
                            |                        ^
                            |                        |
                            |                        |
                            |                  enemy pointer
                            |
                createEnemy() finishes
                            |
                            |                  +-------------+
                            |                  | Enemy       |
                            |                  | health=100  |
                            |                  +-------------+
                            |
                main() continues using the enemy
                            |
                            v
                        delete enemy
                            |
                            v
                    Heap allocation released
        
            Why is heap useful here?

                Because the enemy's lifetime can be managed independently of the function that created it.
                However, this simple example could also return an `Enemy` by value without using the heap.
                Heap allocation becomes more useful as the game's object management becomes more complex.

        2. Other situations where heap memory is useful

            | Situation              | Why heap memory is useful                                                 |
            | ---------------------- | ------------------------------------------------------------------------- |
            | Game objects           | Create and destroy objects with flexible lifetimes                        |
            | GUI windows            | Keep window objects alive until they are closed                           |
            | Camera image buffers   | Store large amounts of image data                                         |
            | Different object types | Create objects of different classes dynamically using polymorphism        |
            | Shared objects         | Allow multiple parts of a program to use an object with managed ownership |
            | Linked structures      | Create tree nodes or linked objects individually as needed                |

        3. Does this mean you should always use heap memory?

            No.

            Consider:

                int main() {
                    int health = 100;
                    return 0;
                }
                ```

            A normal local variable is enough. Heap memory would introduce unnecessary complexity.
            In modern C++, you should also usually avoid directly managing `new` and `delete`.
            For individually allocated objects, `std::unique_ptr` and `std::make_unique` are generally safer.

        4. When should you choose heap memory?

            | Question                                                                  | Recommendation                 |
            | ------------------------------------------------------------------------- | ------------------------------ |
            | Do I just need a small local variable?                                    | Use an ordinary local variable |
            | Does the data only need to exist inside one function?                     | Usually use automatic storage  |
            | Do I need to keep an object alive independently of its creating function? | Consider heap memory           |
            | Is the object too large for the stack?                                    | Consider heap memory           |
            | Do I need runtime polymorphism with dynamically created objects?          | Heap memory is often useful    |

            The key idea: Heap memory gives a program flexibility over when an object is created,
            how long its allocation exists, and when that allocation is released.

            It is not necessary merely because a function returns data. In C++, you can often return objects by value
            without allocating heap memory.

    What happends if i do not use the heap memory for this case?

        You can create the enemy without heap memory, and your program will still work correctly.
        In fact, for your example, using an ordinary local variable is simpler.
        However, there is an important difference in how the enemy object is created and how long it exists.

        - Your original code (using heap memory)
        
            </> c++

                #include <iostream>
                using namespace std;

                struct Enemy {
                    int health = 100;
                };

                Enemy* createEnemy() {
                    return new Enemy;
                }

                int main() {
                    Enemy* enemy = createEnemy();

                    cout << enemy->health << endl;

                    // Enemy is defeated
                    delete enemy;

                    return 0;
                }

            Here, new Enemy dynamically allocates an enemy object on the heap.
            The allocation remains valid after createEnemy() finishes, until you release it using delete.

        - Without heap memory

            We can rewrite the program:

                #include <iostream>
                using namespace std;

                struct Enemy {
                    int health = 100;
                };

                Enemy createEnemy() {
                    Enemy e;
                    return e;
                }

                int main() {
                    Enemy enemy = createEnemy();

                    cout << enemy.health << endl;

                    return 0;
                }

            Output:

                100

            What happens step by step?
            
                Step 1: main() calls createEnemy().

                Step 2: createEnemy() creates a local object named e.
                    "Enemy e;"

                Step 3: return e; returns the enemy object by value.

                Step 4: createEnemy() finishes. Its local variable's lifetime ends,
                    but the returned value initializes enemy in main().

                Step 5: main() can use enemy.
                    "cout << enemy.health;"

                Step 6: When enemy reaches the end of its lifetime, it is automatically destroyed. You do not need delete.
                
                Modern C++ compilers can often construct the returned object directly
                in its destination, avoiding an unnecessary copy.

    What if you return a pointer to a local object instead?

        This is where you need to be careful.

        Incorrect example:
            Enemy* createEnemy() {
                Enemy e;
                return &e;  // WRONG!
            }

        Here:

            1. e is a local variable.
            2. &e obtains its memory address.
            3. The function returns that address.
            4. The function finishes, so e is destroyed.
            5. The returned pointer now refers to an object that no longer exists.

        Illustration:
        
            WHILE createEnemy() IS RUNNING

                Stack
                +-----------------------+
                | e                     |
                | health = 100          |
                +-----------------------+
                        ^
                        |
                    return &e


            AFTER createEnemy() FINISHES

                Stack
                +-----------------------+
                | e no longer exists    |
                | Space can be reused   |
                +-----------------------+

                Returned pointer -> Invalid

        Using that pointer to access the destroyed object causes undefined behavior.
        This is different from returning an object by value, which is safe.

    How about size of program between code using heap memory & Without heap memory?

        The size of a program using heap memory can be different from a program using only stack memory.

        But first, we need to distinguish two things:

            1. Executable file size — The size of your compiled program (.exe) stored on SSD/HDD.
            2. Runtime memory usage — How much memory your program uses while running.

        Let's compare your two C++ programs:

            1. Program using heap memory

                </> c++
                
                    struct Enemy {
                        int health = 100;
                    };

                    Enemy* createEnemy() {
                        return new Enemy;
                    }

                    int main() {
                        Enemy* enemy = createEnemy();

                        delete enemy;
                        return 0;
                    }

                Assume you're using a 64-bit computer where an integer occupies 4 bytes and a pointer occupies 8 bytes.

                At runtime, without compiler optimizations:

                    STACK MEMORY
                    +-----------------------+
                    | enemy pointer         |
                    | Approximately 8 bytes |
                    +-----------------------+
                            |
                            v
                    HEAP MEMORY
                    +-----------------------+
                    | Enemy                 |
                    | health = 100          |
                    | Approximately 4 bytes |
                    +-----------------------+


                The heap allocation may use additional memory for allocator bookkeeping and alignment.

            2. Program without heap memory

                </> c++

                    struct Enemy {
                        int health = 100;
                    };

                    Enemy createEnemy() {
                        Enemy e;
                        return e;
                    }

                    int main() {
                        Enemy enemy = createEnemy();

                        return 0;
                    }

                At runtime, conceptually:

                    STACK MEMORY
                    +-----------------------+
                    | Enemy                 |
                    | health = 100          |
                    | Approximately 4 bytes |
                    +-----------------------+

                The actual stack usage depends on how the compiler generates the program.
                It might even optimize away the object.

            3. Size comparison

                | Feature                   | Using heap              | Without heap               |
                | ------------------------- | ----------------------- | -------------------------- |
                | `Enemy` object size       | 4 bytes                 | 4 bytes                    |
                | Pointer variable          | Typically 8 bytes       | Not required               |
                | Dynamic allocation        | Yes                     | No                         |
                | Memory allocator overhead | Usually yes             | No heap allocator overhead |
                | Executable file size      | May be larger           | May be smaller             |
                | Runtime overhead          | Generally higher        | Generally lower            |
                | Manual `delete`           | Required with raw `new` | Not required               |

            4. Does using heap memory make the compiled program smaller?

                Not necessarily!

                Consider these two statements:

                    </> c++

                        Enemy enemy;             // Automatic storage

                    </> c++

                        Enemy* enemy = new Enemy; // Dynamic allocation

                During compilation:

                    - The first generally requires simple instructions to create and access a local object.
                    - The second may require additional instructions to request heap memory, handle the returned pointer,
                    and eventually release the allocation.

                Therefore, a program using heap memory can have a larger executable file than one using automatic storage.
                However, compiler optimizations may eliminate unnecessary allocations. Your two examples may even compile
                into nearly identical machine code because the objects are not used.

            5. Can heap memory reduce the compiled program's file size?

                Sometimes, the arrangement of data and code can affect executable size,
                but heap allocation does not inherently reduce executable size.

                For example, imagine you need 1,000,000 integers:

                    </> c++

                        int numbers[1000000];

                    Versus:

                    </> c++

                        int* numbers = new int[1000000];

                        delete[] numbers;

                    Both need approximately 4 MB of storage for the integers when their arrays exist.

                The important difference is:

                    - The local array usually uses stack storage.
                    - The dynamically allocated array uses heap storage.

                Neither(tidak ada satu pun) version necessarily(tentu) stores 4 MB of integer data inside the executable file.

            6. Compile-time size vs. runtime size

                Illustration:

                        C++ SOURCE CODE
                                |
                                v
                            COMPILER
                                |
                                v
                        EXECUTABLE FILE
                            (program.exe)
                                |
                                v
                            RUN PROGRAM
                                |
                                v
                        VIRTUAL MEMORY
                                |
                        +-------+-------+
                        |               |
                        v               v
                        STACK            HEAP
                        |               |
                    Local data       Dynamic data

                The compiled executable stays the same size on disk while the program runs,
                even if the heap allocation grows.

            Conclusion:

                For your `Enemy` example, using an ordinary local object is generally more memory-efficient and
                simpler than allocating it with `new`.

                The main advantage of heap memory is not reducing the executable file size.
                It is allowing dynamic allocation of data whose size, ownership, or lifetime needs to be more flexible.

    Stack memory is allocated at compile time based on the size of code while
    heap memory is allocated at runtime based on request, right?

        Almost correct! But there is one important correction:

            - Stack memory: The compiler usually determines how much stack space a function needs,
                but the stack space is actually used or reserved(disimpan/dicadangkan) at runtime, when the function is called.
            - Heap memory: Memory is allocated at runtime, when the program requests it.

        1. Stack Memory

            Consider this C++ code:

                void example() {
                    int a = 10;
                    int b = 20;
                }

                int main() {
                    example();
                    return 0;
                }

            At compile time, The compiler analyzes the function and determines how much stack space it typically needs.

                For example, assuming each int occupies 4 bytes:

                    example()
                        |
                        +-- int a = 10;  (4 bytes)
                        |
                        +-- int b = 20;  (4 bytes)
                        |
                        +-- Total variable storage: 8 bytes

                The compiler may determine the required stack-frame size, including other information.
                It could also keep these variables in registers or optimize them away.

                No stack frame for example() is allocated simply because you compile the code.
                At runtime, When main() calls example(), the program creates or reserves its stack frame.
                When example() returns, that stack space becomes available for reuse.

        2. Heap Memory

            Consider this C++ code:

                int main() {
                    int* p = new int(20);

                    delete p;
                    return 0;
                }

            At compile time, The compiler generates machine instructions that will perform the dynamic allocation.
            
            At runtime, When the program executes:
                
                new int(20);

            The heap allocator reserves memory for the integer.

            When the program executes:

                delete p;

            The allocation is released.

        Important: Stack Size Is Not Based on Code Size

            You mentioned that stack memory is allocated based on the size of the code.
            That is not quite correct.

            Stack memory requirements depend mainly on active function calls and the data each call needs,
            not the total number of lines of code.

            For example:

                void example() {
                    int a = 10;
                }

            Calling example() 100 times one after another does not mean 100 stack frames remain allocated simultaneously.
            However, 100 nested or recursive calls may require 100 active stack frames.

        Conclusion

            Your statement should be:

                - Stack memory: The compiler usually determines the stack-space requirements of
                    each function at compile time, but the space is used at runtime as functions execute.
                - Heap memory: The program requests dynamic memory at runtime, and the amount allocated depends on the request.

            Both stack and heap are part of a running program's memory, not memory allocated inside
            the executable file during compilation.

    We can say Heap & Stack are regions of a program's virtual address space to tell computer to
    manage/organize memory allocations, right?
        
        Yes! Your understanding is correct.
        Just one small correction: Stack and Heap don't directly tell the computer what to do.
        They are memory regions that the program and its runtime use according to different memory management rules.

        A more precise definition would be:

            Stack and Heap are regions of a program's virtual address space used to organize and manage
            memory allocations in different ways.

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