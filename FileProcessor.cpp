#include "FileProcessor.h"

// Default Constructor
FileProcessor::FileProcessor(){
    for (int i = 0; i < 8; ++i){
        m_fileData[i] = 0;
    }
}
// Overloaded Constructor // Takes in input file as a parameter, calling processFile function on file
FileProcessor::FileProcessor(const string& inputFile){
    processFile(inputFile);
}
// Deconstructor
FileProcessor::~FileProcessor(){
}
// processFile Function: takes in a file name and stores file data
void FileProcessor::processFile(const string inputFile){ 
    // Input stream that opens file parameter inputFile as inFile
    ifstream inFile(inputFile);
    if (inFile.is_open()){ // Opens file
        while(getline(inFile, m_line) && m_index < 8){ // While getline reads lines in file and index counter is less than 8 (array size)
            m_fileData[m_index] = stoi(m_line); // Convert string read to int and store to m_fileData array's current index
            m_index++; // Add one to index counter
        }
    } else { 
        cout << "Error Reading File." << endl; // If unable to open file, output message
    }
    inFile.close(); // Close file once file has been read
}
// getFileData Function: accesses element of file data array of given index
int FileProcessor::getFileData(int index){
    return m_fileData[index];
}
