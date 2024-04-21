//Includes
#include <iostream>

//Prototypes
void say_hello(int);
int product(int, int);

//Functions
int main(int argc, char** argv) {
     int x, y;
     std::cout << "Give me a number: ";
     std::cin >> x;
     say_hello(x);

     std::cout << "Give me two numbers: ";
     std::cin >> x >> y;
     std::cout << x << " * " << y << " = " << product(x, y) << std::endl;

     return 0;
}

////Say Hello
//Print "Hello" x amount of times
void say_hello(int x) {
     for (int i = 0; i < x; i++)
          std::cout << "Hello\n";
     std::cout << std::endl;
}

int product(int x, int y) {
     return x * y;
}