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
Design Pattern: Strategy Pattern
a behavioral design pattern that lets you define a family of algorithms, put each of them
into a separate class, and make their objects interchangeable(dapat dipertukarkan).

Problem:
1. A class needs to perform a specific behavior that may vary depending on the context.
2. Hardcoding(writing code that is not easily modified or reused, cannot be easily changed without
    changing the source code) multiple algorithms in the same class creates a complex and
    tightly coupled(berpasangan) design, making it difficult to add, remove, or change algorithms dynamically.

Solution:
1. Define a family of algorithms (strategies) in separate classes that implement a common interface.
2. Encapsulate each algorithm within a separate class.
3. Allow the context to switch between these algorithms dynamically at runtime.

Use Cases:
- Sorting Algorithms:
    Allow the user to choose between different sorting algorithms (e.g., quick sort, merge sort).
- Payment Processing:
    Support multiple payment methods (e.g., credit card, PayPal).

Use in Unreal Engine:
Encapsulates algorithms or behaviors and allows switching them dynamically.
Examples:
    - AI Behavior Trees: Define strategies for AI actions and decision-making.
    - Movement Modes: Characters can switch between walking, flying, or swimming dynamically
        using movement strategies.
    - Game Development: Allow different behaviors for characters (e.g., aggressive,
        defensive, passive strategies).

*/

#include <iostream>
#include <memory>
using namespace std;

// Strategy Interface
class Strategy {
public:
    virtual void execute() const = 0; // Pure virtual method
    virtual ~Strategy() = default;
};

// Concrete Strategy 1
class StrategyA : public Strategy {
public:
    void execute() const override {
        cout << "Executing Strategy A" << endl;
    }
};

// Concrete Strategy 2
class StrategyB : public Strategy {
public:
    void execute() const override {
        cout << "Executing Strategy B" << endl;
    }
};

// Context Class
class Context {
private:
    shared_ptr<Strategy> strategy; // Holds the current strategy

public:
    void setStrategy(shared_ptr<Strategy> newStrategy) {
        strategy = move(newStrategy);
    }

    void performAction() const {
        if (strategy) {
            strategy->execute(); // Delegate the action to the strategy
        } else {
            cout << "No strategy set!" << endl;
        }
    }
};

// Client Code
int main() {
    Context context;

    // Use Strategy A
    context.setStrategy(make_shared<StrategyA>());
    context.performAction(); // Output: Executing Strategy A

    // Switch to Strategy B
    context.setStrategy(make_shared<StrategyB>());
    context.performAction(); // Output: Executing Strategy B

    // No strategy set
    context.setStrategy(nullptr);
    context.performAction(); // Output: No strategy set!

    return 0;
}
