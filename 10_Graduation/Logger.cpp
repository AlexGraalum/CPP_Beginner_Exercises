#include "Logger.h"

Logger::Logger() {
     time_t curr_time;
     tm curr_tm;
     char timeString[25];
     time(&curr_time);
     localtime_s(&curr_tm, &curr_time);
     strftime(timeString, 25, "%Y_%m_%d-%H_%M_%S.txt", &curr_tm);

     this->file = std::fstream(std::string(timeString), std::ios::out);
     this->speedMul = 1.0;
}

Logger::Logger(std::string fileName) {
     this->file = std::fstream(fileName, std::ios::out | std::ios::trunc);
     this->speedMul = 1.0;
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

          if (l != "" ) std::this_thread::sleep_for(std::chrono::milliseconds(int(LOG_TIME_MS / speedMul)));
     }
     logBuffer.clear();
}