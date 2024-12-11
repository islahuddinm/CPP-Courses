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
Design Pattern: Composite Pattern
a structural design pattern that lets you compose(menyusun) objects into tree structures and
then work with these structures as if they were individual objects.

Problem:
1. Need to represent(mewakili) a hierarchical structure of objects, such as a tree-like structure
    (e.g., file systems, GUI components).
2. Allow clients to treat individual objects and compositions (groups of objects) uniformly.

Solution:
1. Define a common interface (Component) for both individual objects (leaf nodes) and
    compositions (composite nodes).
2. Implement "leaf" classes for individual objects.
3. Implement a "composite" class to hold and manage child components.

Use in Unreal Engine:

*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Component Interface
class FileSystemComponent {
public:
    virtual void showDetails(int indentation = 0) const = 0; // Pure virtual function
    virtual ~FileSystemComponent() = default;
};

// Leaf: Represents individual items (e.g., files)
class File : public FileSystemComponent {
private:
    string name;
public:
    // If you dont know "explicit" keyword, look at "KeywordExplicit.cpp"
    explicit File(const string& name) : name(name) {}
    
    void showDetails(int indentation = 0) const override {
        cout << string(indentation, ' ') << "File: " << name << endl;
    }
};

// Composite: Represents a collection of components (e.g., folders)
class Folder : public FileSystemComponent {
private:
    string name;
    vector<shared_ptr<FileSystemComponent>> children; // Holds child components
public:
    explicit Folder(const string& name) : name(name) {}
    
    void add(const shared_ptr<FileSystemComponent>& component) {
        children.push_back(component);
    }

    void showDetails(int indentation = 0) const override {
        cout << string(indentation, ' ') << "Folder: " << name << endl;
        for (const auto& child : children) {
            child->showDetails(indentation + 2); // Indent children
        }
    }
};

// Client Code
int main() {
    // Create files
    auto file1 = make_shared<File>("file1.txt");
    auto file2 = make_shared<File>("file2.docx");
    auto file3 = make_shared<File>("file3.pdf");

    // Create folders
    auto folder1 = make_shared<Folder>("Documents");
    auto folder2 = make_shared<Folder>("Pictures");
    auto rootFolder = make_shared<Folder>("Root");

    // Add files to folders
    folder1->add(file1);
    folder1->add(file2);
    folder2->add(file3);

    // Add folders to root
    rootFolder->add(folder1);
    rootFolder->add(folder2);

    // Show details of the file system
    rootFolder->showDetails();

    return 0;
}
