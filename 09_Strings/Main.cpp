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

     for (int i = 0; i < fullName.length(); i++) {
          switch (fullName[i]) {
          case 'a':
          case 'e':
          case 'i':
          case 'o':
          case 'u':
               fullName[i] = 'z';
               break;
          default:
               break;
          }
     }

     std::cout << fullName << std::endl;

     return 0;
}