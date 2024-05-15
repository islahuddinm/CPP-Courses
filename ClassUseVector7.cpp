#include <iostream>
#include <vector>

// Function to create and initialize a vector
std::vector<int>& createAndInitializeVector() {
    static std::vector<int> vec = {1, 2, 3};
    return vec;
}

class MyClass {
public:
    // Member function to add an element to the vector
    void addElement(int element) {
        std::vector<int>& vec = createAndInitializeVector();
        vec.push_back(element);
    }

    // Member function to print all elements in the vector
    void printElements() {
        std::vector<int>& vec = createAndInitializeVector();
        for (int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyClass obj;

    // Using the class member functions to manipulate the vector
    obj.addElement(10);
    obj.addElement(20);
    obj.addElement(30);

    obj.printElements();  // Output: 1 2 3 10 20 30

    return 0;
}
