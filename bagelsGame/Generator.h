#pragma once

#include<iostream>
#include<string>
#include <random>
#include<vector>

class Generator
{
public:
    std::string generateNumber();
    void generateHints(std::string& userGuess, std::string& answer);
};

