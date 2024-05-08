#include<iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;

std::string generateHints(std::string userGuess, std::string randomNum) {

}

int main() {
    std::string userGuess, randomNum="123";
    int guessCount;
    bool winCond = 0;
    
    cout << "Bagels, a deductive logic game.\n";
    cout << "\nI am thinking of a 3 digit number. Try to guess what it is.\n";
    cout << "Here are some clues:\n";

    cout << std::left << std::setw(20) << "When I say:" << std::left << "That means:\n";
    cout << std::left << std::setw(20) << "Pico" << std::left << "One digit is in the wrong position\n";
    cout << std::left << std::setw(20) << "Fermi" << std::left << "One digit is in the correct position\n";
    cout << std::left << std::setw(20) << "Bagels" << std::left << "No digit is correct\n";

    cout << "\nI have thought of a number.\n";
    cout << "You have 10 guesses to get it\n";

    guessCount = 1;
    cin >> userGuess;
    
    if (userGuess == randomNum) {
        cout << "You win!";
    }
    else {
        generateHints(userGuess, randomNum);
    }

    return 0;
}