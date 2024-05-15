#include <iostream>
#include <vector>

// Function to create and initialize a vector
std::vector<int> createAndInitializeVector() {
    std::vector<int> vec = {1, 2, 3};
    return vec;
}

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

int main() {
    MyClass obj;
    std::vector<int> myVector = createAndInitializeVector();  // Call function to get initialized vector

    // Using the class member functions to manipulate the vector
    obj.addElement(myVector, 10);
    obj.addElement(myVector, 20);
    obj.addElement(myVector, 30);

    obj.printElements(myVector);  // Output: 1 2 3 10 20 30

    return 0;
}
