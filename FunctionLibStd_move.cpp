/*

"std::move()" is a function from the "<utility>" header that casts an object to an rvalue reference.
It is commonly used to enable move semantics, which can improve performance by
avoiding unnecessary deep copies of objects.

Key Features:
    1. Rvalue Reference:
        - An rvalue reference (indicated by &&) allows resources (like dynamically allocated memory) to be
            transferred from one object to another without copying them.
        - std::move() casts an object to an rvalue reference, signaling that its resources can be "moved."
    
    2. Purpose:
        - It indicates that you no longer need the original object, so its resources can be safely transferred.
        - It does not actually "move" anything—it merely(hanya) enables move semantics when used with
            move constructors or move assignment operators.

Example of std::move():
    
    Without Move Semantics (Copying)
    
    #include <iostream>
    #include <vector>

    int main() {
        std::vector<int> vec1 = {1, 2, 3, 4};
        std::vector<int> vec2 = vec1; // Copy: vec1's data is duplicated into vec2
        return 0;
    }

Misuse of std::move():
    
    You should avoid using std::move() on objects you might still need. For instance:
   
    std::string s = "Hello";
    std::string s2 = std::move(s);

    // s is now in a valid but unspecified state
    std::cout << s; // Dangerous: s might not contain valid data

Key Points:
    
    1. std::move() Does Not Move:
        It only performs a type cast to an rvalue reference (T&&). The actual move happens
        if the object has a move constructor or move assignment operator.
    
    2. When to Use:

        Use std::move() when:
        - You want to transfer ownership of resources (e.g., dynamically allocated memory).
        - The object you're passing won't be needed afterward.
    
    3. Not Always Necessary:
        std::move() is unnecessary when dealing with temporary objects (rvalues) because
        they already qualify for move semantics.

*/

#include <iostream>
#include <vector>

// Example with std::move()
int main() {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = std::move(vec1); // Move: vec1's data is transferred to vec2

    std::cout << "vec1 size after move: " << vec1.size() << std::endl; // vec1 is now empty
    return 0;
}
