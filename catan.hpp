#pragma

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "player.hpp"
#include "tile.hpp"
#include "settlement.hpp"
#include "road.hpp"
#include "development_card_factory.hpp"
namespace ariel
{
    class Catan
    {
    private:
        std::vector<Player> players;
        Player *currentPlayer;
        int currentPlayerIndex;
        std::vector<std::shared_ptr<Tile>> tiles;
        std::vector<std::shared_ptr<Settlement>> settlements;
        std::vector<std::shared_ptr<Road>> roads;

        Catan();
        void initializeBoard();

    public:
        static Catan &getInstance(const std::vector<Player> &players)
        {
            static Catan instance;
            instance.players = players;
            instance.currentPlayerIndex = 0;
            instance.currentPlayer = &instance.players[0];
            instance.initializeBoard();
            return instance;
        }

        Player *getCurrentPlayer()
        {
            return currentPlayer;
        }

        void start();
        void playTurn();
        void nextPlayer();
        bool checkVictory();
        void chooseStartingPlayer();
        void printWinner();
        void rollDice();
        // Other member functions
    };

}