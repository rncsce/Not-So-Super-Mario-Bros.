#include "Enemy.h"
#include <random>
using namespace std;
// proability Function: returns true or false for a given percentage (Mario's probability of winning/losing)
bool Enemy::probability(double probability){ // Takes in a probability (double) as a parameter
    random_device rd; // Random number source
    mt19937 gen(rd()); // Random number generator, random device as seed
    uniform_real_distribution<double> distr(0.0, 1.0); // Uniform distribution between 0.0 and 1.0
    double randNum = distr(gen); // Generates random double between 0.0 and 1.0
    if (randNum < probability){ // If the generated number is less than defined probability
        return true; // Return true 
    } else { // If the generated number if more than the defined probability
        return false; // Return false
    }
}
