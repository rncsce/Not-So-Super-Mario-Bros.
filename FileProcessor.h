#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class FileProcessor{
    public:
        // Default Constructor
        FileProcessor();
        // Overloaded Constructor
        FileProcessor(const string& inputFile);
        // Default Deconstructor
        ~FileProcessor();
        // Processes a file for reading
        void processFile(const string inputFile);
        // Returns element of file data at given index
        int getFileData(int index);
    private: 
        // Array of file data (each line stored as one element)
        int m_fileData[8];
        // String read from file
        string m_line;
        // Index counter for array
        int m_index = 0;
};
#endif
