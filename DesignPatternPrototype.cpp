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
Design Pattern: Prototype Pattern
a creational design pattern that lets you copy existing objects without making
your code dependent on their classes.

Problem:
1. Creating objects directly can be costly(mahal/ makan biaya), especially when object creation involves
    a lot of computation or resource allocation.
2. Direct object creation results in tightly coupled code, making it difficult to adapt or extend.
3. When the system needs to create objects at runtime without knowing the exact class of the objects.

Solution:
1. Use a Prototype interface to define a method for cloning objects.
2. Concrete classes implement the clone() method to create a copy of the object.
3. Instead of creating new objects directly, the client requests a copy from an existing prototype.

Use Cases:
- Object Pooling:
    Reuse existing objects with slight modifications.
- Game Development:
    Clone objects like enemies, weapons, or levels with similar attributes.
- Document Editors:
    Duplicate elements like shapes, text boxes, or images with minor tweaks.

Use in Unreal Engine:
Creates new objects by cloning existing ones.
Examples:
    - Actor Duplication: Duplicating actors in the editor or during gameplay for efficiency.
    - Instanced Static Meshes: Efficiently reusing and rendering multiple copies of the same mesh.


*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Prototype Interface
class Shape {
public:
    virtual ~Shape() = default;
    virtual unique_ptr<Shape> clone() const = 0; // Cloning method
    virtual void draw() const = 0;               // Abstract method to demonstrate functionality
};

// Concrete Prototype: Circle
class Circle : public Shape {
private:
    string color;
    int radius;

public:
    Circle(const string& c, int r) : color(c), radius(r) {}

    // Copy constructor used for cloning
    Circle(const Circle& other) : color(other.color), radius(other.radius) {}

    unique_ptr<Shape> clone() const override {
        return make_unique<Circle>(*this); // Clone using copy constructor
    }

    void draw() const override {
        cout << "Drawing a " << color << " circle with radius " << radius << "." << endl;
    }
};

// Concrete Prototype: Rectangle
class Rectangle : public Shape {
private:
    string color;
    int width, height;

public:
    Rectangle(const string& c, int w, int h) : color(c), width(w), height(h) {}

    // Copy constructor used for cloning
    Rectangle(const Rectangle& other) : color(other.color), width(other.width), height(other.height) {}

    unique_ptr<Shape> clone() const override {
        return make_unique<Rectangle>(*this); // Clone using copy constructor
    }

    void draw() const override {
        cout << "Drawing a " << color << " rectangle with width " << width << " and height " << height << "." << endl;
    }
};

// Client Code
int main() {
    // Create prototypes
    unique_ptr<Shape> prototypeCircle = make_unique<Circle>("red", 10);
    unique_ptr<Shape> prototypeRectangle = make_unique<Rectangle>("blue", 15, 25);

    // Clone and use objects
    unique_ptr<Shape> circle1 = prototypeCircle->clone();
    unique_ptr<Shape> circle2 = prototypeCircle->clone();
    unique_ptr<Shape> rectangle1 = prototypeRectangle->clone();

    // Modify and use clones
    circle1->draw(); // Output: Drawing a red circle with radius 10
    circle2->draw(); // Output: Drawing a red circle with radius 10
    rectangle1->draw(); // Output: Drawing a blue rectangle with width 15 and height 25

    return 0;
}
