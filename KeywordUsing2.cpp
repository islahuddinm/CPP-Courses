#include <iostream>

//compiler will always start to read top project to below then start to working in main fuction (int main)

//namespace (A namespace in C++ is a feature used to organize code into logical groups and prevent name collision)

/* 'using' keyword can be used to bring specific names from a namespace/an identifier into the current scope.
for example 'using namespace std;'.*/

namespace first{
    int x = 2;
}

namespace second{
    int x = 3;
}

int main(){
    
    using namespace first;
    using std::string;
    using std::cout;

    string character = "I have ";
   
    cout << character << x + second::x << '\n';

    return 0; //a way for main function send the message to user that this task is success or there are problems.
}