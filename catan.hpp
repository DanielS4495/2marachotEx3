#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>

// #include "board.hpp"
// #include "tile.hpp"
// #include "piece.hpp"
namespace ariel {
    class Player;
    class Piece;
    class Tile;
    class Board;
}
namespace ariel
{
    class Catan
    {
    private:
        std::vector<Player> players;
        std::shared_ptr<Board> board;
        Player *currentPlayer;
        int currentPlayerIndex;
        bool ifBuild;
        std::vector<std::shared_ptr<Tile>> tiles;
        std::vector<std::shared_ptr<Piece>> settlements;
        std::vector<std::shared_ptr<Piece>> roads;
        
        void setIfBuild();
        
        Catan(const std::vector<Player> &players);
        // void initializeBoard();

    public:
        static Catan &getInstance(const std::vector<Player> &players);
        Player *getCurrentPlayer();
        void chooseStartingPlayer();
        void getBoard();
        void start();
        void playTurn();
        void nextPlayer();
        bool checkVictory();
        bool checkBuild(); //check if the player build something so he cant trade 
        void printWinner();
        void rollDice(); //do i need this? player has it
        
        // Other member functions
    };

}