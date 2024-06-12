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
    void Player::addResource(int count, const std::string &getResource)
    {
        ResourceType resourceType = getResourceTypeFromString(getResource);
        std::shared_ptr<Resource> res = createResource(resourceType);
        if (count > 0)
            resources[res] += count;
    }
    void Player::removeResource(int count, const std::string &removeResource)
    {
        ResourceType resourceType = getResourceTypeFromString(removeResource);
        std::shared_ptr<Resource> res = createResource(resourceType);
        if (resources[res] >= count)
            resources[res] -= count;
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
    int Player::countResources() // for dice=7 need to remove if you have moreN then 7 resources
    {
        // string listres = {"wood", "ss"};
        int count = 0;
        // for (int i; i < resources.size(); i++)
        // {
        //     string getResource = listres[i];
        //     // ResourceType resourceType = getResourceTypeFromString(getResource);
        //     // std::shared_ptr<Resource> res = createResource(resourceType);
        //     // resources[res]
        //     count += getResourceCount(listres[i]);
        // }
        return count;
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
            if (removeDevelopment == "knight")
            {
                this->knight++;
                // if()//sent to catan to check if this player deserve cardknight
                this->setKnightCard(true);
            }
            if (removeDevelopment == "Road Builder")
                this->countRoads++;
            //  card->play(this);
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
        if (this->hisTurn)
        {
            int dice = rand() % 12 + 1;
            int robber = 0;
            while (robber == 0 && dice == 7)
            {
                try
                {
                    cout << "enter number betwween 1 to 19 to put in the tile that the robber will be there:" << endl;
                    cin >> robber;
                    if (robber > 20 && robber < 1)
                        throw std::invalid_argument("Not Between 1 to 19 try again");
                }
                catch (const std::exception &e)
                {
                    robber = 0;
                    cout << e.what() << endl;
                }
            }
            board->giveResourceByDice(dice, robber);
        }
    }
    void Player::endTurn()
    {

        this->hisTurn = false;
    }
    void Player::startTurn()
    {
        this->countNumOfTurn++;
        this->hisTurn = true;
        hasBuild(false);
    }
    void Player::hasBuild(bool b)
    {
        this->hasBuildThisTurn = b;
    }
    bool Player::getHasBuild() const
    {
        return this->hasBuildThisTurn;
    }
    // first need to check if they have this resource
    void Player::trade(Player &other, const std::string &giveResource, const std::string &getResource, int giveAmount, int getAmount)
    {
        if (getHasBuild())
        {
            if (giveAmount > 0 && getAmount > 0)
                if (this->getResourceCount(giveResource) > giveAmount && other.getResourceCount(getResource) > getAmount)
                    this->removeResource(giveAmount, giveResource);
            this->addResource(getAmount, getResource);
            other.removeResource(getAmount, getResource);
        }
    }
    void Player::buyDevelopmentCard()
    {
        try
        {
            if (this->hisTurn)
                if (getResourceCount("SHEEP") > 0 && getResourceCount("WHEAT") > 0 && getResourceCount("IRON") > 0)
                {
                    removeResource(1, "SHEEP");
                    removeResource(1, "WHEAT");
                    removeResource(1, "IRON");
                    int random = rand() % 5 + 1;
                    CardType c = CardType(random);
                    std::shared_ptr<Card> card = createCard(c);
                    development[card]++;
                }
                else
                    throw std::invalid_argument("Invalid dont have enough resource type");
            else
                throw std::invalid_argument("Not the player turn");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
    }
    void Player::placeSettelemnt(const std::vector<std::string> &places, const std::vector<int> &placesNum)
    { // check if there are enough resource to build
        try
        {
            if (this->hisTurn)
            {
                if (this->countNumOfTurn < 2)
                {
                    if (getResourceCount("WOOD") > 0 && getResourceCount("SHEEP") > 0 && getResourceCount("WHEAT") > 0 && getResourceCount("BRICK") > 0 && getNumberOfSettlement() < getSettlementLimit())
                    {
                        vector<Tile *> t = board->findTiles(places, placesNum);
                        int node = board->findNode(t);
                        if (node == -1)
                            throw std::invalid_argument("Invalid node, cant find the other node to connect to");
                        bool canPlace = board->placeSettlement(node, *this);
                        if (canPlace && this->countSettlements < getSettlementLimit())
                        {
                            removeResource(1, "WOOD");
                            removeResource(1, "SHEEP");
                            removeResource(1, "WHEAT");
                            removeResource(1, "BRICK");
                            this->countSettlements++;
                        }
                        else
                            throw std::invalid_argument("Invalid cant place settlement or got to the limit");
                    }
                    else
                        throw std::invalid_argument("Invalid dont have enough resource type or dont have enough settelemnt to build");
                }
                else
                {
                    vector<Tile *> t = board->findTiles(places, placesNum);
                    int node = board->findNode(t);
                    if (node == -1)
                        throw std::invalid_argument("Invalid node, cant find the node to connect to");
                    bool canPlace = board->placeSettlement(node, *this);
                    if (!canPlace)
                        throw std::invalid_argument("Invalid cant place settlement");
                }
            }
            else
                throw std::invalid_argument("Not the player turn");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
        if (countResources() < 1)
            endTurn();
    }
    void Player::placeCity(const std::vector<std::string> &places, const std::vector<int> &placesNum)
    {
        try
        {
            if (this->hisTurn)
                if (getResourceCount("IRON") > 3 && getResourceCount("WHEAT") > 2 && getNumberOfCity() < getCityLimit())
                {
                    vector<Tile *> t = board->findTiles(places, placesNum);
                    int node = board->findNode(t);
                    if (node == -1)
                        throw std::invalid_argument("Invalid node, cant find the other node to connect to");
                    bool canPlace = board->placeCity(node, *this);
                    if (canPlace && this->countCity < getCityLimit())
                    {
                        removeResource(2, "WHEAT");
                        removeResource(3, "IRON");
                        this->countCity++;
                    }
                    else
                        throw std::invalid_argument("Invalid cant place city or got to the limit");
                }
                else
                    throw std::invalid_argument("Invalid dont have enough resource type or dont have enough city to build");
            else
                throw std::invalid_argument("Not the player turn");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
        if (countResources() < 1)
            endTurn();
    }
    void Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum)
    {
        try
        {
            if (this->hisTurn)
            {
                if (this->countNumOfTurn < 2)
                {
                    if (getResourceCount("WOOD") > 0 && getResourceCount("BRICK") > 0 && getNumberOfRoads() < getRoadsLimit())
                    {
                        vector<Tile *> t = board->findTiles(places, placesNum);
                        int node = board->findNode(t);
                        if (node == -1)
                            throw std::invalid_argument("Invalid node, cant find the node to connect to");
                        int otherNode = board->findOtherNodeOfRoad(node, *this);
                        if (otherNode == -1)
                            throw std::invalid_argument("Invalid node, cant find the other node to connect to");
                        bool canPlace = board->placeRoad(node, otherNode, *this);
                        if (canPlace && this->countRoads < getRoadsLimit())
                        {
                            removeResource(1, "WOOD");
                            removeResource(1, "BRICK");
                            this->countRoads++;
                        }
                        else
                            throw std::invalid_argument("Invalid cant place road or got to the limit");
                    }
                    else
                        throw std::invalid_argument("Invalid dont have enough resource type or dont have enough roads to build");
                }
                else
                {
                    vector<Tile *> t = board->findTiles(places, placesNum);
                    int node = board->findNode(t);
                    if (node == -1)
                        throw std::invalid_argument("Invalid node, cant find the node to connect to");
                    int otherNode = board->findOtherNodeOfRoad(node, *this);
                    if (otherNode == -1)
                        throw std::invalid_argument("Invalid node, cant find the other node to connect to");
                    bool canPlace = board->placeRoad(node, otherNode, *this);
                    if (!canPlace)
                        throw std::invalid_argument("Invalid cant place settlement");
                }
            }
            else
                throw std::invalid_argument("Not the player turn");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
        if (countResources() < 1)
            endTurn();
    }
    int Player::getNumberOfSettlement() const
    {
        return this->countSettlements;
    }
    int Player::getNumberOfCity() const
    {
        return this->countCity;
    }
    int Player::getNumberOfRoads() const
    {
        return this->countRoads;
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
        cout << "Player: " << this->getName() << " has " << this->getVictoryPoints() << endl;
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