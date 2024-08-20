//header
#include <iostream>
//"#include"(enclose). "<iostream>"(library) which allows to use library functions in "<iostream>"(library). "std::cin"(input) and "std::cout"(output).
//analogy of library is imagine that library is a storage which it provides tools so if we dont have tool we cant do works.

//compiler will always start to read top project to below then start to working in main fuction (int main).

/*
- function = a reusable block of code that performs a specific task or set of tasks.
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
*/