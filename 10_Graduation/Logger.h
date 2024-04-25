#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Logger {
private:
     //std::string fileName;
     std::fstream file;
     std::vector<std::string> logBuffer;
public:
     Logger(std::string);
     ~Logger();

     void AddToLog(std::string);
     void AddToLogFront(std::string);
     void LogOut();
};
#endif