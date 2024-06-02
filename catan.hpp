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
        void chooseStartingPlayer();

        Catan();
        void initializeBoard();

    public:
        static Catan &getInstance(const std::vector<Player> &players);
        Player *getCurrentPlayer();
        void start();
        void playTurn();
        void nextPlayer();
        bool checkVictory();
        
        void printWinner();
        void rollDice(); //do i need this? player has it
        
        // Other member functions
    };

}