/*

Design patterns are typical solutions to commonly occurring problems in software design.
They are like pre-made blueprints/templates that you can customize to solve a recurring design problem
in your code. It's not a specific piece of code but a template or concept for
solving problems that can be adapted to various situations in programming.

You can’t just find a pattern and copy it into your program, the way you can do with
off-the-shelf(Siap pakai) functions or libraries. The pattern is not a specific piece of code,
but a general concept for solving a particular problem.


a programming design pattern is a template for solving a common problem, while
a programming paradigm is a way to structure a computer program.


Design patterns can be used in different programming paradigms, such as object-oriented and
functional programming. For example, in procedural programming, design patterns like modules,
decorators, and commands can be used to solve problems.


Example:
Object-Oriented Programming Paradigm (OOP)
Paradigm Principles:
1. Code is organized around objects, which represent real-world entities.
2. Objects encapsulate data (attributes) and behavior (methods).
3. Key concepts: Encapsulation, Inheritance, Polymorphism, and Abstraction.


Types of Design Patterns:
1. Creational Patterns:
    Focus on object creation mechanisms.
    
    Example: Singleton, Factory, Abstract Factory, Builder, Prototype.

2. Structural Patterns:
    Deal with object composition and relationships.
    Example: Adapter, Bridge, Composite, Decorator, Facade, Flyweight, Proxy.

3. Behavioral Patterns:
    Concerned(Berkaitan) with object interactions and delegation  of responsibilities ("delegation" refers to
    the practice of one object passing on a task or responsibility to another object, essentially allowing
    an object to "delegate" work to another object that is better suited to handle it,
    instead of performing the task itself).

    Example: Observer, Strategy, Command, Chain of Responsibility, State, Template Method,
    Visitor, Mediator, Interpreter, Iterator, memento.

*/

/*

Example:
Design Pattern: Singleton Pattern
a creational design pattern that lets you ensure that a class has only one instance,
while providing a global access point to this instance.

Problem:
1. Ensure that a class has just a single instance. 
2. Provide a global access point to that instance.

Solutions:
1. Make the default constructor private, to prevent multiple instances might accidentally be created,
    causing inconsistencies or conflicts.
2. Provides a static method (e.g., getInstance()) to access the single instance from anywhere in
    the application.

Use in Unreal Engine:
Ensures that certain systems or managers are globally accessible and have only one instance.
Examples:
    - Game Instance: Manages persistent data and systems that need to exist across level/map transitions.
    - Subsystems: Such as GameInstanceSubsystem or WorldSubsystem, which provide global services for
    specific purposes.

*/

//Code Example in C++:
#include <iostream>
using namespace std;

// Singleton class
class Logger {
private:
    /* We can create an object of the Logger class inside the class itself because the Logger class is
    a friend of itself */
    static Logger* instance; // Static instance of the class
    Logger() {}              // Private constructor to prevent direct instantiation

public:
    // Static method to access the single instance
    static Logger* getInstance() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    void logMessage(const string& message) {
        cout << "Log: " << message << endl;
    }
};

// Initialize static member
Logger* Logger::instance = nullptr;

int main() {
    Logger* logger1 = Logger::getInstance();
    Logger* logger2 = Logger::getInstance();

    logger1->logMessage("This is a log message.");
    if (logger1 == logger2) {
        cout << "Both loggers are the same instance!" << endl;
    }
    return 0;
}