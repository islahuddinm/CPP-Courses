// C++ program to demonstrate working of malloc()

// cstdlib is used to use malloc function
#include <cstdlib>
#include <iostream>
using namespace std;

/* Memory Management Functions

malloc() - Allocates memory on the heap (from the C library).
free() - Deallocates memory allocated by malloc (from the C library).
new - Allocates memory on the heap in C++.
delete - Deallocates memory allocated by new in C++.*/

int main()
{
	// size_t is an integer data type which can assign
	// greater than or equal to 0 integer values
	size_t s = 0; // s is SIZE

	// malloc declaration/initialization
	int* ptr = (int*)malloc(s);

	// return condition if the memory block is not
	// initialized
	if (ptr == NULL) {
		cout << "Null pointer has been returned";
	}

	// condition printing the message if the memory is
	// initialized
	else {
		cout << "Memory has been allocated at address "
			<< ptr << endl;
	}

	free(ptr);
	return 0;
}
