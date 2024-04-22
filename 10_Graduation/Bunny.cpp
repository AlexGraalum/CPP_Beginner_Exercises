#include "Bunny.h"

Bunny::Bunny() {
     sex = (rand() % 2) == 0 ? Sex::MALE : Sex::FEMALE;
     switch (rand() % 4) {
     case 0:
          fur = Color::WHITE;
          break;
     case 1:
          fur = Color::BROWN;
          break;
     case 2:
          fur = Color::BLACK;
          break;
     default:
          fur = Color::SPOTTED;
          break;
     }
     age = 0;
     name = GetRandomName(this->sex);
     radioactive = (rand() % 101) > 97 ? true : false;

     std::cout << *this << " was born!\n";
}

Bunny::Bunny(Color momFur) {
     sex = (rand() % 2) == 0 ? Sex::MALE : Sex::FEMALE;
     fur = momFur;
     age = 0;
     name = GetRandomName(this->sex);
     radioactive = (rand() % 101) > 97 ? true : false;

     std::cout << *this << " was born!\n";
}

Bunny::~Bunny() {
     std::cout << *this << " has died!\n";
}

std::string Bunny::GetRandomName(Sex sex) {
     std::ifstream file((sex == Sex::MALE) ? MALE_FILE : FEMALE_FILE);
     int lineCount = 0;
     std::string line;
     while (std::getline(file, line))
          lineCount++;
     file.clear();
     file.seekg(0);

     int r = rand() % lineCount;
     int i = 0;
     while (std::getline(file, line)) {
          ++i;
          if (i == r) {
               break;
          }
     }
     return line;
}

void Bunny::PrintInfo() {
     std::cout << "Name: " << this->name << std::endl;
     std::cout << "\tSex: " << ((this->sex == Sex::MALE) ? "M" : "F");
     std::cout << "\tAge: " << this->age << std::endl;
     std::cout << "\tFur: ";
     switch (this->fur) {
     case Color::WHITE:
          std::cout << "White\n";
          break;
     case Color::BROWN:
          std::cout << "Brown\n";
          break;
     case Color::BLACK:
          std::cout << "Black\n";
          break;
     default:
          std::cout << "Spotted\n";
          break;
     }
     std::cout << "Radioactive Vampire Mutant: " << ((this->radioactive) ? "Yes\n" : "No\n");
}

std::ostream& operator<<(std::ostream& out, const Bunny& bunny) {
     if (bunny.radioactive) {
          out << "Radioactive Mutant Vampie Bunny ";
     }
     else {
          out << "Bunny ";
     }
     out << bunny.name;
     return out;
}