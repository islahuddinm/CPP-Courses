#include <algorithm>
#include <vector>
#include <iostream>

// std::sort is used for sorting a range of elements.

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};

    std::sort(vec.begin(), vec.end());

    for(int n : vec)
        std::cout << n << ' ';  // Output: 1 2 5 5 6 9
}
