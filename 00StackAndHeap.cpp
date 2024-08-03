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


In summary, the stack is used for static memory allocation and manages function call information,
while the heap is used for dynamic memory allocation and allows for more flexible memory management.*/