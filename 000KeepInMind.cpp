
/*
C++ elements that have "<...>" angle brackets symbol e.g. class type (vector, deque), keyword (dynamic_cast,
static_cast), type trait (std::is_integral<int>::value), function template (std::numeric_limits<...>::min()).

Macros in Unreal Engine and standard C++ are similar in concept, as they both rely on the preprocessor to
perform text substitution.
    Examples in C++ include #define PI 3.14159, #define SQUARE(x) ((x) * (x)), and #ifdef DEBUG.
    Check at "Macro.cpp"

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
    example: 
    
    template<>
    void printValue<std::string>(const std::string& value) { // this "<std::string>" to make explicit / convert other data types into string.
        std::cout << "Specialized: [" << value << "]" << std::endl;
    }
    
    file location: "FunctionTemplate.ccp"

concept (a feature introduced in the C++20 standard that allows programmers to specify
requirements/constraint/restriction on template arguments / in function template).
    file location: "Concepts Folder".

class (keyword which used to create custom data types).
- inside class there is constructor (a special member function of a class that allow creat an object).
constructor has same name as name class, no return type, can has parameters.
- there is default constructor (a constructor with no arguments/parameters).
default constructor can be automatically called when an object of that class is created in
main function, check at "DefaultConstructor.cpp". and also there is own/custom constructor which we declare
with arguments/parameters. when we create class then we dont declare default constructor, when we create object
we cannot create object without parameter like this "cars toyota;". we can see example at "KeyworClass4.cpp".
- there is custom constructor. check at "KeywordCalss3.cpp".
- when we create private attributes and then we want to get it to make public, we have to use 'return function'
to retrieve the value of a private, check at "KeywordCalss2". we can still access even though the
attributes is private because it is in same class.
- there is destructor function (special function is used to destroy objects). check at "DefaultConstructor.ccp,"
"Destructor3.cpp," "Destructor4.cpp" to know how they behave.
- there is "this" keyword is used to point current object address. check at "KeywordThis.cpp".
- there is how to call attibutes of objects that is created on heap memory, check at "KeywordCalss3.cpp".

programming paradigm is refer to style or patern of how code should be structured, organized, and
how algorithms should be designed. there is Object-oriented programming (OOP) is a type of programming paradigm
based on the concept of "objects," which can contain data within the form of fields (often known as attributes
or properties) and code, within the form of procedures (often known as methods). there are the core principles
of OOP: abstraction, encapsulation, inheritance, and polymorphism. those principles to achieve OOP.

inheritance (a fundamental concept in OOP. Creating new classes based on existing classes,
inheriting their attributes and methods of existing classes while also allowing for customization and
extension) check at "Inheritance.cpp".
- there are "protected" member, friend keyword, copy constructor and how to access private members,
check at "Inheritance2.cpp".
- there is how to inherit default constructor, check at "Inheritance3.cpp".

polymorphism (a fundamental concept in OOP / method in C++ allows us to reuse code by creating one function
that's usable for multiple uses in different scenarios). Polymorphism refers to the ability of derived classes
to override base class methods and allow the base class pointer or reference to call the derived class version
of the method, typically through virtual functions.
Without the virtual keyword, it is not polymorphism, even if the functions in the base and derived classes
have the same name. If you don't declare a base class function as virtual, the function called depends solely
on the type of the pointer or reference, not on the actual object type at runtime.
There are two main types of polymorphism:
- Compile-Time Polymorphism (Static Binding):
Achieved through method overloading and operator overloading.
example, check at "BindingStatic.cpp" and "BindingDynamic.cpp"
- Run-Time Polymorphism (Dynamic Binding):
Achieved through inheritance and function overriding.
example, check at "BindingStatic.cpp" and "BindingDynamic.cpp"

before understand polymorphism we have to understand
how create object on the heap and how to call its function, check at "KeywordClass3.cpp," "DefaultConstructor.cpp,"
"Destructor3.cpp," "Destructor4.cpp" and how they behave and also understand static and dynamic binding, check
at "BindingStatic.cpp," "BindingDynamic.cpp".
- there is virtual keyword is used to a base class's member function that you can redefine in a derived class
to achieve polymorphism, check at "Polymorphism.cpp" and "BindingDynamic.cpp".
- there is static and dynamic binding check at "BindingStatic.cpp," "BindingDynamic.cpp," "Polymorphism.cpp".
- there is pholymorphism size, check at "SizeofPolymorphism.cpp".
- there is object slicing, check at "PolymorphismSlicing.cpp," "SizeofPolymorphism.cpp" and "BindingStatic.cpp".
how to avoid "object slicing"? Mark functions as virtual in the base class when they need to be overridden in
derived classes & use pointer for implementation, check at "PolymorphismSlicing.cpp," "SizeofPolymorphism.cpp" and "BindingStatic.cpp".
- there is "override" keyword that is used to check if the function name is same with function name in
base class, check at "Polymorphism.cpp".
- there is overload function, check at "PolymorphismOverload.cpp," "PolymorphismOverload2.cpp," "PolymorphismOverload3.cpp"
- there is static keyword, check at "Polymorphism3.cpp"
- there is final keyword, check at "Polymorphism4.cpp"
- compiler always use default function arguments/parameter of base class and function body of derived class when
we call virtual(polymorphic) function in derived class.
- there is "dynamic cast keyword" (used for convert class type to another class type). check at "KeywordDynamicCast.cpp"
- there are abstruct class, interface and pure virtual (abstract) function. check at "AbstractClass.cpp,"
"AbstractClass2.cpp," "04AbstrackClassAsInterface.cpp".
- there is "typeid()". check at "OperatorTypeid.cpp," "OperatorTypeid2.cpp".

create object on the heap and how to call its function, check at "KeywordClass3.cpp," "DefaultConstructor.cpp,"
"Destructor3.cpp," "Destructor4.cpp".

Behaviors:
- Default Constructor: 
    - when we create object without parameter / declare pointer of animal class (base class),
    default constructor in animal class would be called automatically.
    - when we create object without parameter of dog class (child/derived class), default constructor in
    animal, feline, dog class would be called automatically even though we dont call all of it.
- Destructor:
    - when we create base class's object on stack memory, base class's default constructor and destructor
    function will be called automatically.
    - when we create child/derived class's object on stack memory, child/derived, base class's default
    constructor and destructor function will be called automatically.
    - but when we create object on heap memory, destructor function will be never called automatically.
- Polymorphism:
    - Polymorphism refers to the ability of derived classes to override base class methods and allow the base
    class pointer or reference to call the derived class version of the method, typically through
    virtual functions.
- Flow Control:
    - we cannot access variables inside flow control. but we can access variables outside flow control
    from flow control.
    - we cannot access variables inside flow control from flow control.
- Function:
    - access variables inside function. Check at "AccessVariableInsideFunction.cpp"
    - we cannot access variables inside function. but we can access variables outside function
    from function.
    - we cannot access variables inside function from function. but we can access variables inside function
    from function inside class. Check at "ClassGetsExternalFunctionReturn.cpp".
    - we cannot declare/create a function inside function. but we can create lambda function inside function.
    Chect at "ClassCreateClass.cpp", "FunctionInsideFunction.cpp"
    - we can call a function inside a class without create a object. Chect at "CallFunctionInsideClass.cpp".
    - we can call a function inside a class from another class.
    Check at "CallFunctionInsideClassFromAnotherClass.cpp"
- Class:
    - We can create a class inside a class. Chect at "ClassCreateClass.cpp".
    - We can create an object of the Logger class inside the class itself. Check at "DesignPatternSingleton.cpp"
    - We can cleate an object of another class inside class. Check at "ClassCreateObjectInside.cpp".
    - Class can get an external ReturnFunction. Check at "ClassGetsExternalFunctionReturn.cpp".
    - Class is inside function. Check at "ClassInsideFunction.cpp".
    - Create object outside function. Check at "ClassOutsideFunction.cpp".
    - Initializing static member variables of the cars class from outside. Check at "ClassOutsideFunction4.cpp"
*/