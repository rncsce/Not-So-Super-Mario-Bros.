#ifndef WORLD_H
#define WORLD_H
#include "FileProcessor.h"
#include "Logger.h"
#include "Mario.h"
#include "KoopaTroopa.h"
#include "Goomba.h"
#include "Boss.h"
#include <random>
using namespace std;

class World{

    public:
        // Overloaded Constructor
        World(const string& fileInput, const string& logFile);
        ~World();
        // Play Function
        void play();
    private:
        // Member Variables
        // Dimensions of Rows and Columns
        int m_dimensions;
        // Number of Levels in World
        int m_levels;
        // 3D Array of Levels, Rows, and Columns
        char*** m_world = nullptr;
        // Array of Probabilites for Each Object (correlated to in order)
        double m_probabilites[5];
        // Array of Objects (correlated to in order)
        char m_objects[5] = {'c', 'x', 'g', 'k', 'm'};
        // Whether Mario Moves On
        bool m_move; 
        // Whether Mario Won Last Level
        bool m_win;
        // Total Number of Moves
        int m_totalMoves;
        // Encountered Object by Mario
        char m_obstacle;
        string m_rowStr;
        // Objects
        Mario m_mario;
        FileProcessor m_fileProcessor;
        Logger m_logger;
        KoopaTroopa m_koopaTroopa;
        Goomba m_goomba;
        Boss m_boss;
        // Helper Functions
        void initializeMario();
        void fillWorld();
        void logLevel();
        void initialStatus();
        void postStatus();
        int genRandInt();
        void move();
        void right();
        void left();
        void up();
        void down();
        char getLevelElement(int row, int col);
        void setLevelElement(int row, int col, char elem);
};
#endif
