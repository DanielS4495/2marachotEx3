#include "catan.hpp"
namespace ariel
{
    Catan::Catan() {}

    void Catan::initializeBoard()
    {
        // Initialize the tiles and other board elements
    }
    static Catan &getInstance(const std::vector<Player> &players)
    {
        static Catan instance;
        instance.players = players;
        instance.currentPlayerIndex = 0;
        instance.chooseStartingPlayer();
        instance.initializeBoard();
        return instance;
    }
    Player *getCurrentPlayer()
    {
        return currentPlayer;
    }
    void Catan::start()
    {
        // Game starting logic
    }

    void Catan::playTurn()
    {
        // Player *currentPlayer = getCurrentPlayer();
        std::cout << currentPlayer->getName() << "'s turn." << std::endl;

        int rollResult = Dice::roll();
        std::cout << "Rolled: " << rollResult << std::endl;

        // Distribute resources based on the roll result
        // Implement trading and building logic

        // Move to the next player
        // turnIndex = (turnIndex + 1) % players.size(); //do i need this?
        nextPlayer();
    }

    void Catan::nextPlayer()
    {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        currentPlayer = &players[currentPlayerIndex];
    }

    bool Catan::checkVictory()
    {
        return currentPlayer->getVictoryPoints() >= 10;
    }

    void Catan::chooseStartingPlayer()
    { // the oldest player is starting
        int maxage = 0;
        for (const auto &player : players)
        {
            if (maxage < player.getage())
                maxage = player.getage();
        }
        for (const auto &player : players)
        {
            if (maxage == player.getage())
            {
                std::cout << "Starting player is " << player->getName() << std::endl;
                *this->currentPlayer == player;
                return;
            }
        }
    }

    void Catan::printWinner()
    { // need to free all the space from everything
        for (const auto &player : players)
        {
            if (player.getVictoryPoints() >= 10)
            {
                std::cout << player.getName() << " wins the game!" << std::endl;
                return;
            }
        }
        std::cout << "None of the players reached 10 points yet." << std::endl;
    }

    void Catan::rollDice()
    {
        // Logic to roll the dice and distribute resources
        int diceRoll = rand() % 6 + 1 + rand() % 6 + 1; // Simulate rolling two six-sided dice
        std::cout << "Dice roll: " << diceRoll << std::endl;
        // Distribute resources based on the dice roll
    }
}