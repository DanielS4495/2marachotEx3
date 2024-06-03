#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "card.hpp"
#include "resource.hpp"
#include "board.hpp"
#include <stdexcept>
#include <iostream>

namespace ariel
{
    class Piece;
    class Board;
    class Card;
}

// Forward declaration
namespace ariel
{

    class Player
    {
    private:
        std::string name;
        int age;
        int victoryPoints;
        int knight;
        int countMostConnectRoads;
        bool knightCard;
        bool roadCard;
        std::shared_ptr<Board> boardPtr = Board::getInstance();
        Board& board = *boardPtr; // Dereference the shared pointer
        std::vector<std::shared_ptr<Piece>> City;
        std::vector<std::shared_ptr<Piece>> settlements;
        std::vector<std::shared_ptr<Piece>> roads;
        std::unordered_map<std::shared_ptr<Resource>, int> resources;
        std::unordered_map<std::shared_ptr<Card>, int> development;
        void reduceVictoryPoints(int num);

    public:
        Player(const std::string &name, const int age);
        std::string getName() const;
        int getAge() const;

        int getVictoryPoints() const;
        void addVictoryPoints();

        void addResource(const std::string &getResource);
        void removeResource(const std::string &removeResource); // maybe need to be private
        int getResourceCount(ResourceType resourceType) const;

        void addDevelopment(const std::string &getDevelopment);
        void useDevelopment(const std::string &removeDevelopment);
        int getDevelopmentCardCount(CardType type) const;
        void buyDevelopmentCard();
        // void pieceBuild(const std::string &getPiece, const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
        void placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum);
        void placeCity(const std::vector<std::string> &places, const std::vector<int> &placesNum);
        void placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum);
        int getNumberOfSettlement() const;
        int getNumberOfCity() const;
        int getNumberOfRoads() const;

        void rollDice();
        void endTurn();

        void trade(Player &other, const std::string &giveResource, const std::string &getResource, int giveAmount, int getAmount);

        void setKnightCard(bool b); // to add do true else false
        bool getKnightCard();       // if he has knight card
        void setRoadCard(bool b);   // to add do true else false
        bool getRoadCard();         // if he has road card

        void printPoints() const;
    };
}
