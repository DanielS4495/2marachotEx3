#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include "player.hpp"
#include "board.hpp"
#include "tile.hpp"
// #include "piece.hpp"
using namespace std;
namespace ariel
{
    class Catan
    {
    private:
        std::vector<Player *> players;
        // Board &board;
        std::shared_ptr<Board> board;
        Player *currentPlayer;
        size_t currentPlayerIndex;
        bool ifBuild;
        bool ifstart = false; // if the game started then its true
        std::vector<std::shared_ptr<Tile>> tiles;
        // std::vector<std::shared_ptr<Piece>> settlements;
        // std::vector<std::shared_ptr<Piece>> roads;
        // std::shared_ptr<Board> board;
        void setIfBuild(bool status);
        void chooseStartingPlayer();
        // Catan(const std::vector<Player> &players);
        // void initializeBoard();

    public:
        Catan(const std::vector<Player *> &players);
        Catan(const Catan &) = delete;
        void operator=(const Catan &) = delete;
        // ~Catan();
        // std::shared_ptr<Board> getBoard() const;
        static Catan &getInstance(const std::vector<Player *> &players);
        // std::shared_ptr<Board> getBoard();
        Player *getCurrentPlayer() const;
        void start();
        void playTurn();
        void nextPlayer();
        bool checkVictory();
        bool checkBuild(); // check if the player build something so he cant trade
        void printWinner();
        void giveResourceStart();
        // void finishTurn();
    };

}