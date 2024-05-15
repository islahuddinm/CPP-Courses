#include <iostream>
#include <vector>

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

std::vector<int> globalVector;  // Vector defined outside of main and class

int main() {
    MyClass obj;

    // Using the class member functions to manipulate the global vector
    obj.addElement(globalVector, 10);
    obj.addElement(globalVector, 20);
    obj.addElement(globalVector, 30);

    obj.printElements(globalVector);  // Output: 10 20 30

    return 0;
}
