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
Design Pattern: Observer Pattern
a behavioral design pattern that lets you define a subscription mechanism to notify multiple objects about
any events that happen to the object they’re observing.

Problem:
1. Need to notify multiple objects (observers/customer) automatically when the state of
    another object(subject/store) changes.
2. Avoid tightly(secara erat/ketat) coupling(keterkaitan) the subject and its observers,
    so changes to(pada) the subject do not require modifications to(pada) its observers.

Solution:
1. Define a subject (observable) that maintains a list of observers.
2. Provide methods in the subject to add, remove, and notify observers.
3. bservers implement a common interface to ensure they can receive updates from the subject.

Use in Unreal Engine:
Used to manage communication between objects without tight coupling(keterkaitan).
Examples:
    - Event Dispatchers: Allow objects to listen to and respond to events triggered by other objects.
    - Delegates: Provide callbacks for events like input handling or gameplay triggers.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // This is for "observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());"
using namespace std;

// Observer Interface
class Observer {
public:
    virtual void update(const string& message) = 0; // Pure virtual function for updates
};

// Subject (Observable) class
class Subject {
private:
    vector<Observer*> observers; // List of observers
    string state;                // State of the subject

public:
    // Add an observer
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    // Remove an observer
    void removeObserver(Observer* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Notify all observers about the state change
    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(state);
        }
    }

    // Change the state of the subject
    void setState(const string& newState) {
        state = newState;
        notifyObservers(); // Notify observers of the change
    }
};

// Concrete Observer class
class ConcreteObserver : public Observer {
private:
    string name;

public:
    explicit ConcreteObserver(const string& name) : name(name) {}

    void update(const string& message) override {
        cout << "Observer [" << name << "] received update: " << message << endl;
    }
};

// Main Function
int main() {
    // Create subject
    Subject subject;

    // Create observers
    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    // Add observers to subject
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // Change state of the subject
    cout << "Changing state to 'State1':" << endl;
    subject.setState("State1");

    // Remove one observer
    subject.removeObserver(&observer1);

    // Change state again
    cout << "Changing state to 'State2':" << endl;
    subject.setState("State2");

    return 0;
}
