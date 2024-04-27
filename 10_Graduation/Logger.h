#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <chrono>
#include <thread>

#define LOG_TIME_MS 1000

class Logger {
private:
     std::fstream file;
     std::vector<std::string> logBuffer;
     float speedMul;
public:
     Logger();
     Logger(std::string);
     ~Logger();

     void AddToLog(std::string);
     void AddToLogFront(std::string);
     void LogOut();

     void SetSpeedMul(float speedMul) { this->speedMul = speedMul; }
     float GetSpeedMul() { return this->speedMul; }
};
#endif