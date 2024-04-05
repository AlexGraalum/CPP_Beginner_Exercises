//Includes
#include <iostream>
#include <stdlib.h>
#include <time.h>

//Defines
#define compguess

//Prototypes
int getUserInput();

//Functions
int main(int argc, char** argv) {

#ifndef compguess
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
#else
     int ready, guess, correct, count = 0;
     std::srand(static_cast<unsigned int>(time(NULL)));
     
     std::cout << "Think of a number from 1 to 100, and I'll try to guess that number.\nType 1 when you're ready.\n";
     ready = getUserInput();

     while (ready != 1) {
          ready = getUserInput();
     }

     do {
          count++;

          guess = rand() % 100 + 1;
          std::cout << "Is your number " << guess << "?\n0: Too Low; 1: Correct; 2: Too High\n";
          correct = getUserInput();

          while ((correct < 0) && (correct > 2)) {
               correct = getUserInput();
          }
     } while (correct != 1);

     std::cout << "It took me " << count << " guesses to guess correctly.\n";

#endif
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