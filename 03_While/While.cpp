//Includes
#include <iostream>

//Prototypes
int getUserInput();

//Functions
int main(int argc, char** argv) {
     int x;

     std::cout << "Enter any number other than 5.\n";

     do {
          x = getUserInput();
     } while (x != 5);

     std::cout << "Hey! You weren't supposed to enter 5!\n";

     return 0;
}

int getUserInput() {
     int x = 0;

     std::cout << ">> ";
     std::cin >> x;

     while (std::cin.fail()) {
          std::cout << "That was not an integer.\nEnter an integer.\n>> ";
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          std::cin >> x;
     }

     return x;
}