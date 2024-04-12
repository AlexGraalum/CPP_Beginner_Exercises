//Includes
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>

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
     int input, count = 0, high = 100, low = 1;
     std::default_random_engine generator;
     
     std::cout << "Think of a number from 1 to 100, and I'll try to guess that number.\nType 1 when you're ready.\n";

     while (getUserInput() != 1) {}

     do {
          count++;

          //Number: 27                       int diff = high - low + 1;
          // Low: 1, High: 100               if (diff % 2 == 0) --diff;
          // Diff: H - L = 99                int guess = (diff / 2) + low;
          //Guess: Diff / 2 = 49.5 -> 50     std::cout << guess;
          // Too High                        int correct = getUserInput();
          // High = Guess - 1 = 49           if (correct == 1){ //Too Low
          // Low: 1, High: 49                     low = guess + 1;
          // Diff = H - L = 48               } else if (correct == 2){ //Too High
          //Guess: Diff / 2 = 24                  high = guess - 1;
          // Too Low                         }
          // Low = Guess + 1 = 25
          // Low = 25, High = 49
          // Diff = H - L = 24
          //Guess: Diff / 2 = 12

          int diff = high - low + 1;
          if (diff % 2 == 0) --diff;
          int guess = (diff / 2) + low;
          std::cout << "DEBUG: High = " << high << " -- Low = " << low << std::endl;
          std::cout << "Is your number " << guess << "?\n1: Too Low; 2: Too High; 3: Correct\n";
          input = getUserInput();

          while ((input < 1) && (input > 3)) {
               input = getUserInput();
          }

          //Too Low
          if (input == 1) {
               low = guess + 1;
          }
          //Too High
          else if (input == 2) {
               high = guess - 1;
          }

     } while (input != 3);


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