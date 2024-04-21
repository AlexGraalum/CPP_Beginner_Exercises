//Includes
#include <iostream>

//Prototypes
void say_hello(int);
int product(int, int);
void half(int);

//Functions
int main(int argc, char** argv) {
     int x, y;
     std::cout << "Give me a number: ";
     std::cin >> x;
     say_hello(x);

     std::cout << "Give me two numbers: ";
     std::cin >> x >> y;
     std::cout << x << " * " << y << " = " << product(x, y) << std::endl;

     std::cout << "Give me one more number: ";
     std::cin >> x;
     half(x);

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

void half(int x) {
     std::cout << x << std::endl;
     x /= 2;
     if (x > 0) half(x);
}