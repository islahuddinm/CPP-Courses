#include <iostream>
#include <string>


/* Interface: A special kind of abstract class that typically only contains pure virtual functions and
no data members or implemented functions. Interface cannot be used to create object.
Abstract Class: A class that contains at least one pure virtual function. in abstract there can be data members
but in interface is nothing. abstract class cannot be used to create object.

an interface is indeed a type of abstract class, but not all abstract classes are interfaces. */


// Abstract class or interface from your code
class StreamInsertable {    // "std::ostream& out" is used to store "std::cout".
                            // "StreamInsertable& operand" is used to store "object".
    friend std::ostream& operator<< (std::ostream& out, const StreamInsertable& operand) {
        operand.stream_insert(out);
        return out; // "return out;" which allows chaining of stream operations (e.g., ' std::cout << person << std::endl; ')
    }/*
    - friend keyword allows this function to access the private and protected members of StreamInsertable.
    However, in this context, it’s mainly used to access the protected pure virtual function stream_insert.
    - operator<< function takes two parameters: a reference to an std::ostream object (out) and a
    constant reference to a StreamInsertable object (operand).
    - Inside the function, it calls operand.stream_insert(out);, which is the key operation.
    This line invokes the stream_insert method of the operand object, passing the std::ostream reference (out)
    as an argument. This means the actual insertion of content into the stream is handled by
    the stream_insert method, which must be implemented by derived classes.
    - After calling stream_insert, the operator<< function returns the stream object out, which allows
    chaining of stream operations (e.g., std::cout << obj1 << obj2;). */



public:
    virtual void stream_insert(std::ostream& out) const = 0;  // Pure virtual function
    /*
    - This "virtual void stream_insert(std::ostream& out) const = 0;" is a pure virtual function,
    making StreamInsertable an abstract class. Derived classes must implement this function to define
    how they should be inserted into an output stream.
    - The const keyword indicates that this function does not modify the object it’s called on.
    - The implementation of this function in derived classes will be responsible for inserting the
    appropriate content into the stream. */
};

// Concrete class inheriting from StreamInsertable
class Person : public StreamInsertable {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Implement the pure virtual function
    void stream_insert(std::ostream& out) const override { // "std::ostream& out" is used to store "std::cout".
        out << "Person(Name: " << name << ", Age: " << age << ")";
    }
};

int main() {
    Person person("Alice", 30);

    // This will call the stream_insert method and output the formatted string
    std::cout << person << std::endl;
    operator<<(std::cout, person); // another way to print "operator function".
    operator<<(std::cout, person) << std::endl; // another way to print "operator function" with "endl".

    /*
    operator<<(std::cout, person); its parameters are passed to

    this
    friend std::ostream& operator<< (std::ostream& out, const StreamInsertable& operand) {
        operand.stream_insert(out);
        return out;
    }
    then it is passed to

    this
    void stream_insert(std::ostream& out) const override {
        out << "Person(Name: " << name << ", Age: " << age << ")";
    }
    */

    return 0;
}
