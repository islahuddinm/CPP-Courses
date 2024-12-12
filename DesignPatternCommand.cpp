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
Design Pattern: Command Pattern
a behavioral design pattern that turns a request into a stand-alone(berdiri sendiri) object that contains
all information about the request. This transformation lets you pass requests as a method arguments,
delay or queue(antre/baris) a request’s execution, and support undoable(tidak bisa dibatalkan) operations.

Problem:
1. You need to decouple(memisahkan) the sender of a request from the receiver.
2. You want to encapsulate a request as an object to allow delayed execution,
    undo/redo functionality, or logging.

Solution:
1. Define a Command Interface with a common method (e.g., execute()).
2. Implement Concrete Command Classes for each request, encapsulating the action and its receiver.
3. The Invoker (e.g., a button) stores and executes commands, while the Receiver performs the actual operation.

Uses Cases:
- UI Buttons:
    Associate commands with buttons to execute specific actions.
- Transactional Systems:
    Encapsulate operations as commands for replay or rollback functionality.
- Task Scheduling:
    Queue and execute tasks in a controlled manner.

Use in Unreal Engine:
Encapsulates actions as objects, allowing them to be queued or undone.
Examples:
    - Input Bindings: Maps inputs to specific actions or commands (e.g., jump, shoot).
    - Undo/Redo System in the Editor: Encapsulates editor actions to allow undo and redo.

*/

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Command Interface
class Command {
public:
    virtual void execute() = 0; // Pure virtual method to execute a command
    virtual ~Command() = default;
};

// Receiver Class
class Light {
public:
    void turnOn() {
        cout << "Light is ON" << endl;
    }

    void turnOff() {
        cout << "Light is OFF" << endl;
    }
};

// Concrete Command to Turn On the Light
class TurnOnCommand : public Command {
private:
    Light& light;

public:
    explicit TurnOnCommand(Light& lightRef) : light(lightRef) {}
    void execute() override {
        light.turnOn();
    }
};

// Concrete Command to Turn Off the Light
class TurnOffCommand : public Command {
private:
    Light& light;

public:
    explicit TurnOffCommand(Light& lightRef) : light(lightRef) {}
    void execute() override {
        light.turnOff();
    }
};

// Invoker Class
class RemoteControl {
private:
    vector<shared_ptr<Command>> commands; // List of commands

public:
    void setCommand(shared_ptr<Command> command) {
        commands.push_back(move(command));
    }

    void pressButton() {
        if (!commands.empty()) {
            commands.back()->execute(); // Execute the most recently added command
            commands.pop_back();        // Remove the executed command
        } else {
            cout << "No command to execute!" << endl;
        }
    }
};

// Client Code
int main() {
    Light livingRoomLight;

    // Create commands
    auto turnOn = make_shared<TurnOnCommand>(livingRoomLight);
    auto turnOff = make_shared<TurnOffCommand>(livingRoomLight);

    // Invoker
    RemoteControl remote;

    // Set and execute commands
    remote.setCommand(turnOn);
    remote.pressButton(); // Output: Light is ON

    remote.setCommand(turnOff);
    remote.pressButton(); // Output: Light is OFF

    // No command left to execute
    remote.pressButton(); // Output: No command to execute!

    return 0;
}
