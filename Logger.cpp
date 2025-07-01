#include "Logger.h"
#include <iostream>
using namespace std;

// **Begin Code from Dr. Eel's Notion Notes - Logger Bank Account Example: https://dreel.notion.site/File-Processing-184708fc052180f5b6f9f629c0be46ba**
// Overloaded Constructor
Logger::Logger(const string& file) : fileName(file) { // Takes in reference to file name and sets it to the file name member variable
    logFile.open(fileName, ios::app); // Opens file in append mode
    if (!logFile.is_open()) { // If the file is not open
        cerr << "Unable to open file for writing." << endl; // Outputs file is unable to open
    } else {
        logFile << "Game Started.\n"; // If file opens logs the game started
    }
}
// Default Deconstructor
Logger::~Logger() { 
    if (logFile.is_open()) { // If file is open
        logFile << "Game Over.\n"; // Log the game is over
        logFile.close(); // Close file
    }
}
// logMessage Function: logs messages to logger
void Logger::logMessage(const string& message) { // Takes in string as reference
    if (logFile.is_open()) { // If the file is open
        logFile << message; // Output message to logger
    } else { // If not
        cerr << "Unable to open file for logging." << endl; // Outputs file is unable to open
    }
}
// **End Code from Dr. Eel's Notion Notes - Logger Bank Account Example: https://dreel.notion.site/File-Processing-184708fc052180f5b6f9f629c0be46ba**
