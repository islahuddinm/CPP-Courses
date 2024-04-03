#include <iostream>
#include <vector>

/* std::vector is a standard library class in C++ that represents a dynamic array. It provides functionalities
similar to arrays but with additional features such as dynamic resizing, insertion and deletion of elements at
the end, and efficient random access to elements.*/

int main() {
    // Create a vector of integers
    std::vector<int> vec;

    // Add elements to the vector
    /* push_back and emplace_back are both member functions of the std::vector class in C++ used to
    add elements to the end of a vector. However, they differ in how they add elements.
    'push_back' will call the copy constructor to create a copy of the object and add it to the vector.
    'emplace_back' directly constructs the element in the vector's memory without making a copy.*/
    vec.push_back(10); // The 'push_back' function is a member function of the 'std::vector' class in C++.
    vec.push_back(20);
    vec.push_back(30);

    std::cout << vec[0] << '\n';

    // Access elements using [] operator
    std::cout << "Elements in vector: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }

    return 0;
}

/* In this example, std::vector<int> vec; creates an empty vector of integers. push_back is used to add
elements to the vector, and the [] operator is used to access elements by index. The size() function returns
the number of elements in the vector.*/

/* Sure! Here's a list of some common methods available for various standard library containers in C++:

Common Methods for Sequential Containers (std::vector, std::list, std::deque)
push_back(const T& value): Adds an element to the end of the container.
pop_back(): Removes the last element from the container.
push_front(const T& value): Adds an element to the beginning of the container (not available for std::vector).
pop_front(): Removes the first element from the container (not available for std::vector).
insert(iterator pos, const T& value): Inserts an element at the specified position.
erase(iterator pos): Removes the element at the specified position.
clear(): Removes all elements from the container.
size(): Returns the number of elements in the container.
empty(): Returns true if the container is empty, false otherwise.
begin(), end(): Return iterators pointing to the beginning and past-the-end positions of the container, respectively.

Common Methods for Associative Containers (std::set, std::map, std::unordered_set, std::unordered_map)
insert(const T& value): Inserts an element into the container (for std::set and std::unordered_set).
insert(const std::pair<const Key, T>& pair): Inserts an element into the container (for std::map and std::unordered_map).
erase(iterator pos): Removes the element at the specified position.
erase(const Key& key): Removes the element with the specified key.
find(const Key& key): Finds an element with the specified key.
clear(): Removes all elements from the container.
size(): Returns the number of elements in the container.
empty(): Returns true if the container is empty, false otherwise.
begin(), end(): Return iterators pointing to the beginning and past-the-end positions of the container, respectively.

Common Methods for std::string
append(const std::string& str): Appends a string to the end of the current string.
insert(size_t pos, const std::string& str): Inserts a string at the specified position.
erase(size_t pos, size_t len): Erases a portion of the string starting from the specified position.
clear(): Removes all characters from the string.
size(): Returns the number of characters in the string.
empty(): Returns true if the string is empty, false otherwise.
begin(), end(): Return iterators pointing to the beginning and past-the-end positions of the string, respectively.

These are just a few of the commonly used methods for these containers.
The actual methods availablemay vary depending on the container and the version of the C++ standard library
you are using.*/