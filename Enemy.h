#ifndef ENEMY_H
#define ENEMY_H
#include <random>

class Enemy{
    public:
        // Abstract Function
        virtual bool result() = 0;
    protected:
        // Inherited Function
        bool probability(double probability);
};
#endif
