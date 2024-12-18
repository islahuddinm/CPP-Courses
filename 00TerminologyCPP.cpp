//header
#include <iostream>
//"#include"(enclose). "<iostream>"(library) which allows to use library functions in "<iostream>"(library). "std::cin"(input) and "std::cout"(output).
//analogy of library is imagine that library is a storage which it provides tools so if we dont have tool we cant do works.

//compiler will always start to read top project to below then start to working in main fuction (int main).

/*
- function = a reusable block of code that performs a specific task or set of tasks.
- overload function (Function allows multiple functions to have the same name but with different parameters).
- override function is function in the derived class "overrides"(menggantikan) the function in
the base class.
- data types = int(integer), float, double, char(character), bolean. used to define the type of
data that a variable can store.
- pre-defined class types = std::srting, std::vector<T>, std::deque<T>, std::list<T>, and so on.
- keyword which used to create custom data types / class types = class, struct, union, enum, typedef, template.

- variable = symbolic name assigned to store data and value.
- statement = a complete line of code that performs a specific action or operation/ a line code that have ";".
- declaration = a statement describing an identifier, such as the name of a variable or a function.
- assignment = a statement in computer programming that is used to set a value in a variable.
- initialize = start to the assignment of an initial value.
- expression = a combination of values, variables, operators, and functions that can be evaluated to
produce a result.

- "return 0" in the main function = a signal to indicate to the operating system that the program is
successfully. it is used when scripting or using tools that execute programs, it's common to
check the exit status. A return value of 0 allows for automated processes to quickly determine whether
the executed program succeeded or encountered problems.

- "return" in other functions = enable to return values to main function.

- "FunctionUserDefined.cpp"(cpp file) in CPP-COURSES folder. it explaind more function terminologys.

- "encapsulate" means bundling data (variables) together with the methods (functions) that
operate on that data into a single unit, usually within a class, effectively hiding
internal implementation details and controlling how the data can be accessed and modified.
- "encapsulation" refers to the practice of bundling data (variables) and the methods that
    operate on that data together into a single unit, usually a class. 
- "delegates" refer to allowing you to pass a method as an argument to another method.
- "delegation" refers to the practice of one object passing on a task or responsibility to another object,
    essentially allowing an object to "delegate" work to another object that is better suited to handle it,
    instead of performing the task itself.
- "instantiation" refer to the process of creating a new instance or object from a class.
- "explicit" means clearly stating instructions or details within the code, where the programmer
    manually specifies everything needed.
- "implicit" means something is done automatically by the language or compiler without
    the programmer explicitly writing it out.
- "semantics" refers to the meaning behind a piece of code, essentially defining
    what a set of instructions will do when executed.
- "syntax" refers to the set of rules that define the structure and order of symbols, words, and
    punctuation used to write valid code in a specific programming language. In english it is like Grammer.
- "Lvalue (Left Value)" refers to an expression that has a persistent memory location (an address) and
    can appear on the left-hand side of an assignment. Check below at main() function.
- "Rvalue (Right Value)" refers to a temporary value (a value without a persistent memory location).
    It is typically used on the right-hand side of an assignment. Check below at main() function.

*/

//function
int main() { // "int"(data type) for main function's "return 0". "main"(function name). "()"(to store parameters)
    
    //declare and initialize.
    int var1 {12}; // "int"(data type). "var1"(variable). "12"(value). ";"(semicolon is used to indicate the end of a statement)
    std::cout << var1 << '\n'; // "std::cout"(library function) that is used to output. '\n'(c++ element) to move a code line.

    //assignment.
    var1 = 20; 
    std::cout << var1 << '\n';

    //declare and initialize
    bool state {false}; 
    std::cout << std::boolalpha << state << '\n'; // std::boolalpha; is a manipulator to manipulate values to be "true" or "false"

    state = true; //assignment
    std::cout << state << std::boolalpha << '\n';

    //this is lvalue (left value)
    int x = 10;  // 'x' is an lvalue.
    x = 20;      // Valid: 'x' is on the left-hand side.
    int& ref = x;  // Valid: lvalue reference to 'x'.
    const int y = 15;  // 'y' is a const lvalue (non-modifiable).

    //this is rvalue (right value)
    int x = 10;   // '10' is an rvalue (temporary value).
    int y = x + 5;  // '(x + 5)' is an rvalue.
    int&& r = 10;  // Valid: rvalue reference to a temporary value.
    
    return 0;
}

/*
virtual function is polymorphic function.

Function Overloading
Function overloading allows multiple functions to have the same name but with different parameters
(different number, type, or order of parameters). 

Function Overriding
Function overriding occurs when a derived (child) class has a definition for one of the member functions of
the base (parent) class. The function in the derived class "overrides"(menggantikan) the function in
the base class.

Key Differences:
Overloading: Same function name with different parameters (within the same scope).
Overriding: Same function name, same parameters, but the function is defined in both base and
derived classes (inherited classes). */

/* Binding in programming, specifically in C++, is the process of linking a function call to
its corresponding function definition. there are 2 binding types "Static Binding" and "Dynamic Binding"

Static binding happens at compile time. it means when we call generally other functions in main function.
dynamic binding happens at runtime. it means when we only call "deriverd class's" function then automatically
also call "base class's" function.

https://youtu.be/5FmszF_Tb2A?si=GzShzuEJebtgEOth

'#pragma once' instructs the compiler to include a header file only once when compiling a source file.

'#ifndef CAR_H' stand for "if not defined (code file)"
'#define CAR_H' stand for "define(code file)"

#ifndef, #define those are directive(yg menginstruksikan) check to ensure that the file's contents are
not included multiple times. This practice is known as an include guard.

'#endif' This marks the end of the conditional directive started by #ifndef.
*/