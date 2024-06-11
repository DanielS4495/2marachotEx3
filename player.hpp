#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "card.hpp"
#include "resource.hpp"
#include "piece.hpp"
// #include "board.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;
namespace ariel
{
    class Board;
    class Player
    {
    private:
        Board *board;
        string name;
        int age;
        int victoryPoints;
        int knight;
        int countMostConnectRoads;
        bool knightCard;
        bool roadCard;
        // Board& board = *boardPtr; // Dereference the shared pointer
        std::vector<std::shared_ptr<Piece>> City;
        std::vector<std::shared_ptr<Piece>> settlements;
        std::vector<std::shared_ptr<Piece>> roads;
        std::unordered_map<std::shared_ptr<Resource>, int> resources;
        std::unordered_map<std::shared_ptr<Card>, int> development;
        void reduceVictoryPoints(int num);

    public:
            Player(const string &name, const int age);
            string getName() const;
            int getAge() const;

            int getVictoryPoints() const;
            void addVictoryPoints();

            void addResource(std::shared_ptr<Resource> resource);
            void removeResource(const string &removeResource); // maybe need to be private
            int getResourceCount(const std::string &getResource) const;

            void addDevelopment(const string &getDevelopment);
            void useDevelopment(const string &removeDevelopment);
            int getDevelopmentCardCount(const string &getDevelopment) const;
            void buyDevelopmentCard();

            void placeSettelemnt(const vector<string> &places, const vector<int> &placesNum);
            void placeCity(const vector<string> &places, const vector<int> &placesNum);
            void placeRoad(const vector<string> &places, const vector<int> &placesNum);
            int getNumberOfSettlement() const;
            int getNumberOfCity() const;
            int getNumberOfRoads() const;

            int getSettlementLimit() const;
            int getCityLimit() const;
            int getRoadsLimit() const;

            void rollDice();
            void endTurn();

            void trade(Player &other, const string &giveResource, const string &getResource, int giveAmount, int getAmount);

            void setKnightCard(bool b); // to add do true else false
            bool getKnightCard();       // if he has knight card
            void setRoadCard(bool b);   // to add do true else false
            bool getRoadCard();         // if he has road card

            void printPoints() const;
            bool operator==(const Player &p) const;
    };
}