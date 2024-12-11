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

Exampple:
Design Pattern: State Pattern
a behavioral design pattern that lets an object alter(mengubah) its behavior when its internal state changes.
It appears as if the object changed its class.

Problem:
1. An object’s behavior depends on its state, and it must change its behavior at runtime based on the state.
2. Avoid large conditional statements (e.g., switch or if-else) to handle state-specific behavior.

Solution:
1. Define a State interface to represent all possible states of the object.
2. Implement concrete classes for each state, encapsulating state-specific behavior.
3. Have the context class maintain a reference to the current state and delegate state-specific behavior to it.
4. Allow the state to transition to another state dynamically.

Use in Unreal Engine:
Manages different states of objects or characters, allowing behavior to change dynamically.
Examples:
    - State Machines in Animation Blueprints: Handle different states of
        character animations, like idle, walk, run, or jump.
    - Gameplay Abilities: Use the Gameplay Ability System (GAS) to manage states like "stunned" or "buffed."
    - UI Components: Button behavior changes depending on its state (e.g., enabled, disabled, or hovered).

*/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Forward declaration of Context
class Context;

// State Interface
class State {
public:
    virtual void handle(Context& context) = 0; // Pure virtual function
    virtual ~State() = default;
};

// Concrete State 1
class StateA : public State {
public:
    void handle(Context& context) override;
};

// Concrete State 2
class StateB : public State {
public:
    void handle(Context& context) override;
};

// Context Class
class Context {
private:
    shared_ptr<State> currentState; // Current state of the context

public:
    Context(shared_ptr<State> state) : currentState(move(state)) {}

    void setState(shared_ptr<State> state) {
        currentState = move(state);
    }

    void request() {
        if (currentState) {
            currentState->handle(*this); // Delegate to the current state
        }
    }
};

// StateA's handle implementation
void StateA::handle(Context& context) {
    cout << "StateA handling request, transitioning to StateB" << endl;
    context.setState(make_shared<StateB>()); // Transition to StateB
}

// StateB's handle implementation
void StateB::handle(Context& context) {
    cout << "StateB handling request, transitioning to StateA" << endl;
    context.setState(make_shared<StateA>()); // Transition to StateA
}

// Client Code
int main() {
    // Start in StateA
    auto initialState = make_shared<StateA>();
    Context context(initialState);

    // Perform state-specific behavior
    context.request(); // Output: StateA handling request, transitioning to StateB
    context.request(); // Output: StateB handling request, transitioning to StateA
    context.request(); // Output: StateA handling request, transitioning to StateB

    return 0;
}
