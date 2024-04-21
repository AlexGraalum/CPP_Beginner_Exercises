//Includes
#include <iostream>
#include <string>

//Prototypes

//Functions
int main(int argc, char** argv) {
     std::string firstName, lastName, fullName;

     std::cout << "Give a first name: ";
     std::cin >> firstName;
     std::cout << "Give a last name: ";
     std::cin >> lastName;

     fullName = firstName + " " + lastName;

     std::cout << fullName << std::endl;

     return 0;
}