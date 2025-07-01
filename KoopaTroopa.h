#ifndef KOOPATROOPA_H
#define KOOPATROOPA_H
#include "Enemy.h"

class KoopaTroopa : public Enemy {
    public:
        // Implementation of Abstract Function
        bool result() override;
    private:
        // Winning Probability
        double m_probability = 0.65;
};
#endif
