#include "Logger.h"

Logger::Logger(std::string fileName) {
     //this->fileName = fileName;
     this->file = std::fstream(fileName, std::ios::out | std::ios::trunc);
}

Logger::~Logger() {
     this->file.close();
}

void Logger::AddToLog(std::string str) {
     logBuffer.push_back(str);
}

void Logger::AddToLogFront(std::string str) {
     logBuffer.insert(logBuffer.begin(), str);
}

void Logger::LogOut() {
     for (auto& l : logBuffer) {
          std::cout << l << std::endl;
          this->file << l << std::endl;
     }
     logBuffer.clear();
}