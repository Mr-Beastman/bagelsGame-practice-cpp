#include "Game.h"
#include "Generator.h"

//constructor
Game::Game() : initReplayGame{ true } {}

//deconstructor
Game::~Game(){}

//displays title/subheading/instructions of the game
void Game::displayTitle()
{
    std::cout << "******* Bagels *******\n";
    std::cout << "A deductive logic game\n";
    std::cout << "**********************\n";

    std::cout << "\nDuring this game I'll be thinking of a 3 digit number.\n";
    std::cout << "You will have 10 guesses to figure it out\n";
    std::cout << "To help you, I will being giving the following hints:\n";

    std::cout << std::left << std::setw(20) << "When I say:" << std::left << "That means:\n";
    std::cout << std::left << std::setw(20) << "Pico" << std::left << "One digit is in the wrong position\n";
    std::cout << std::left << std::setw(20) << "Fermi" << std::left << "One digit is in the correct position\n";
    std::cout << std::left << std::setw(20) << "Bagels" << std::left << "No digit is correct\n";

    std::cout << "\nFor example, if the secret number was 248 and your guess was 843, the clues could be 'Pico Fermi'.\n";
}

//game logic for playing a round of the game
void Game::playRound(){

    Generator genertors;

    std::string userGuess;
    std::string answer = genertors.generateNumber();

    std::cout << "\nAlrigt, I've come up with a number! What do you think it is?\n";

    for (int guesscount = 1; guesscount < 11; guesscount++) {
        std::cout << "\nGuess #" << guesscount << ": ";
        std::cin >> userGuess;

        if (userGuess == answer) {
            std::cout << "\nCongratulations! You Win!\n";
            std::cout << "The Answer was : " << answer<<'\n';
            break;
        }
        else if (guesscount == 10) {
            std::cout << "\nGuess limit exceded. Better luck next time!\n";
            std::cout << "The correct answer was " << answer << "\n";
        }
        else {
            genertors.generateHints(userGuess, answer);
        }
    }

}

//Offers users option to replay the game after a win/loss. Y replays loop and N allows program to exit.
void Game::replayGame()
{
    char userInput;

    do {
        std::cout << "\nWould you like to play again y/n? : ";
        std::cin >> userInput;

        if (std::tolower(userInput) != 'y' && std::tolower(userInput) != 'n') {
            std::cout << "\nInvalid selection, please try again.";
        }
    } while (std::tolower(userInput) != 'y' && std::tolower(userInput) != 'n');


    if (std::tolower(userInput) == 'n') {
        initReplayGame = false;
    }
}


//public mehtod to run the game as intended
void Game::runGame(){

    displayTitle();

    while (initReplayGame) {
        playRound();
        replayGame();
    }

    std::cout<<"\nThank you for Playing!\n";
}
