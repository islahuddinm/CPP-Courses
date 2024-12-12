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
Design Pattern: Facade Pattern
a structural design pattern that provides a simplified interface to a library, a framework, or
any other complex set of classes.

Problem:
1. Complex subsystems with multiple interconnected(saling berhubungan) components can
    overwhelm(membebani/ give too much of a thing to (someone)) clients.
2. Clients need to interact with multiple classes, leading to tight coupling and reduced maintainability.
3. The complexity of using a system's features increases due to the need to
    manage interactions among various subsystems.

Solution:
1. Introduce a Facade class that provides a simplified and unified interface to the subsystem.
2. Clients interact with the facade, which internally manages interactions with the subsystem components.
3. The facade decouples the client from the internal complexity of the subsystem.

Use Cases:
- Home Theater Systems:
    Managing audio, video, and other components through a central interface.
- Enterprise Applications:
    Providing a simplified interface for complex subsystems like database connections, logging, and authentication.
- GUI Applications:
    Hiding low-level graphical details behind a facade class for rendering and user interactions.

Use in Unreal Engine:
Provides a simplified interface to complex subsystems.
Examples:
    - Gameplay Framework: Classes like APlayerController, AGameMode, and ACharacter hide
        the complexity of managing players, rules, and input.
    - Blueprint System: Simplifies scripting and logic creation for non-programmers.

*/

#include <iostream>
#include <string>
using namespace std;

// Subsystem Component 1
class AudioSystem {
public:
    void turnOn() {
        cout << "Audio System: Turning on..." << endl;
    }
    void setVolume(int level) {
        cout << "Audio System: Setting volume to " << level << "." << endl;
    }
};

// Subsystem Component 2
class VideoSystem {
public:
    void turnOn() {
        cout << "Video System: Turning on..." << endl;
    }
    void setResolution(const string& resolution) {
        cout << "Video System: Setting resolution to " << resolution << "." << endl;
    }
};

// Subsystem Component 3
class GameConsole {
public:
    void turnOn() {
        cout << "Game Console: Turning on..." << endl;
    }
    void loadGame(const string& game) {
        cout << "Game Console: Loading game \"" << game << "\"." << endl;
    }
};

// Facade Class
class HomeTheaterFacade {
private:
    AudioSystem audio;
    VideoSystem video;
    GameConsole console;

public:
    void startGamingSession(const string& game) {
        cout << "Starting Gaming Session..." << endl;
        audio.turnOn();
        audio.setVolume(50);
        video.turnOn();
        video.setResolution("1920x1080");
        console.turnOn();
        console.loadGame(game);
        cout << "Gaming Session Ready!" << endl;
    }
};

int main() {
    // Client Code
    HomeTheaterFacade homeTheater;
    homeTheater.startGamingSession("The Legend of Code");

    /* Output
    
    Starting Gaming Session...
    Audio System: Turning on...
    Audio System: Setting volume to 50.
    Video System: Turning on...
    Video System: Setting resolution to 1920x1080.
    Game Console: Turning on...
    Game Console: Loading game "The Legend of Code".
    Gaming Session Ready!
    
    */

    return 0;
}
