#include "Generator.h"

//generate radondom 3 digit number
//returns: string containing 3 digits. string format used in checking.
std::string Generator::generateNumber()
{
    std::random_device randNum;
    std::uniform_int_distribution<int> dist(100, 999);
    int randomNumber = dist(randNum);
    return std::to_string(randomNumber);
}

//generate hints for user based off inputs.
//parameters: users current guess and rounds answer as strings
void Generator::generateHints(std::string& userGuess, std::string& answer){
    
    std::vector<std::string> hints;
    bool match[3] = { false,false,false };

    std::cout << answer;

    for (int i = 0; i < 3; i++) {
        if (userGuess[i] == answer[i]) {
            hints.push_back("Pico");
            match[i] = true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (userGuess[i] != answer[i]) {
            for (int j = 0; j < 3; j++) {
                if (!match[j] && userGuess[i] == answer[j]) {
                    hints.push_back("Fermi");
                    match[j] = true;
                    break;
                }
            }
        }
    }

    if (hints.empty()) {
        std::cout<<"\nBagels\n";
    }
    else {
        for (auto& hint : hints) {
            std::cout << hint << " ";
        }
    }
}


