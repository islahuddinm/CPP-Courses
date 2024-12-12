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
Design Pattern: Mediator Pattern
a behavioral design pattern that lets you reduce chaotic(kacau) dependencies(ketergantungan) between objects.
The pattern restricts direct communications between the objects and forces them to
collaborate only via a mediator object.

Problem:
1. Communication between multiple objects becomes complex, leading to tightly coupled(berpasangan) classes.
2. A direct dependency between objects makes the system rigid(kaku) and hard to maintained or extend.
3. Changing one object often requires modifying others, creating a cascading(berjenjang) effect.

Solution:
1. Use a Mediator to encapsulate the communication logic between multiple objects (Colleagues).
2. Colleagues interact with the Mediator rather than communicating directly with each other.
3. The Mediator reduces dependencies by centralizing the interaction logic.

Use Cases:
- Chat Applications:
    A mediator (chat room) manages messages between users.
- GUI Development:
    Components like buttons, text fields, and sliders interact through a mediator to coordinate behavior.
- Game Development:
    Managing interactions between game entities without direct dependencies

Use in Unreal Engine:
Facilitates communication between multiple objects, ensuring they do not interact directly.
Examples:
    - Game Mode and Game State: Coordinate gameplay elements like scoring or rules.
    - HUD and Controllers: Mediate communication between player input, UI updates, and game logic.

*/

#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// Forward declaration
class Mediator;

// Abstract Colleague Class
class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* med) : mediator(med) {}
    virtual void sendMessage(const string& message) = 0;
    virtual void receiveMessage(const string& message) = 0;
    virtual ~Colleague() = default;
};

// Mediator Interface
class Mediator {
public:
    virtual void notify(Colleague* sender, const string& message) = 0;
    virtual ~Mediator() = default;
};

// Concrete Colleague Classes
class User : public Colleague {
    string name;

public:
    User(Mediator* med, const string& userName) : Colleague(med), name(userName) {}

    void sendMessage(const string& message) override {
        cout << name << " sends: " << message << endl;
        mediator->notify(this, message);
    }

    void receiveMessage(const string& message) override {
        cout << name << " receives: " << message << endl;
    }
};

// Concrete Mediator
class ChatRoom : public Mediator {
    vector<shared_ptr<Colleague>> participants;

public:
    void addUser(const shared_ptr<Colleague>& user) {
        participants.push_back(user);
    }

    void notify(Colleague* sender, const string& message) override {
        for (auto& participant : participants) {
            if (participant.get() != sender) {
                participant->receiveMessage(message);
            }
        }
    }
};

// Client Code
int main() {
    // Create a mediator (Chat Room)
    shared_ptr<ChatRoom> chatRoom = make_shared<ChatRoom>();

    // Create colleagues (Users)
    auto user1 = make_shared<User>(chatRoom.get(), "Alice"); // The "chatRoom.get()" function call. This is used to get the raw pointer ( such as int*, float*, or MyClass.  it does not provide additional functionality or safety features like smart pointers (std::shared_ptr, std::unique_ptr)) managed by the std::shared_ptr named chatRoom.
    auto user2 = make_shared<User>(chatRoom.get(), "Bob");
    auto user3 = make_shared<User>(chatRoom.get(), "Charlie");

    // Register users to the chat room
    chatRoom->addUser(user1);
    chatRoom->addUser(user2);
    chatRoom->addUser(user3);

    // Users communicate via the mediator
    user1->sendMessage("Hello, everyone!");
    user2->sendMessage("Hi Alice!");
    user3->sendMessage("Hey Alice and Bob!");

    /* Output
    
    Alice sends: Hello, everyone!
    Bob receives: Hello, everyone!
    Charlie receives: Hello, everyone!
    Bob sends: Hi Alice!
    Alice receives: Hi Alice!
    Charlie receives: Hi Alice!
    Charlie sends: Hey Alice and Bob!
    Alice receives: Hey Alice and Bob!
    Bob receives: Hey Alice and Bob!
    
    */

    return 0;
}
