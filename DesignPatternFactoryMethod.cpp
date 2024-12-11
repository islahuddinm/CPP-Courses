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
Design Pattern: Factory Method Pattern
a creational design pattern that provides an interface for creating objects in
a superclass(a class from which other classes inherit properties and behaviors, superclass is
often also called a "base class" or "parent class"),
but allows subclasses to alter(permak/mengubah) the type of objects that will be created.

Problem:
1. Need to create objects without specifying their exact class, enabling flexibility and scalability.
2. Avoid modifying existing code to introduce new types of objects, adhering(mengikuti) to
    the Open/Closed Principle (New product types can be added by creating new factories without
    changing existing code).

Solution:
1. Define a factory method in a base class (or interface) that delegates(allowing you to pass a method as
    an argument to another method) the instantiation(the process of creating a new instance or
    object from a class) of objects to its subclasses.
2. Subclasses override the factory method to create specific object types.

Use in Unreal Engine:
Simplifies object creation while keeping it abstract and extensible.
Examples:
    - Object and Actor Factories: Unreal Engine uses methods like SpawnActor to create actors dynamically
        at runtime.
    - Gameplay Tags: Used to define reusable gameplay properties, often instantiated through
        a factory-like process.

*/

#include <iostream>
#include <memory>
using namespace std;

// Product Interface
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function for drawing
    virtual ~Shape() = default;
};

// Concrete Product 1
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Concrete Product 2
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

// Creator (Factory) Interface
class ShapeFactory {
public:
    virtual unique_ptr<Shape> createShape() = 0; // Factory Method // Pure virtual function
    virtual ~ShapeFactory() = default;
};

// Concrete Factory 1
class CircleFactory : public ShapeFactory {
public:
    unique_ptr<Shape> createShape() override {
        return make_unique<Circle>(); // Create a Circle
        //return Circle(); // Create a Circle generally
    }
};

// Concrete Factory 2
class RectangleFactory : public ShapeFactory {
public:
    unique_ptr<Shape> createShape() override {
        return make_unique<Rectangle>(); // Create a Rectangle
    }
};

// Client Code
int main() {
    unique_ptr<ShapeFactory> factory;

    // Use CircleFactory
    factory = make_unique<CircleFactory>();
    // Create objects without specifying their exact class
    unique_ptr<Shape> circle = factory->createShape(); // Create a Circle
    circle->draw(); // Output: Drawing a Circle

    // Use RectangleFactory
    factory = make_unique<RectangleFactory>();
    // Create objects without specifying their exact class
    unique_ptr<Shape> rectangle = factory->createShape(); // Create a Rectangle
    rectangle->draw(); // Output: Drawing a Rectangle

    return 0;
}
