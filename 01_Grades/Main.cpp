//Includes
#include <iostream>

//Prototypes
int getUserInput();
void assessGrade(int);

//Functions
int main(int argc, char** argv) {
     int x = 0;
     
     std::cout << "Hello!\nPlease enter your grade [0-100]: ";

     assessGrade(getUserInput());

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

////Assess User Grade
//IF-ELSE the grade value
//Print the letter-grade based on value
void assessGrade(int grade) {
     if (grade == 100) {
          std::cout << "Congrats! You got a perfect score!";
     }
     else if ((grade >= 90) && (grade <= 99)) {
          std::cout << "Congrats! You got an A!";
     }
     else if ((grade >= 80) && (grade <= 89)) {
          std::cout << "Good job. You got a B.";
     }
     else if ((grade >= 70) && (grade <= 79)) {
          std::cout << "You got a C.";
     }
     else if ((grade >= 60) && (grade <= 69)) {
          std::cout << "You got a D. You can do better.";
     }
     else {
          std::cout << "You got an F. You need to study more.";
     }
}