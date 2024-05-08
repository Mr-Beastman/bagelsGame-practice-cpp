#include<iostream>
#include <iomanip>
#include <string>
#include <random>


using std::cout;
using std::cin;

std::string randomNumGen() {
    std::random_device randNum;
    std::uniform_int_distribution<int> dist(100, 999);
    int randomNumber = dist(randNum);
    return std::to_string(randomNumber);
}

void generateHints(std::string userGuess, std::string randomNum) {
    int clueCount=0;

    for (int i = 0; i < 3; i++) {
        //Loop through checking if number and placment match. 
        if (userGuess[i] == randomNum[i]) {
            cout << "Pico ";
            clueCount++;
        }
        else {
            //Loop through to checking if number from guess appears in sequence at all.
            for (int j = 0; j < 3; j++) {
                if (userGuess[i] == randomNum[j]) {
                    cout << "Fermi ";
                    clueCount++;
                }
            }
        }
    }

    //Quick check if any clues were provided and supplies final clue if needed.
    if (clueCount == 0) {
        cout << "Bagels";
    }
}

bool replayGame() {
    char response;

    cout << "\n\nWould you like to play again y/n? : ";
    cin >> response;

    if (response == 'y') {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    //Declare variables
    std::string userGuess, randomNum;
    bool replay;
    
    //Game info Display
    cout << "Bagels, a deductive logic game.\n";
    cout << "\nI am thinking of a 3 digit number. Try to guess what it is.\n";
    cout << "Here are some clues:\n";

    cout << std::left << std::setw(20) << "When I say:" << std::left << "That means:\n";
    cout << std::left << std::setw(20) << "Pico" << std::left << "One digit is in the wrong position\n";
    cout << std::left << std::setw(20) << "Fermi" << std::left << "One digit is in the correct position\n";
    cout << std::left << std::setw(20) << "Bagels" << std::left << "No digit is correct\n";

    do {
        //Setting Random Number via function
        randomNum = randomNumGen();

        cout << "\nI have thought of a number.\n";
        cout << "You have 10 guesses to get it\n";
        cout << randomNum<<"\n";

        for (int guessCount = 1; guessCount <= 10; guessCount++) {

            cout << "Guess #" << guessCount << "\n";
            cin >> userGuess;

            if (userGuess == randomNum) {
                cout << "You win!";
                break;
            }
            else {
                generateHints(userGuess, randomNum);
            }

            cout << "\n";
        }

        replay = replayGame();

    } while (replay == 1);
    
    cout << "\n";
    return 0;
}