#include "World.h"
#include <iostream>

// Overloaded Constructor
World::World(const string& fileInput, const string& logFile) : m_fileProcessor(fileInput), m_logger(logFile){ // Takes in a file name as a parameter and initializes Logger with the file name
    // Initializing Member Variables
    m_move = true;
    m_win = false;
    m_totalMoves = 0;
    m_obstacle = 'x';
    // Processing File to Read Data
    // m_fileProcessor.processFile("CommandLines.txt");
    // Defining Member Variables with File Data 
    m_levels = m_fileProcessor.getFileData(0);
    m_dimensions = m_fileProcessor.getFileData(1);
    m_mario.setLives(m_fileProcessor.getFileData(2));
    m_probabilites[0] = m_fileProcessor.getFileData(3) /(double) 100; // Dividing by 100 to change % to decimal, typecasted as double (to avoid int division)
    m_probabilites[1] = m_fileProcessor.getFileData(4) /(double) 100;
    m_probabilites[2] = m_fileProcessor.getFileData(5) /(double) 100;
    m_probabilites[3] = m_fileProcessor.getFileData(6) /(double) 100;
    m_probabilites[4] = m_fileProcessor.getFileData(7) /(double) 100;
    // Initializing 3D Array 
    m_world = new char**[m_levels]; // Allocating memory for # of levels (# of 2D arrays)
    // Nested for loop that loops for number of levels and rows
    for (int lvls = 0; lvls < m_levels; lvls++){
        m_world[lvls] = new char*[m_dimensions]; // Allocating memory for # of rows in 2D array
        for (int rows = 0; rows < m_dimensions; rows++){ 
            m_world[lvls][rows] = new char[m_dimensions]; // Allocating memory for # of columns in 2D array
        }
    }
    // Nested for loop that loops through each level, row, and column
    for (int lvls = 0; lvls < m_levels; lvls++){
        for (int rows = 0; rows < m_dimensions; rows++){ 
            for (int cols = 0; cols < m_dimensions; cols++){
                m_world[lvls][rows][cols] = '0'; // Initializing elements 
            }
        }
    }
}
// Default Deconstructor
World::~World(){
    for (int lvl = 0; lvl < m_levels; lvl++) {
        for (int row = 0; row < m_dimensions; row++) {
            delete[] m_world[lvl][row]; // Deallocates columns
        }
        delete[] m_world[lvl]; // Deallocates rows
    }
    delete[] m_world; // Deallocates levels
}
// fillWorld Function: fills the world with objects
void World::fillWorld(){
    random_device rd; // Random number source
    mt19937 gen(rd()); // Random number generator, random device as seed
    discrete_distribution<> prob{m_probabilites[0], m_probabilites[1], m_probabilites[2], m_probabilites[3], m_probabilites[4]}; // Distribution between indicies based on each % probability 
    // Nested for loop through levels, rows, and columns 
    for (int lvl = 0; lvl < m_levels; lvl++){
        for (int row = 0; row < m_dimensions; row++){
            for (int col = 0; col < m_dimensions; col++){
                m_world[lvl][row][col] = m_objects[prob(gen)]; // Place accessed object from generated index
            }
        }
        if (lvl < m_levels - 1){ // If current level is not the last level
            m_world[lvl][prob(gen) % m_dimensions][prob(gen) % m_dimensions] = 'w'; // Place warp pipe at random row and column
        }
        m_world[lvl][prob(gen) % m_dimensions][prob(gen) % m_dimensions] = 'b'; // Place boss at random row and column
    }
}
// initializeMario Function: initializes mario at random row and column in first level
void World::initializeMario(){
    random_device rd; // Random number source
    mt19937 gen(rd()); // Random number generator, random device as seed
    uniform_int_distribution<int> distr(0, m_dimensions - 1);
    m_mario.setPosition(distr(gen), distr(gen)); // setPosition function sets Mario's row and colum position, genRandInt function randomly generated numbers within indicies range
    m_obstacle = getLevelElement(m_mario.getRow(), m_mario.getColumn()); // Sets obstacle member variable to the element at mario's position
    setLevelElement(m_mario.getRow(), m_mario.getColumn(), 'H'); // Sets a H (Mario's place holder) at the generated rows and colums from above
    m_logger.logMessage("Mario is at starting position: (" + to_string(m_mario.getRow() + 1) + ", " + to_string(m_mario.getColumn() + 1) + ").\n"); // Logs Mario's starting position
}
// initialStatus Function: logs status before gameplay
void World::initialStatus(){
    m_logger.logMessage("Level: " + to_string(m_mario.getLevel() + 1) + ".\n"); // Logs Mario's level
    m_logger.logMessage("Mario is at position: (" + to_string(m_mario.getRow() + 1) + ", " + to_string(m_mario.getColumn() + 1) + ").\n"); // Logs Mario's row and column position (int converted to string usng to_string())
    m_logger.logMessage("Mario is at power level: " + to_string(m_mario.getPowerLevel()) + ".\n"); // Logs Mario's power level 
}
// play Function: carries out gameplay rules
void World::play(){
    fillWorld();
    logLevel(); // Logs initial level status
    initializeMario(); // Initializes Mario in level
    while(m_mario.getLevel() < m_levels && m_mario.getLives() > 0){ // While Mario is not at last level and still has lives
        logLevel(); // Log level with Mario instantiated 
        initialStatus(); // Log Mario's initial level, position, and power level
        switch(m_obstacle){
            case 'm': // Mushroom
                if(m_mario.getPowerLevel() <= 2){ // If Mario's power level is less or equal to 2 (2 is max power level)
                    m_mario.increasePowerLevel(); // Increase power level
                }
                m_logger.logMessage("Mario ate a mushroom.\n");
                m_move = true; // Mario moves onto next position
                break; // Break out of switch statement
            case 'c': // Coin
                m_mario.addCoin(); // Adds 1 coin to Mario
                m_logger.logMessage("Mario collected a coin.\n");
                m_move = true;
                break;
            case 'w': // Warp Pipe
                m_mario.moveUpLevel(); // Moves Mario to next level
                m_logger.logMessage("Mario found a warp pipe.\n");
                m_move = true;
                break;
            case 'x': // Nothing
                m_logger.logMessage("Mario visited an empty space.\n");
                m_move = true;
                break;
            case 'g': // Goomba
                m_logger.logMessage("Mario encountered a goomba");
                if (m_goomba.result() == true){ // If Mario wins against Goomba
                    m_mario.addDefeat(); // Add defeat to Mario's defeat counter
                    m_logger.logMessage(" and won.\n"); // Log result
                    m_move = true; // Mario moves onto next position
                    setLevelElement(m_mario.getRow(),m_mario.getColumn(), 'x'); // Set position to x (move() skips emptying position for Goombas for when Mario loses)
                    m_obstacle = 'g';
                } else {
                    m_logger.logMessage(" and lost.\n");
                    if (m_mario.getPowerLevel() > 0){ // If Mario is not at PL0
                        m_mario.decreasePowerLevel(); // Mario drops down a power level
                        m_move = true;
                    } else { // If Mario is at PL0
                        m_move = false; // Rematch, Mario stays at current position
                        m_mario.removeLife(); // Mario loses a life
                        m_mario.setDefeats(0); // Mario's defeats are reset to 0 (defeats are counted on a single life)
                    }
                    m_logger.logMessage("Mario will stay put.\n"); 
                }
                break;
            case 'k': // Koopa Troopa
                m_logger.logMessage("Mario encountered a koopa troopa"); // Log
                if (m_goomba.result() == true){ // Mario wins
                    m_move = true; // Mario moves on
                    m_mario.addDefeat(); // Add defeat to counter
                    m_logger.logMessage(" and won.\n"); // Log result
                    setLevelElement(m_mario.getRow(),m_mario.getColumn(), 'x'); // Set position to x (move() skips emptying position for Koopa Troopas for when Mario loses)
                    m_obstacle = 'k'; // Ensure m_obstacle is still k, for switch statement to read again
                } else { // Mario loses
                    m_logger.logMessage(" and lost.\n"); // Log result
                    if (m_mario.getPowerLevel() > 0){ // Check power level > 0
                        m_mario.decreasePowerLevel(); // Drop down power level
                        m_move = true;
                    } else { // Mario is a power level 0
                        m_mario.removeLife(); // Loses Life
                        m_mario.setDefeats(0); // Defeat tracker reset
                        m_move = false; // Rematch
                    }
                    m_logger.logMessage("Mario will stay put.\n"); 
                }
                break;
            case 'b': // Boss
                m_logger.logMessage("Mario encountered a boss");
                if (m_boss.result() == true){ // Mario wins
                    m_move = true; // Mario moves on
                    if (m_mario.getLevel() == m_levels - 1){ // If Mario was at the last level
                        m_win = true; // Mario wins the game! 
                        m_move = false;
                    }
                    m_mario.moveUpLevel(); // Mario moves up a level when boss is defeated
                    m_mario.addDefeat(); //  Add defeat to counter
                    m_logger.logMessage(" and won.\n");
                } else {
                    m_logger.logMessage(" and lost.\n");
                    m_move = false; // Rematch
                    if (m_mario.getPowerLevel() > 1){ // If Mario's power level is 2 (2 is max)
                        m_mario.decreasePowerLevel(); // Drop down 2 power levels
                        m_mario.decreasePowerLevel();
                    } else {
                        m_mario.removeLife(); // Mario loses a life
                        m_mario.setDefeats(0); // Defeat tracker reset
                    }
                    m_logger.logMessage("Mario will stay put.\n"); 
                }
                break;
            default: // Default Case
                break; // Breaks out of switch statement
        }
        if (m_move == true){ // Whether Mario moves on from position (for initial position and rematches)
            move(); // Randomly moves Mario right, left, up, or down each with 25% probability, returning the object at the position
            m_totalMoves += 1; // Tracks number of Mario's moves (for Game Over Log)
        } 
        m_mario.extraLifeCheck(); // Checks if Mario has enough coins or has defeated enough enemies for an extra life
        postStatus(); // Logs Mario's status after gameplay
    }
    if (m_win == true){ // If Mario wins against final boss
        m_logger.logMessage("Mario won the Game!\nTotal Moves: " + to_string(m_totalMoves) + "\n"); // Log win and total moves it took to win
    } else {
        m_logger.logMessage("Mario lost the Game.\nTotal Moves: " + to_string(m_totalMoves) + "\n"); // Log loss and total moves 
    }
}
// logLevel Function: logs Mario's current level's objects to logger
void World::logLevel(){
    m_logger.logMessage("==========\n"); 
    for (int row = 0; row < m_dimensions; row++){ // Loop through each row
        for (int col = 0; col < m_dimensions; col++){ // Loop through each column
            m_rowStr += m_world[m_mario.getLevel()][row][col]; // Add element to string (Mario's current level is under Mario's class)
        }
        m_logger.logMessage(m_rowStr + "\n"); // Log string to logger
        m_rowStr = ""; // Reset string 
    }
    m_logger.logMessage("==========\n");
}
// postStatus Function: logs status after gameplay
void World::postStatus(){
    m_logger.logMessage("Mario has " + to_string(m_mario.getLives()) + " lives left.\n"); // Logs Mario's lives, converting int to string with to_string()
    m_logger.logMessage("Mario has " + to_string(m_mario.getCoins()) + " coins.\n"); // Logs Mario's coins ""
}
// move Function: randomly chooses direction for Mario to move in with 25% probability
void World::move(){
    if (m_obstacle != 'g' || m_obstacle != 'k'){ // If the object Mario interated with was not a Goomba or Koopa Troopa (both stay put)
        setLevelElement(m_mario.getRow(),m_mario.getColumn(), 'x'); // Sets Mario's current position to an x
    }
    random_device rd; // Random number source
    mt19937 gen(rd()); // Random number generator, random device as seed
    uniform_real_distribution<double> distr(0.0, 1.0); // Uniform distribution between 0.0 and 1.0
    double randNum = distr(gen); // Generates random double between 0.0 and 1.0,
    if (randNum < 0.25){ // If randNum is under 0.25
        up(); // Call up function
    } else if (randNum < 0.50) { // If between 0.25 and 0.50
        down(); // Call down function
    } else if (randNum < 0.75) { // If between 0.50 and 0.75
        right(); // Call right function
    } else { // If between 0.75 and 1.0
        left(); // Call left function
    }
    m_obstacle = getLevelElement(m_mario.getRow(), m_mario.getColumn()); // Sets obstacle member variable to the element at Mario's position
    setLevelElement(m_mario.getRow(), m_mario.getColumn(), 'H'); // Sets a H (Mario's place holder) at the generated rows and colums from above
}
// right Funtion: moves Mario right
void World::right(){
    if (m_mario.getColumn() == m_dimensions - 1){ // If Mario is at the right end of the column (-1 to account for 0 index)
        m_mario.setColumn(0); // Mario is set to the beginning of column
    } else { // If not 
        m_mario.setColumn(m_mario.getColumn() + 1); // Mario moves over right one column
    }
    m_logger.logMessage("Mario will move right.\n"); // Log Mario's move
}
// left Funtion: moves Mario left
void World::left(){
    if (m_mario.getColumn() == 0){ // If Mario is at the left end of the column (0 index = left end)
        m_mario.setColumn(m_dimensions - 1); // Mario is set to end of column (-1 to account for 0 index)
    } else { // If not
        m_mario.setColumn(m_mario.getColumn() - 1); // Mario moves over left one column
    }
    m_logger.logMessage("Mario will move left.\n"); // Log Mario's move
}
// up Function: moves Mario up
void World::up(){
    if (m_mario.getRow() == 0){ // If mario is at the top row
        m_mario.setRow(m_dimensions - 1); // Mario moves to bottom row (-1 to account for 0 index)
    } else { // If not
        m_mario.setRow(m_mario.getRow() - 1); // Mario moves up a row
    }
    m_logger.logMessage("Mario will move up.\n"); // Log Mario's move
}
// down Function: moves Mario down
void World::down(){
    if (m_mario.getRow() == m_dimensions - 1){ // If mario is at the bottom row 
        m_mario.setRow(0); // Mario moves to top row
    } else { // If not
        m_mario.setRow(m_mario.getRow() + 1); // Mario moves down a row
    }
    m_logger.logMessage("Mario will move down.\n"); // Log Mario's move
}
// getLevelElement Function: returns object at certain position
char World::getLevelElement(int row, int col){
    return m_world[m_mario.getLevel()][row][col]; // Returns element at Mario's current level and given row and column
}
// setLevelElement Function: sets an objecta at a certain position
void World::setLevelElement(int row, int col, char elem){
    m_world[m_mario.getLevel()][row][col] = elem; // Sets element at Mario's current level and given row and column to given element
}
