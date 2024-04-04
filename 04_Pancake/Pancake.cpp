//Includes
#include <iostream>

//Prototypes
int getUserInput();

//Functions
int main(int argc, char** argv) {
     int cakes[10] = {};

     std::cout << "How many pancakes did each person eat?\n";

     for (int i = 0; i < 10; i++) {
          std::cout << "Person " << i + 1;
          cakes[i] = getUserInput();
     }

     int most = 0, a = 0;
     int least = INT_MAX, b = 0;

     for (int i = 0; i < 10; i++) {
          if (cakes[i] > most) {
               most = cakes[i];
               a = i+1;
          }

          if (cakes[i] < least) {
               least = cakes[i];
               b = i+1;
          }
     }

     std::cout << "Person " << a << " ate the most at " << most << " pancakes.\n";
     std::cout << "Person " << b << " ate the least at " << least << " pancakes.\n";

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