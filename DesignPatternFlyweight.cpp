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
Design Pattern: Flyweight Pattern
a structural design pattern that aims to minimize memory usage by sharing common parts of objects.

Problem:
1. Applications that require creating a large number of objects can face performance issues
    due to high memory usage.
2. Repeatedly creating and storing duplicate data for similar objects wastes memory.
3. Maintaining multiple instances with the same state can lead to redundancy and inefficiency.

Solution:
1. Share common parts of object state (intrinsic state) instead of duplicating them for each object.
2. Use a central Flyweight Factory to manage and reuse shared objects.
3. Store the unique state (extrinsic state) externally and combine it with the intrinsic state
    when performing operations.

Use Cases:
- Graphical Applications:
    Rendering a large number of similar objects like trees, particles, or icons.
- Text Editors:
    Representing characters in a document where fonts and formatting are shared.
- Game Development:
    Managing repeated objects like tiles, bullets, or enemies with shared characteristics.

Use in Unreal Engine:
Optimizes memory usage by sharing common data between objects.
Examples:
    - Instanced Static Mesh Component: Shares rendering data among identical meshes.
    - Animation Assets: Reuses animation data across multiple characters.

*/

#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>
using namespace std;

// Flyweight Class
class TreeType {
private:
    string name;
    string color;
    string texture;

public:
    TreeType(const string& n, const string& c, const string& t)
        : name(n), color(c), texture(t) {}

    void display(int x, int y) const {
        cout << "TreeType: " << name << ", Color: " << color
             << ", Texture: " << texture
             << " at position (" << x << ", " << y << ")." << endl;
    }
};

// Flyweight Factory
class TreeFactory {
private:
    unordered_map<string, shared_ptr<TreeType>> treeTypes;

public:
    shared_ptr<TreeType> getTreeType(const string& name, const string& color, const string& texture) {
        string key = name + "_" + color + "_" + texture;
        if (treeTypes.find(key) == treeTypes.end()) {
            treeTypes[key] = make_shared<TreeType>(name, color, texture);
        }
        return treeTypes[key];
    }
};

// Context Class
class Tree {
private:
    int x, y;                         // Extrinsic state
    shared_ptr<TreeType> treeType;    // Intrinsic state

public:
    Tree(int x, int y, shared_ptr<TreeType> type)
        : x(x), y(y), treeType(type) {}

    void display() const {
        treeType->display(x, y);
    }
};

// Client Code
int main() {
    TreeFactory factory;

    // Create trees with shared TreeType instances
    Tree tree1(10, 20, factory.getTreeType("Oak", "Green", "Rough"));
    Tree tree2(30, 40, factory.getTreeType("Pine", "Dark Green", "Smooth"));
    Tree tree3(50, 60, factory.getTreeType("Oak", "Green", "Rough")); // Reuses existing "Oak" TreeType

    // Display trees
    tree1.display();
    tree2.display();
    tree3.display();

    /* Output
    
    TreeType: Oak, Color: Green, Texture: Rough at position (10, 20).
    TreeType: Pine, Color: Dark Green, Texture: Smooth at position (30, 40).
    TreeType: Oak, Color: Green, Texture: Rough at position (50, 60).
    
    */

    return 0;
}
