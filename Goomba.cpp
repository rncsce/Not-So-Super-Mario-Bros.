#include "Goomba.h"
// result Function: returns the result of Mario's encounter with a Goomba, given the 80% probability of winning and 20% of losing against a Goomba
bool Goomba::result(){
    return probability(m_probability); // Returns result of returned result
}
