#pragma once

#include<iostream>
#include <iomanip>
#include <string>

class Game{
private:
    bool initReplayGame;

    void displayTitle();
    void playRound();
    void replayGame();
    
public:
    Game();
    ~Game();

    void runGame();
};

