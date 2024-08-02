#include <algorithm>
#include <vector>
#include <iostream>

// std::find is used for finding the first occurrence of a value within a range.

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};

    auto it = std::find(vec.begin(), vec.end(), 9);

    if(it != vec.end())
        std::cout << "Found: " << *it << std::endl;  // Output: Found: 9
    else
        std::cout << "Not Found" << std::endl;
}
