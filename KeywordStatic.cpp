// C++ program to demonstrate
// the use of static Static
// variables in a Function
#include <iostream>
#include <string>
using namespace std;

/* Static Variables
In C++, a static variable declared inside a function is used to retains its value between function calls.
static variables are initialized only once and retain their value until the end of the program.*/
 
void demo()
{
    // static variable
    static int count = 0;
    cout << count << " "; 
    
    count++;
}
 
int main() {

    //while(int a = 0 < 2) {

        int i = 0;
        
        while(i < 5) {
            
            int count = 0;
            count += 1;
            
            std::cout << "count : " << count << '\n';            
            i++;
        }

        int ii = 0;

        while(ii < 5) {
            
            static int count = 0;
            count += 1;
            
            std::cout << "count2 : " << count << '\n';            
            ii++;
        }

        //break;
    //}
        
    demo();
    demo();
    demo();

    return 0;
}