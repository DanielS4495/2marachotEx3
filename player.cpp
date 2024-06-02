#include "player.hpp"
namespace ariel
{
    void Player::reduceVictoryPoints(int num)
    {
        *this->victoryPoints-=num;
    }

    Player::Player(const std::string &name, const int age)
    {
        *this->name = name;
        *this->age = age;
        *this->countMostConnectRoads = 0;
        *this->knight = 0;
        *this->victoryPoints = 0;
        *this->roadCard = false;
        *this->knightCard = false;
    }
    std::string Player::getName() const
    {
        return *this->name;
    }
    int Player::getAge() const
    {
        return *this->age;
    }
    int Player::getVictoryPoints() const
    {
        return *this->victoryPoints;
    }
    void ariel::Player::addVictoryPoints()
    {
        *this->victoryPoints++;
    }
    void Player::addResource(const std::string &getResource) // how does it know what type its a string not type resource
    { 
        // resources[getResource->getType()]++;
    }
    void Player::removeResource(const std::string &removeResource)
    {
        // resources[removeResource->getType()]--;
    }
    void Player::addDevelopment(const std::string &getDevelopment)
    {
        
    }
    // when i use road or knight i need to sent to catan so it will check with all the player who has the most
    void Player::useDevelopment(const std::string &removeDevelopment)
    {
    }
    // when i use road i need to sent to catan so it will check with all the player who has the most
    void Player::pieceBuild(const std::string &getPiece, const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    {
    }

    void Player::rollDice()
    {
    }
    void Player::endTurn()
    {
    }
    // first need to check if they have this resource
    void Player::trade(Player &other, const std::string &giveResource, const std::string &getResource, int giveAmount, int getAmount)
    {
    }
    void Player::buyDevelopmentCard()
    {
    }
    int Player::getNumberOfSettlement() const
    {
        return 0;
    }
    int Player::getNumberOfCity() const
    {
        return 0;
    }
    int Player::getNumberOfRoads() const
    {
        return 0;
    }
    void Player::setKnightCard(bool b)
    {
        *this->knightCard=b;
    }
    void Player::setRoadCard(bool b)
    {
        *this->roadCard=b;
        if(b){
            *this->addVictoryPoints();
            *this->addVictoryPoints();
        }
        else{
            *this->reduceVictoryPoints(2);
        }
    }
    void Player::printPoints() const
    {
        cout << "Player: " << *this->getName << "has " << *this->getVictoryPoints << endl;
    }
}