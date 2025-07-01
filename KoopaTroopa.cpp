#include "KoopaTroopa.h"
// result Function: returns the result of Mario's encounter with a Koopa Troopa, given the 65% probability of winning and 35% of losing against a Koopa Troopa
bool KoopaTroopa::result(){
    return probability(m_probability); // Returns result of returned result
}
