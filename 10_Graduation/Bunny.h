#pragma once
#ifndef BUNNY_H
#define BUNNY_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdlib.h>

const std::string MALE_FILE = "Resources/Male_Names.txt";
const std::string FEMALE_FILE = "Resources/Female_Names.txt";
const std::string LASTNAME_FILE = "Resources/Last_Names.txt";

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
     ~Bunny() {}

     std::string GetInfo(size_t);
     bool CanBreed();

     Sex GetSex() { return this->sex; }
     void SetSex(Sex sex) { this->sex = sex; }
     Color GetFur() { return this->fur; }
     void SetFur(Color fur) { this->fur = fur; }
     int GetAge() { return this->age; }
     void SetAge(int age) { this->age = age; }
     std::string GetName();
     void SetName(std::string name) { this->name = name; }
     bool GetRadioactive() { return this->radioactive; }
     void SetRadioactive(bool radioactive) { this->radioactive = radioactive; }
};

#endif