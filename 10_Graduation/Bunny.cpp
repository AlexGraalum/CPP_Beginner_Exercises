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
}

Bunny::Bunny(Color momFur) {
     sex = (rand() % 2) == 0 ? Sex::MALE : Sex::FEMALE;
     fur = momFur;
     age = 0;
     name = GetRandomName(this->sex);
     radioactive = (rand() % 101) > 97 ? true : false;
}

std::string Bunny::GetRandomName(Sex sex) {
     std::ifstream firstNameFile((sex == Sex::MALE) ? MALE_FILE : FEMALE_FILE);
     std::ifstream lastNameFile(LASTNAME_FILE);

     int firstNameFileCount = 0;
     int lastNameFileCount = 0;
     std::string firstName, lastName;

     while (std::getline(firstNameFile, firstName))
          firstNameFileCount++;
     while (std::getline(lastNameFile, lastName))
          lastNameFileCount++;

     firstNameFile.clear();
     firstNameFile.seekg(0);
     lastNameFile.clear();
     lastNameFile.seekg(0);

     int r = rand() % firstNameFileCount;
     int i = 0;
     while (std::getline(firstNameFile, firstName)) {
          ++i;
          if (i == r) break;
     }

     r = rand() % lastNameFileCount;
     i = 0;
     while (std::getline(lastNameFile, lastName)) {
          ++i;
          if (i == r) break;
     }

     firstNameFile.close();
     lastNameFile.close();

     return firstName + " " + lastName;
}

std::string Bunny::GetInfo(size_t nameBuffer) {
     std::string info = "";
     int digits = 1, tempAge = age;
     while (tempAge >= 10) {
          tempAge /= 10;
          digits += 1;
     }

     info.append(this->GetName());
     info.append(nameBuffer - info.length() + 3 - digits, ' ');
     info.append(std::to_string(this->age)).append(" [");
     switch (this->sex) {
     case Sex::MALE:
          info.append("M] -- ");
          break;
     default:
          info.append("F] -- ");
          break;
     }

     switch (this->fur) {
     case Color::WHITE:
          info.append("White");
          break;
     case Color::BROWN:
          info.append("Brown");
          break;
     case Color::BLACK:
          info.append("Black");
          break;
     default:
          info.append("Spotted");
          break;
     }

     return info;
}

bool Bunny::CanBreed() {
     if (radioactive) return false;
     if (age < 2) return false;
     return true;
}

std::string Bunny::GetName() {
     std::string str = "";
     if (this->radioactive) {
          str.append("Radioactive Mutant Vampire Bunny ");
     }
     else {
          str.append("Bunny ");
     }
     str.append(this->name);
     return str;
}