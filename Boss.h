#ifndef BOSS_H
#define BOSS_H
#include "Enemy.h"

class Boss : public Enemy {
    public:
        // Implementation of Abstract Function
        bool result() override;
    private:
        // Winning Probability
        double m_probability = 0.50;
};
#endif
