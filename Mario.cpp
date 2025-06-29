#include "Mario.h"
// Default Constructor
Mario::Mario(){
    // Initializing Member Variables to 0
    m_level = 0;
    m_row = 0;
    m_column = 0;
    m_powerLevel = 0;
    m_lives = 0;
    m_coins = 0;
    m_defeats = 0;
}
// Default Deconstructor
Mario::~Mario(){
}
// Level Position Setter
void Mario::setLevel(int level){
    m_level = level;
}
// Row Position Setter
void Mario::setRow(int row){
    m_row = row;
}
// Column Position Setter
void Mario::setColumn(int column){
    m_column = column;
}
// Row & Column Position Settter
void Mario::setPosition(int row, int column){
    m_row = row;
    m_column= column;
}
// Power Level Setter
void Mario::setPowerLevel(int powerLevel){
    m_powerLevel = powerLevel;
}
// Number of Lives Setter
void Mario::setLives(int lives){
    m_lives = lives;
}
// Number of Coins Setter
void Mario::setCoins(int coins){
    m_coins = coins;
}
// Number of Defeats Setter (on single life)
void Mario::setDefeats(int defeats){
    m_defeats = 0;
}
// Level Position Getter
int Mario::getLevel(){
    return m_level;
}
// Row Postion Getter
int Mario::getRow(){
    return m_row;
}
// Column Position Getter
int Mario::getColumn(){
    return m_column;
}
// Power Level Getter
int Mario::getPowerLevel(){
    return m_powerLevel;
}
// Number of Lives Getter
int Mario::getLives(){
    return m_lives;
}
// Number of Coins Getter
int Mario::getCoins(){
    return m_coins;
}
// Number of Defeats Getter (on single life)
int Mario::getDefeats(){
    return m_defeats;
}
void Mario::moveUpLevel(){
    m_level += 1;
}
// Increase Power Level Function
void Mario::increasePowerLevel(){
    m_powerLevel += 1; // Adds 1 to power level
}
// Decrease Power Level Function
void Mario::decreasePowerLevel(){
    m_powerLevel -= 1; // Subtracts 1 from power level
}
// Add Life Function
void Mario::addLife(){
    m_lives += 1; // Add 1 to lives
}
// Remove Life Function
void Mario::removeLife(){
    m_lives -= 1; 
    m_defeats = 0; // Reset defeats to 0 each time Mario loses a life  (gameplay rules)
}
// Add Single Coin Function
void Mario::addCoin(){
    m_coins += 1;
}
// Removes Single Coin Function
void Mario::removeCoins(int coins){
    m_coins -= coins;
}
// Add Defeat Function (on single life)
void Mario::addDefeat(){
    m_defeats += 1;
}
// Gameplay Rules: Mario gains extra life if he has 20 coins or has defeated 7 enemies on a single life
// Checks for Extra Life
void Mario::extraLifeCheck(){
    if (m_coins >= 20){  // If Mario has 20 or more coins
        m_lives += 1; // Add 1 life 
        m_coins -= 20; // Subtract 20 coins from Mario's coins
    }
    if (m_defeats >= 7){ // If Mario has defeated 7 or more enemies on a single life (reset with each life removed)
        m_lives += 1; // Add 1 life
        m_defeats = 0; // Reset defeats to 0
    }
}
