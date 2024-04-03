//Includes
#include <iostream>

int getUserInput();

//Functions
int main(int argc, char** argv) {
     int x = 0;
     
     std::cout << "Hello!\nPlease enter your grade [0-100]: ";

     x = getUserInput();

     if ((x >= 90) && (x <= 100)) {
          std::cout << "Congrats! You got an A!\n";
     }

     return 0;
}

////Get User Input
//Use cin to get user input
//Handle invalid user inputs
//Return valid entry
int getUserInput() {
     int x = 0;

     std::cin >> x;

     while (std::cin.fail()) {
          std::cout << "That was not an integer. Enter an integer from 0 to 100: ";
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          std::cin >> x;
     }

     if ((x < 0) || (x > 100)) {
          std::cout << "That entry is not within the valid bounds. Please keep the entry from 0 to 100: ";
          std::cin.clear();
          std::cin.ignore(INT_MAX, '\n');
          return getUserInput();
     }

     return x;
}