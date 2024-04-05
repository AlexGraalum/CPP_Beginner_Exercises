//Includes
#include <iostream>
#include <stdlib.h>
#include <time.h>

//Prototypes
int getUserInput();

//Functions
int main(int argc, char** argv) {
     int num, guess, count = 0;
     std::srand(static_cast<unsigned int>(time(NULL)));

     num = rand() % 100 + 1;

     std::cout << "Guess what number I'm thinking of.\n";
     guess = getUserInput();

     while (guess != num) {
          count++;
          if (guess > num) {
               std::cout << "That's too high. Try again.\n";
          }
          else {
               std::cout << "That's too low. Try again.\n";
          }

          guess = getUserInput();
     }

     std::cout << "Well done! You guessed the correct number in " << count << " guesses.\n";

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