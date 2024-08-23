#include <iostream>

/* in this file we just want to see
if we call most 'special(derived class)', default constructors in other classes are going to be called in
inheritance hierarchy even though we dont call them. it is going to call starting
from most basic class(base class) going down to 'most special(derived class)' that we call.*/

class employee {
private:
    std::string name;
    std::string company;
    int age;

public:
    std::string address;
    std::string hobby;

public:
    std::string getName() {
        return this->name;        
    }
    std::string getCompany() {        
        return this->company;
    }
    int getAge() {  
        return this->age;
    }
    
    employee() {
        std::cout << "Default consturctor for Employee called......\n";
    }
    employee(std::string nameParam, std::string companyParam, int ageParam) {
        name = nameParam;
        company = companyParam;
        age = ageParam;
    }
        
    void introduceYourself() {
        std::cout << "Name : " << name << '\n';
        std::cout << "Company : " << company << '\n';
        std::cout << "Age : " << age << '\n' << '\n';
    }    

    //employee::going;
//private:
    int going() {
        std::cout << "-------------Go------------\n";
        return 0;        
    }
};


class developer : public employee {
public:
    std::string favProgrammingLanguage;

    developer() {
        std::cout << "Default consturctor for Developer called......\n";
    }
    developer(std::string nameParam, std::string companyParam, int ageParam, std::string favProgrammingLanguageParam) : employee(nameParam, companyParam, ageParam) { // constructor
        favProgrammingLanguage = favProgrammingLanguageParam;
    }
    
    void fixBug() {
        std::cout << getName() << " fix bug using " << favProgrammingLanguage << '\n';
    }
};


class engineer : public employee {
public:  

    using employee::employee; // this is how to inherit default and custom constructor from base class.
    // **notation** copy constructor is not inheritable.

    // this is custom constructor
    /* engineer(std::string nameParam, std::string companyParam, int ageParam) : employee(nameParam, companyParam, ageParam) { // default constructor        
    } */   
    
    void work() {
        std::cout << getName() << " is working " << '\n';
    }

//private:
    void go() {
        std::cout << "-------------Go------------\n";
    }
};


class civilEngineer : public engineer {
public:

    civilEngineer() {
        std::cout << "Default consturctor for Civil Employee called......\n";
    }
    civilEngineer(std::string nameParam, std::string companyParam, int ageParam) : engineer(nameParam, companyParam, ageParam) { // default constructor        
    }   
    
    void work() {
        std::cout << going() << " is working in " << getCompany() <<'\n';
    }
};


int main() {

    engineer A1; // create object of engineer class by inherit default and custom constructor from base class.

    //employee B2("Engineer", "Google", 40);

    civilEngineer employee5("Civil Engineer", "Starlink", 40);
    employee5.work();

    std::cout << "----------------------------------\n";

    civilEngineer C3; // this calls 'most special(derived class)'.

    //std::cout << C3.engineer::go() << '\n'; // error

    return 0;
}