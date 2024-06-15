#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include "card.hpp"
#include "resource.hpp"
// #include "piece.hpp"
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
        // std::shared_ptr<Board> board;
        string name;
        int age;
        int victoryPoints;
        int knight;
        int countMostConnectRoads = 0;
        bool knightCard;
        bool roadCard;
        bool hisTurn = false;
        bool hasBuildThisTurn = false;
        int countNumOfTurn = 0; // count the number of turn so we will know for the two first round
        // Board& board = *boardPtr; // Dereference the shared pointer
        int countCity = 0;
        int countSettlements = 0;
        int countRoads = 0;
        // std::unordered_map<std::shared_ptr<Resource>, int> resources;
        // std::map<std::shared_ptr<Resource>, int> resources;
        // std::unordered_map<Resource *, int> resources;
        std::unordered_map<ResourceType, int> resources;
        std::unordered_map<CardType, int> development;
        void reduceVictoryPoints(int num);
        void addDevelopment(const string &getDevelopment);
        // void addRoad();

    public:
        Player(const string &name, const int age);
        ~Player() = default;
        // void setBoard(const std::shared_ptr<Board> &board);
        string getName() const;
        int getAge() const;

        int getVictoryPoints() const;
        void addVictoryPoints();

        void addResource(int count, const std::string &getResource);
        void removeResource(int count, const string &removeResource); // maybe need to be private
        int getResourceCount(const std::string &getResource) const;
        int countResources();

        void useDevelopment(const string &removeDevelopment);
        int getDevelopmentCardCount(const string &getDevelopment) const;
        void buyDevelopmentCard();
        bool hasDevelopment() const;

        void placeSettelemnt(const vector<string> &places, const vector<int> &placesNum, Board &board);
        void placeCity(const vector<string> &places, const vector<int> &placesNum, Board &board);
        void placeRoad(const vector<string> &places, const vector<int> &placesNum, Board &board);
        int getNumberOfSettlement() const;
        int getNumberOfCity() const;
        int getNumberOfRoads() const;

        int getSettlementLimit() const;
        int getCityLimit() const;
        int getRoadsLimit() const;

        void rollDice(Board &board);
        void endTurn();
        void startTurn();
        void hasBuild(bool b);
        bool getHasBuild() const;

        void trade(Player &other, const string &giveResource, const string &getResource, int giveAmount, int getAmount);

        void setKnightCard(bool b); // to add do true else false
        bool getKnightCard();       // if he has knight card
        void setRoadCard(bool b);   // to add do true else false
        bool getRoadCard();         // if he has road card

        void printPoints() const;
        void printStatsOfPlayer() const; // print resource and dev own by player
        bool operator==(const Player &p) const;
    };
}