#include "player.hpp"
#include "board.hpp"
// #include "catan.hpp"
using namespace std;
namespace ariel
{
    void Player::reduceVictoryPoints(int num)
    {
        this->victoryPoints -= num;
    }

    Player::Player(const std::string &name, const int age)
    {
        this->name = name;
        this->age = age;
        this->countMostConnectRoads = 0;
        this->knight = 0;
        this->victoryPoints = 0;
        this->roadCard = false;
        this->knightCard = false;

        // for (const auto &pair : stringToResource)
        // {
        //     this->resources[pair.second] = 0;
        // }
        // for (const auto &pair : Card::stringToDevelopment)
        // {
        //     this->development[pair.second] = 0;
        // }
    }
    std::string Player::getName() const
    {
        return this->name;
    }
    int Player::getAge() const
    {
        return this->age;
    }
    int Player::getVictoryPoints() const
    {
        return this->victoryPoints;
    }
    void Player::addVictoryPoints()
    {
        this->victoryPoints++;
    }
    void Player::addResource(int count,std::shared_ptr<Resource> resource) // how does it know what type its a string not type resource
    {
        // ResourceType resourceType = getResourceTypeFromString(getResource);
        // std::shared_ptr<Resource> res = createResource(resourceType);
        if(count>0)
        resources[resource]+=count;
    }
    void Player::removeResource(const std::string &removeResource)
    {
        ResourceType resourceType = getResourceTypeFromString(removeResource);
        std::shared_ptr<Resource> res = createResource(resourceType);
        if (resources[res] > 0)
            resources[res]--;
        else
            throw std::invalid_argument("Invalid dont have enough resource type");
    }
    int Player::getResourceCount(const std::string &getResource) const
    {
        ResourceType resourceType = getResourceTypeFromString(getResource);
        std::shared_ptr<Resource> res = createResource(resourceType);
        auto it = resources.find(res);
        if (it != resources.end())
        {
            return it->second;
        }
        else
        {
            return 0;
        }
    }
    void Player::addDevelopment(const std::string &getDevelopment)
    {
        CardType developmentType = getCardTypeFromString(getDevelopment);
        std::shared_ptr<Card> card = createCard(developmentType);
        development[card]++;
    }

    // when i use road or knight i need to sent to catan so it will check with all the player who has the most
    // when i use knight go to catan and check who has the most knight so he will get the card instead another player
    void Player::useDevelopment(const std::string &removeDevelopment)
    {
        CardType developmentType = getCardTypeFromString(removeDevelopment);
        std::shared_ptr<Card> card = createCard(developmentType);
        if (development[card] > 0)
            development[card]--;
        else
            throw std::invalid_argument("Invalid dont have enough resource type");
        try
        {
            // std::shared_ptr<Card> card = createCard(developmentType);
            // card->play(player);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    int Player::getDevelopmentCardCount(const string &getDevelopment) const
    {
        CardType developmentType = getCardTypeFromString(getDevelopment);
        std::shared_ptr<Card> card = createCard(developmentType);
        auto it = development.find(card);
        if (it != development.end())
        {
            return it->second;
        }
        else
        {
            return 0;
        }
    }
    // when i use road i need to sent to catan so it will check with all the player who has the most
    // void Player::pieceBuild(const std::string &getPiece, const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    // { // need to do while so i can try to put city in someplace and get true or false if false try someplace else or if there is no place at all to put
    //   // need func to do that
    // }

    void Player::rollDice()
    {
    }
    void Player::endTurn() // need to change buck the ifbuild so it wont affect his next play
    // also need to check if it is his turn to play
    {
    }
    // first need to check if they have this resource
    void Player::trade(Player &other, const std::string &giveResource, const std::string &getResource, int giveAmount, int getAmount)
    {
    }
    void Player::buyDevelopmentCard()
    {
    }
    void Player::placeSettelemnt(const std::vector<std::string> &places, const std::vector<int> &placesNum)
    { // check if there are enough resource to build
        try
        {
            if (getResourceCount("WOOD") > 0 && getResourceCount("SHEEP") > 0 && getResourceCount("WHEAT") > 0 && getResourceCount("ORE") > 0 && getNumberOfSettlement() < 5)
            // board.placeSettlement(places, placesNum);
            {
                removeResource("WOOD");
                removeResource("SHEEP");
                removeResource("WHEAT");
                removeResource("ORE");
            }
            else
                throw std::invalid_argument("Invalid dont have enough resource type or dont have enough settelemnt to build");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
    }
    void Player::placeCity(const std::vector<std::string> &places, const std::vector<int> &placesNum)
    {
        try
        {
            if (getResourceCount("BRICK") > 3 && getResourceCount("WHEAT") > 2 && getNumberOfCity() < 4)
            // board.placeSettlement(places, placesNum);
            {
                removeResource("WHEAT");
                removeResource("WHEAT");
                removeResource("BRICK");
                removeResource("BRICK");
                removeResource("BRICK");
            }
            else
                throw std::invalid_argument("Invalid dont have enough resource type or dont have enough city to build");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
    }
    void Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum)
    {
        try
        {
            if (getResourceCount("WOOD") > 0 && getResourceCount("ORE") > 0 && getNumberOfRoads() < 15)
            // board.placeroad(placesNum[0],placesNum[1],this);
            {
                removeResource("WOOD");
                removeResource("ORE");
            }
            else
                throw std::invalid_argument("Invalid dont have enough resource type or dont have enough roads to build");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
    }
    int Player::getNumberOfSettlement() const
    {
        return settlements.size();
    }
    int Player::getNumberOfCity() const
    {
        return City.size();
    }
    int Player::getNumberOfRoads() const
    {
        return roads.size();
    }
    int Player::getSettlementLimit() const
    {
        return 5;
    }
    int Player::getCityLimit() const
    {
        return 4;
    }
    int Player::getRoadsLimit() const
    {
        return 15;
    }
    void Player::setKnightCard(bool b)
    {
        this->knightCard = b;
        if (b)
        {
            this->addVictoryPoints();
            this->addVictoryPoints();
        }
        else
        {
            this->reduceVictoryPoints(2);
        }
    }
    bool Player::getKnightCard()
    {
        return this->knightCard;
    }
    void Player::setRoadCard(bool b)
    {
        this->roadCard = b;
        if (b)
        {
            this->addVictoryPoints();
            this->addVictoryPoints();
        }
        else
        {
            this->reduceVictoryPoints(2);
        }
    }
    bool Player::getRoadCard()
    {
        return this->roadCard;
    }
    void Player::printPoints() const
    {
        cout << "Player: " << this->getName() << "has " << this->getVictoryPoints() << endl;
    }
    bool Player::operator==(const Player &p) const
    {
        if (p.getName() != this->getName())
            return false;
        if (p.getAge() != this->getAge())
            return false;
        return true;
    }

}