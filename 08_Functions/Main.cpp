//Includes
#include <iostream>

//Prototypes
void say_hello(int);

//Functions
int main(int argc, char** argv) {
     int x;
     std::cout << "Give me a number: ";
     std::cin >> x;
     say_hello(x);
     return 0;
}

////Say Hello
//Print "Hello" x amount of times
void say_hello(int x) {
     for (int i = 0; i < x; i++)
          std::cout << "Hello";
}