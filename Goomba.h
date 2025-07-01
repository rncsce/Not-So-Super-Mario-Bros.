#ifndef GOOMBA_H
#define GOOMBA_H
#include "Enemy.h"

class Goomba : public Enemy {
    public:
        // Implementation of Abstract Function
        bool result() override;
    private:
        // Winning Probability
        double m_probability = 0.80;
};
#endif
