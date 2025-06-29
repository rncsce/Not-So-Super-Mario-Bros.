#ifndef MARIO_H
#define MARIO_H

class Mario{
    public:
        // Constructors
        Mario();
        ~Mario();
        // Setters
        void setLevel(int level);
        void setRow(int row);
        void setColumn(int column);
        void setPosition(int row, int column);
        void setPowerLevel(int powerLevel);
        void setLives(int lives);
        void setCoins(int coins);
        void setDefeats(int defeats);
        // Getters
        int getLevel();
        int getRow();
        int getColumn();
        int getPowerLevel();
        int getLives();
        int getCoins();
        int getDefeats();
        // Functions
        void moveUpLevel();
        void increasePowerLevel();
        void decreasePowerLevel();
        void addLife();
        void removeLife();
        void addCoin();
        void removeCoins(int coins);
        void addDefeat();
        void extraLifeCheck();
    private:
        // Member Variables
        // Level Position
        int m_level;
        // Row Position
        int m_row;
        // Column Position
        int m_column;
        // Power Level
        int m_powerLevel;
        // Number of Lives
        int m_lives;
        // Number of Coins
        int m_coins;
        // Number of Defeats (on single life)
        int m_defeats;
};
#endif
