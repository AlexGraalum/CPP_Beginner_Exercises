//Includes
#include <iostream>

//Prototypes
int getUserInput();

//Functions
int main(int argc, char** argv) {
     int x, y = 0;

     /*std::cout << "Enter any number other than 5.\n";

     do {
          x = getUserInput();
          y++;
     } while (x != 5 && y < 10);

     if (x == 5) {
          std::cout << "Hey! You weren't supposed to enter 5!\n";
     }
     else {
          std::cout << "Wow, you're more patient than I am. You win!\n";
     }*/

     std::cout << "Enter any number other than " << y << ".\n";
     x = getUserInput();

     while (x != y) {
          y++;
          std::cout << "Enter any number other than " << y << ".\n";
          x = getUserInput();
     }

     std::cout << "Hey! You weren't supposed to enter " << y << ".\n";

     return 0;
}

////Get User Input
//Use cin to get user input
//Handle invalid user inputs
//Return valid entry
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