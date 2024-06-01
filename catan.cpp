#include "catan.hpp"

Catan::Catan() {}

void Catan::initializeBoard() {
    // Initialize the tiles and other board elements
}

void Catan::start() {
    // Game starting logic
}

void Catan::playTurn() {
    // Play turn logic
    // Update current player
}

void Catan::nextPlayer() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    currentPlayer = &players[currentPlayerIndex];
}

bool Catan::checkVictory() {
    return currentPlayer->getVictoryPoints() >= 10;
}

void Catan::chooseStartingPlayer() {
    // Logic to choose the starting player
    std::cout << "Starting player is " << currentPlayer->getName() << std::endl;
}

void Catan::printWinner() {
    // Logic to print the winner
    for (const auto& player : players) {
        if (player.getVictoryPoints() >= 10) {
            std::cout << player.getName() << " wins the game!" << std::endl;
            return;
        }
    }
    std::cout << "None of the players reached 10 points yet." << std::endl;
}

void Catan::rollDice() {
    // Logic to roll the dice and distribute resources
    int diceRoll = rand() % 6 + 1 + rand() % 6 + 1; // Simulate rolling two six-sided dice
    std::cout << "Dice roll: " << diceRoll << std::endl;
    // Distribute resources based on the dice roll
}
