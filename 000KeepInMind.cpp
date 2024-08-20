
/*
library function (functions that are already available and implemented in C++ standard library).
    example: "std::strlen(parameters)," "std::strcpy(parameters)," "std::strcat(parameters)," "std::strcmp()".
    file location: "FunctionLibStd_.cpp"

lambda function (anonymous functions means that the function is without a name).
    file location: "FunctionLambda.cpp"

overload function (Function allows multiple functions to have the same name but with
different parameters).
    file location: "FunctionOverload.cpp"

function template (Function template is a feature in languages like C++ that allows you to define once
a function and use it with different data types. it is used to avoid "overload functions").
    file location: "FunctionTemplate.ccp"

concept (a feature introduced in the C++20 standard that allows programmers to specify
requirements/constraint/restriction on template arguments / in function template).
    file location: "Concepts Folder".

class (keyword which used to create custom data types).
- inside class there is constructor (a special member function of a class that allow creat an object).
constructor has same name as name class, no return type, can has parameters.
- there is default constructor default (a constructor with no arguments/parameters).
default constructor can be automatically called when an object of that class is created in
main function, check at "DefaultConstructor.cpp". and also there is own/custom constructor which we declare
with arguments/parameters. when we create class then we dont declare default constructor, when we create object
we cannot create object without parameter like this "cars toyota;". we can see example at "KeyworClass4.cpp".
- when we create private attributes and then we want to get it to make public, we have to use 'return function'
to retrieve the value of a private, check at "KeywordCalss2". we can still access even though the
attributes is private because it is in same class.
- there is destructor function (special function is used to destroy objects). check at "DefaultConstructor.ccp
," "Destructor3.cpp," "Destructor4.cpp" to know how they behave.

create object on the heap and how to call its function, check at "KeywordClass3.cpp".
*/