//danielsamson10@gmail.com
#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <random>
#include "card.hpp"
#include "resource.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;
namespace ariel
{
    class Board;
    class Player
    {
    private:
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
        int countCity = 0;
        int countSettlements = 0;
        int countRoads = 0;
        std::unordered_map<ResourceType, int> resources;
        std::unordered_map<CardType, int> development;
        void reduceVictoryPoints(int num);
        void addDevelopment(const string &getDevelopment);
        bool isInputsValid(const vector<string> &places, const vector<int> &placesNum);

    public:
        Player(const string &name, const int age);
        ~Player() = default;
        string getName() const;
        int getAge() const;

        int getVictoryPoints() const;
        void addVictoryPoints();

        void addResource(int count, const std::string &getResource);
        void removeResource(int count, const string &removeResource); 
        int getResourceCount(const std::string &getResource) const;
        int countResources();

        void useDevelopment(const string &removeDevelopment); // need to change this so it will be done in the catan and here only reduce
        int getDevelopmentCardCount(const string &getDevelopment) const;
        void buyDevelopmentCard();
        bool hasDevelopment() const;
        void printDevelopment() const;//list of the development of the player

        bool placeSettelemnt(const vector<string> &places, const vector<int> &placesNum, Board &board);
        bool placeCity(const vector<string> &places, const vector<int> &placesNum, Board &board);
        bool placeRoad(const vector<string> &places, const vector<int> &placesNum, Board &board);
        int getNumberOfSettlement() const;
        int getNumberOfCity() const;
        int getNumberOfRoads() const;

        int getSettlementLimit() const;
        int getCityLimit() const;
        int getRoadsLimit() const;

        int rollDice(Board &board);
        void endTurn();
        void startTurn();
        void hasBuild(bool b);
        bool getHasBuild() const;

        void trade(Player &other, const string &giveResource, const string &getResource, int giveAmount, int getAmount);
        void tradeMonopoly(Player &other, const string &giveResource, const string &getResource, int giveAmount, int getAmount);

        void setKnightCard(bool b); // to add do true else false
        bool getKnightCard();       // if he has knight card
        void setRoadCard(bool b);   // to add do true else false
        bool getRoadCard();         // if he has road card

        void printPoints() const;
        void printStatsOfPlayer() const; // print resource and dev own by player
        bool operator==(const Player &p) const;
    };
}