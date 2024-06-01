#pragma

#include <string>
#include <vector>
#include "settlement.hpp"
#include "road.hpp"

class Board; // Forward declaration
namespace ariel{

class Player {
private:
    std::string name;
    int age;
    int victoryPoints;
    std::vector<std::shared_ptr<City>> City;
    std::vector<std::shared_ptr<Settlement>> settlements;
    std::vector<std::shared_ptr<Road>> roads;
    std::vector<std::shared_ptr<Resource>> resource;
    std::vector<std::shared_ptr<Development>> Development;
    void addvictorypoints();
    // Other player attributes like resources and development cards
    

public:
    Player(const std::string& name,const int age);
    std::string getName() const;
    int getAge() const;
    int getVictoryPoints() const;
    void addResource(const std::string& getResource);
    void removeResource(const std::string& removeResource); //maybe need to be private
    void addDevelopment(const std::string& getDevelopment);
    void useDevelopment(const std::string& removeDevelopment); 
    void pieceBuild(const std::string& getPiece);
    // void placeSettlement(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    // void placeRoad(const std::vector<std::string>& places, const std::vector<int>& placesNum, Board& board);
    void rollDice();
    void endTurn();
    void trade(Player& other, const std::string& giveResource, const std::string& getResource, int giveAmount, int getAmount);
    void buyDevelopmentCard();
    int getNumberOfSettlement() const;
    int getNumberOfCity() const;
    int getNumberOfRoads() const;
    void printPoints() const;

    
};
}

