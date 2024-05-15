/* #include <iostream>
#include <vector>

////////////////////// Passing the Vector as an Argument ///////////////////////////

class MyClass {
public:
    // Member function to add an element to an external vector
    void addElement(std::vector<int>& vec, int element) {
        vec.push_back(element);
    }

    // Member function to print all elements in an external vector
    void printElements(const std::vector<int>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }
};

std::vector<int> globalVector = {1, 2, 3};  // Vector defined and initialized outside of main and class

int main() {
    MyClass obj;

    // Using the class member functions to manipulate the global vector
    obj.addElement(globalVector, 10);
    obj.addElement(globalVector, 20);
    obj.addElement(globalVector, 30);

    obj.printElements(globalVector);  // Output: 1 2 3 10 20 30

    return 0;
} */



////////////////////// Using a Globally Accessible Vector ///////////////////////////

#include <iostream>
#include <vector>

std::vector<int> globalVector = {1, 2, 3};  // Vector defined and initialized outside of main and class

class MyClass {
public:
    // Member function to add an element to the global vector
    void addElement(int element) {
        globalVector.push_back(element);
    }

    // Member function to print all elements in the global vector
    void printElements() {
        for (int i = 0; i < globalVector.size(); ++i) {
            std::cout << globalVector[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyClass obj;

    // Using the class member functions to manipulate the global vector
    obj.addElement(10);
    obj.addElement(20);
    obj.addElement(30);

    obj.printElements();  // Output: 1 2 3 10 20 30

    return 0;
}
