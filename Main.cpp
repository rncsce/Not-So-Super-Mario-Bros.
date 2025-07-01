#include "World.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv){

    // Testing File Processing Class

    // FileProcessor processor;
    // processor.processFile("CommandLines.txt");
    // cout << processor.getFileData(0) << endl;
    // cout << processor.getFileData(1) << endl;
    // cout << processor.getFileData(2) << endl;
    // cout << processor.getFileData(3) << endl;
    // cout << processor.getFileData(4) << endl;
    // cout << processor.getFileData(5) << endl;
    // cout << processor.getFileData(6) << endl;
    // cout << processor.getFileData(7) << endl;

    // Testing Logger Class

    // Logger logger("HelloWorld.txt");
    // logger.logMessage("Hello World!\n");
    // logger.logMessage("\n");
    // logger.logMessage("\n");
    // logger.logMessage(":D");

    // Testing Mario Class

    // Mario mario;
    // cout << "Mario has:  " << mario.getLives() << " lives." << endl;
    // mario.setLives(7);
    // cout << "Mario has:  " << mario.getLives() << " lives." << endl;
    // mario.addLife();
    // cout << "Mario picked up an extra life.!" << endl;
    // cout << "Lives: " << mario.getLives() << " lives." << endl;
    // mario.removeLife();
    // cout << "Mario lost a life." << endl;
    // cout << "Lives:  " << mario.getLives() << " lives." << endl;
    // mario.setCoins(20);
    // cout << "Mario has: " << mario.getCoins() << " coins." << endl;
    // // Extra Life Check Function
    // mario.extraLifeCheck();
    // cout << "Mario has: " << mario.getCoins() << " coins." << endl;
    // cout << "Lives:  " << mario.getLives() << " lives." << endl;
    // mario.addCoin();
    // cout << "Mario picked up a coin!" << endl;
    // cout << "Mario has: " << mario.getCoins() << " coins." << endl;
    // mario.removeCoins(1);
    // cout << "Mario used a coin." << endl;
    // cout << "Mario has: " << mario.getCoins() << " coins." << endl;

    // Testing Enemy Classes
    // Testing Goomba Class

    // Goomba goomba;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;
    // cout << goomba.result() << endl;

    // Testing Koopa Troopa Class

    // KoopaTroopa koopaTroopa;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;
    // cout << koopaTroopa.result() << endl;

    // Testing Boss Class

    // Boss boss;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;
    // cout << boss.result() << endl;

    // Testing Game Class
    // World world("CommandLines.txt", "GameLog.txt");
    string sourceFile;
    string outputFile;
    sourceFile = argv[1];
    outputFile = argv[2];
    // cout << "Enter source file: " << endl;
    // getline (cin, sourceFile);
    World world(sourceFile, outputFile);
    world.play();

    return 0;
}
