#include "Boss.h"

// result Function: returns the result of Mario's encounter with a Boss, given the 50% probability of winning/losing against a Koopa Troopa
bool Boss::result(){
    return probability(m_probability); // Returns result of returned result
}
