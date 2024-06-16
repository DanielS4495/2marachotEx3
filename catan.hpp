//danielsamson10@gmail.com
#pragma once
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include "player.hpp"
#include "board.hpp"
#include "tile.hpp"
#include "card.hpp" // go to player for card dev and come here and do the card here
using namespace std;
namespace ariel
{
    class Catan
    {
    private:
        std::vector<Player *> players;
        std::shared_ptr<Board> board;
        Player *currentPlayer;
        size_t currentPlayerIndex;
        bool ifBuild = false;
        bool ifstart = false; // if the game started then its true
        std::vector<std::shared_ptr<Tile>> tiles;
        void setIfBuild(bool status);
        void chooseStartingPlayer();
        bool buildFromUser(string WhatBuild); // take places and numbers from user and build with them
        // if player got 7 in dice we need to check all the player cards
        // to see if all got less then 7 card if not reduce the amount of the card
        void gotSevenInDice();
        void UseDevelopmentOfCurrentPlayer(const string &useDevelopment); // play card player

    public:
        Catan(const std::vector<Player *> &players);
        Catan(const Catan &) = delete;
        void operator=(const Catan &) = delete;
        static Catan &getInstance(const std::vector<Player *> &players);
        Board &getBoard();
        Player *getCurrentPlayer() const;
        void start();
        void playTurn();
        void nextPlayer();
        bool checkVictory();
        bool checkBuild(); // check if the player build something so he cant trade
        void printWinner();
        void giveResourceStart();
    };

}