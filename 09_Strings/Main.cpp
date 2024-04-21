//Includes
#include <iostream>
#include <string>

//Prototypes
void zName(std::string);
void reverseName(std::string);

//Functions
int main(int argc, char** argv) {
     std::string firstName, lastName, fullName;

     std::cout << "Give a first name: ";
     std::cin >> firstName;
     std::cout << "Give a last name: ";
     std::cin >> lastName;

     fullName = firstName + " " + lastName;

     zName(fullName);
     reverseName(fullName);

     return 0;
}

////Z-Name
//Replace all vowels with z
void zName(std::string str) {
     for (int i = 0; i < str.length(); i++) {
          switch (str[i]) {
          case 'a':
          case 'e':
          case 'i':
          case 'o':
          case 'u':
               str[i] = 'z';
               break;
          default:
               break;
          }
     }

     std::cout << str << std::endl;
}

////Reverse Name
//Reverse all characters in the string
void reverseName(std::string str) {
     for (long i = 0; i < str.length() / 2; i++) {
          char temp = str[i];
          str[i] = str[str.length() - (i + 1)];
          str[str.length() - (i + 1)] = temp;
     }

     std::cout << str << std::endl;
}