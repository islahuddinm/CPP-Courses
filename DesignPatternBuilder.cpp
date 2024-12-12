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
Design Pattern: Builder Pattern
a creational design pattern that lets you construct complex objects step by step.
The pattern allows you to produce different types and representations of an object using
the same construction code.

Problem:
1. A complex object needs to be created step by step.
2. The construction process is too complex to be handled by a single constructor or simple factory method.
3. You want to build variations of the same object without creating a massive constructor with
    multiple optional parameters.

Solution:
1. Separate the construction of a complex object from its representation:
    - Use a Builder to construct the object step by step.
    - The Director manages the building process, ensuring that the correct steps are followed.
2. The Builder interface allows for variations in the construction process for different types of products.

Use Cases:
- Complex Object Construction:
    Building GUI components like dialogs or forms.
- Game Development:
    Creating complex game entities like characters or buildings.
- Report Generation:
    Building reports with varying sections based on configuration.

Use in Unreal Engine:
Constructs complex objects step by step.
Examples:
    - UI Construction: Building complex UIs using WidgetBlueprint or UUserWidget.
    - Procedural Level Generation: Dynamically creating levels or environments using predefined steps.

*/

#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Product Class
class House {
private:
    string foundation;
    string structure;
    string roof;
    string interior;

public:
    void setFoundation(const string& foundationType) { foundation = foundationType; }
    void setStructure(const string& structureType) { structure = structureType; }
    void setRoof(const string& roofType) { roof = roofType; }
    void setInterior(const string& interiorType) { interior = interiorType; }

    void show() const {
        cout << "House built with:\n"
             << "Foundation: " << foundation << "\n"
             << "Structure: " << structure << "\n"
             << "Roof: " << roof << "\n"
             << "Interior: " << interior << "\n";
    }
};

// Builder Interface
class HouseBuilder {
public:
    virtual void buildFoundation() = 0;
    virtual void buildStructure() = 0;
    virtual void buildRoof() = 0;
    virtual void buildInterior() = 0;
    virtual shared_ptr<House> getHouse() = 0;
    virtual ~HouseBuilder() = default;
};

// Concrete Builder for a Wooden House
class WoodenHouseBuilder : public HouseBuilder {
private:
    shared_ptr<House> house;

public:
    WoodenHouseBuilder() { house = make_shared<House>(); }

    void buildFoundation() override { house->setFoundation("Wooden Piles"); }
    void buildStructure() override { house->setStructure("Wooden Beams"); }
    void buildRoof() override { house->setRoof("Wooden Shingles"); }
    void buildInterior() override { house->setInterior("Wooden Paneling"); }

    shared_ptr<House> getHouse() override { return house; }
};

// Concrete Builder for a Stone House
class StoneHouseBuilder : public HouseBuilder {
private:
    shared_ptr<House> house;

public:
    StoneHouseBuilder() { house = make_shared<House>(); }

    void buildFoundation() override { house->setFoundation("Concrete Foundation"); }
    void buildStructure() override { house->setStructure("Stone Walls"); }
    void buildRoof() override { house->setRoof("Slate Roof"); }
    void buildInterior() override { house->setInterior("Stone Flooring"); }

    shared_ptr<House> getHouse() override { return house; }
};

// Director Class
class ConstructionDirector {
private:
    shared_ptr<HouseBuilder> builder;

public:
    void setBuilder(shared_ptr<HouseBuilder> newBuilder) { builder = move(newBuilder); }

    shared_ptr<House> constructHouse() {
        if (!builder) {
            throw runtime_error("No builder set!");
        }
        builder->buildFoundation();
        builder->buildStructure();
        builder->buildRoof();
        builder->buildInterior();
        return builder->getHouse();
    }
};

// Client Code
int main() {
    ConstructionDirector director;

    // Build a Wooden House
    auto woodenHouseBuilder = make_shared<WoodenHouseBuilder>();
    director.setBuilder(woodenHouseBuilder);
    shared_ptr<House> woodenHouse = director.constructHouse();
    woodenHouse->show();

    // Build a Stone House
    auto stoneHouseBuilder = make_shared<StoneHouseBuilder>();
    director.setBuilder(stoneHouseBuilder);
    shared_ptr<House> stoneHouse = director.constructHouse();
    stoneHouse->show();

    /* Output
    
    House built with:
    Foundation: Wooden Piles
    Structure: Wooden Beams
    Roof: Wooden Shingles
    Interior: Wooden Paneling

    House built with:
    Foundation: Concrete Foundation
    Structure: Stone Walls
    Roof: Slate Roof
    Interior: Stone Flooring
    
    */

    return 0;
}
