#ifndef BUNNY_H
#define BUNNY_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

const std::string MALE_FILE = "resources/Male_Names.txt";
const std::string FEMALE_FILE = "resources/Female_Names.txt";

enum class Sex {MALE, FEMALE};
enum class Color {WHITE, BROWN, BLACK, SPOTTED};

class Bunny {
private:
     Sex sex;
     Color fur;
     int age;
     std::string name;
     bool radioactive;

     std::string GetRandomName(Sex);
public:
     Bunny();
     Bunny(Color);
     ~Bunny();

     void PrintInfo();

     friend std::ostream& operator<<(std::ostream& out, const Bunny& bunny);

     Sex GetSex() { return this->sex; }
     void SetSex(Sex sex) { this->sex = sex; }
     Color GetFur() { return this->fur; }
     void SetFur(Color fur) { this->fur = fur; }
     int GetAge() { return this->age; }
     void SetAge(int age) { this->age = age; }
     std::string GetName() { return this->name; }
     void SetName(std::string name) { this->name = name; }
     bool GetRadioactive() { return this->radioactive; }
     void SetRadioactive(bool radioactive) { this->radioactive = radioactive; }
};

#endif