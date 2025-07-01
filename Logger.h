#ifndef LOGGER_H
#define LOGGER_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Logger{
    public:
        // Constructors
        Logger(const string& input);
        ~Logger();
        // Log Message Function
        void logMessage(const string& message);
    private:
        // Member Variables
        // Output File Stream
        ofstream logFile;
        // File Name String
        string fileName;
};
#endif
