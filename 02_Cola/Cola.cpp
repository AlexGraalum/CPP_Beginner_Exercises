//Includes
#include <iostream>
#include <string>

//Prototypes
int getUserInput();

//Functions
int main() {
     int choice = 0;

     std::cout << "Welcome to the soda machine.\nPlease select your drink of choice: ";

     choice = getUserInput();

/*     if (choice == 1) {
          std::cout << "You have chosen Pepsi.";
     }
     else if (choice == 2) {
          std::cout << "You have chosen Dr. Pepper.";
     }
     else if (choice == 3) {
          std::cout << "You have chosen Fanta.";
     }
     else if (choice == 4) {
          std::cout << "You have chosen Sprite.";
     }
     else if (choice == 5) {
          std::cout << "You have chosen Water.";
     }*/

     switch (choice) {
          case 1:
               std::cout << "You have chosen Pepsi.";
               break;
          case 2:
               std::cout << "You have chosen Dr. Pepper.";
               break;
          case 3:
               std::cout << "You have chosen Fanta.";
               break;
          case 4:
               std::cout << "You have chosen Sprite.";
               break;
          case 5:
               std::cout << "You have chosen Water.";
               break;
     }

     return 0;
}

int getUserInput() {
     int x = 0;

     std::cout << ">> ";
     std::cin >> x;

     while (std::cin.fail()) {
          std::cout << "That was not an integer.\nEnter an integer from 1 to 5.\n>>";
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          std::cin >> x;
     }

     return x;
}