// danielsamson10@gmail.com
#include "player.hpp"
#include "board.hpp"
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
        if (count > 0)
            resources[resourceType] += count;
    }
    void Player::removeResource(int count, const std::string &removeResource)
    {
        ResourceType resourceType = getResourceTypeFromString(removeResource);
        if (resources[resourceType] >= count)
            resources[resourceType] -= count;
        else
            throw std::invalid_argument("Invalid dont have enough resource type");
    }
    int Player::getResourceCount(const std::string &getResource) const
    {
        ResourceType resourceType = getResourceTypeFromString(getResource);
        auto it = resources.find(resourceType);
        return (it != resources.end()) ? it->second : 0;
    }
    int Player::countResources() // for dice=7 need to remove if you have more then 7 resources
    {
        int count = 0;
        count += getResourceCount("WOOD");
        count += getResourceCount("BRICK");
        count += getResourceCount("SHEEP");
        count += getResourceCount("WHEAT");
        count += getResourceCount("IRON");
        return count;
    }
    void Player::addDevelopment(const std::string &getDevelopment)
    {
        try
        {
            CardType developmentType = getCardTypeFromString(getDevelopment);
            std::shared_ptr<Card> card = createCard(developmentType);
            if (card->getHowMuchLeft() > 0)
            {
                card->reduceCard();
                development[developmentType]++;
            }
            else
                throw std::invalid_argument("dont have any card left from this card cant add it to your hand");
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    bool Player::isInputsValid(const vector<string> &places, const vector<int> &placesNum)
    {
        for (string s : places)
        {
            if (!(s == "Forest" || s == "Hills" || s == "Pasture Land" || s == "Agricultural Land" || s == "Mountains" || s == "Desert"))
                return false;
            cout << s << endl;
        }
        for (int i : placesNum)
        {
            if (i < 0 || i > 53)
                return false;
            cout << i << endl;
        }
        return true;
    }
    void Player::useDevelopment(const std::string &removeDevelopment)
    {
        try
        {
            CardType developmentType = getCardTypeFromString(removeDevelopment);

            if (development[developmentType] > 0)
                development[developmentType]--;
            else
                throw std::invalid_argument("Invalid dont have enough development card type");

            if (removeDevelopment == "knight")
                this->knight++;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    int Player::getDevelopmentCardCount(const string &getDevelopment) const
    {
        CardType developmentType = getCardTypeFromString(getDevelopment);
        auto it = development.find(developmentType);
        if (it != development.end())
        {
            return it->second;
        }
        else
        {
            return 0;
        }
    }
    int Player::rollDice(Board &board)
    {
        try
        {
            if (this->hisTurn)
            {
                int dice = rand() % 12 + 1;
                int robber = -1;
                while (robber == -1 && dice == 7)
                {
                    try
                    {
                        cout << "enter number betwween 0 to 18 to put in the tile that the robber will be there:" << endl;
                        cin >> robber;
                        if (robber > 19 && robber < 0)
                            throw std::invalid_argument("Not Between 0 to 18 try again");
                    }
                    catch (const std::exception &e)
                    {
                        robber = -1;
                        cout << e.what() << endl;
                    }
                }
                board.giveResourceByDice(dice, robber);
                return dice;
            }
            else
                throw std::invalid_argument("Not the player turn");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
        return 0;
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
    // need to check the resource if valid
    void Player::trade(Player &other, const std::string &giveResource, const std::string &getResource, int giveAmount, int getAmount)
    {
        try
        {
            if (this->hisTurn)
            {
                if (!getHasBuild())
                {
                    if (giveAmount > 0 && getAmount > 0)
                    {
                        if (this->getResourceCount(giveResource) > giveAmount && other.getResourceCount(getResource) > getAmount)
                        {
                            this->removeResource(giveAmount, giveResource);
                            this->addResource(getAmount, getResource);
                            other.removeResource(getAmount, getResource);
                        }
                        else
                            throw std::invalid_argument("one of the player doesnt have the amount of resource to give");
                    }
                    else
                        throw std::invalid_argument("the amount of the give or get resource need to be more than 0");
                }
                else
                    throw std::invalid_argument("the player has already build so he cant trade");
            }
            else
                throw std::invalid_argument("Not the player turn");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
    }
    void Player::tradeMonopoly(Player &other, const string &giveResource, const string &getResource, int giveAmount, int getAmount)
    {

        bool build = this->getHasBuild();
        this->hasBuild(false);              // if he has build he cant trade but this card can trade because it development
        this->addResource(1, giveResource); // get one so can do trade if has zero
        trade(other, giveResource, getResource, giveAmount, getAmount);
        other.removeResource(1, giveResource); // reduce one because got one from this player that should be zero
        this->hasBuild(build);                 // if the player has build return it to true
    }
    void Player::buyDevelopmentCard()
    {
        try
        {
            if (this->hisTurn)
                if (getResourceCount("SHEEP") > 0 && getResourceCount("WHEAT") > 0 && getResourceCount("IRON") > 0)
                {

                    int i = 0;
                    int random = rand() % 5;
                    CardType c;
                    while (i < 5)
                    {
                        c = CardType(random);
                        std::shared_ptr<Card> card = createCard(c);
                        if (card->getHowMuchLeft() > 0)
                            break;
                        i++;
                        random = (random + 1) % 5;
                    }
                    std::shared_ptr<Card> card = createCard(c);
                    if (card->getHowMuchLeft() > 0)
                    {
                        cout << "the player:" << this->getName() << "got this card:" << c << endl;
                        development[c]++;
                        removeResource(1, "SHEEP");
                        removeResource(1, "WHEAT");
                        removeResource(1, "IRON");
                    }
                    else
                        throw std::invalid_argument("Invalid we run out of card development so we cant buy any more card");
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
    bool Player::hasDevelopment() const
    {
        bool b = false;
        if (getDevelopmentCardCount("Knight") > 0 || getDevelopmentCardCount("Road Builder") > 0 || getDevelopmentCardCount("Monopoly") > 0 || getDevelopmentCardCount("Year Of Plenty") > 0 || getDevelopmentCardCount("Victory Point") > 0)
            b = true;
        return b;
    }
    void Player::printDevelopment() const
    {
        string s = "";
        if (!hasDevelopment())
        {
            if (getDevelopmentCardCount("KNIGHT") > 0)
                s += "KNIGHT / ";
            if (getDevelopmentCardCount("ROAD_BUILDER") > 0)
                s += "ROAD_BUILDER / ";
            if (getDevelopmentCardCount("MONOPOLY") > 0)
                s += "MONOPOLY / ";
            if (getDevelopmentCardCount("YEAR_OF_PLENTY") > 0)
                s += "YEAR_OF_PLENTY / ";
            if (getDevelopmentCardCount("VICTORY_POINT") > 0)
                s += "VICTORY_POINT / ";
            s = s.substr(0, s.size() - 3);
            cout << "choose from: " << s << endl;
        }
    }
    bool Player::placeSettelemnt(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    { // check if there are enough resource to build
        try
        {
            if (this->hisTurn || places.size() == placesNum.size())
            {
                if (isInputsValid(places, placesNum))
                {

                    if (getResourceCount("WOOD") > 0 && getResourceCount("SHEEP") > 0 && getResourceCount("WHEAT") > 0 && getResourceCount("BRICK") > 0 && getNumberOfSettlement() < getSettlementLimit())
                    {
                        std::vector<std::shared_ptr<Tile>> t = board.findTiles(places, placesNum);
                        int node = board.findNode(t);
                        if (node == -1)
                            throw std::invalid_argument("Invalid node, cant find the other node to connect to");
                        bool canPlace = board.placeSettlement(node, *this, this->countNumOfTurn);
                        if (canPlace && this->countSettlements < getSettlementLimit())
                        {
                            removeResource(1, "WOOD");
                            removeResource(1, "SHEEP");
                            removeResource(1, "WHEAT");
                            removeResource(1, "BRICK");
                            this->countSettlements++;
                            this->addVictoryPoints();
                            cout << getName() << " has build settelemnt" << endl;
                        }
                        else
                            throw std::invalid_argument("Invalid cant place settlement or got to the limit");
                    }
                    else
                        throw std::invalid_argument("Invalid dont have enough resource type or dont have enough settelemnt to build");
                }
                else
                    throw std::invalid_argument("Invalid Inputs");
            }
            else
                throw std::invalid_argument("Not the player turn or the places and numbers not of the same size");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
            return 0;
        }
        return 1;
    }
    bool Player::placeCity(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    {
        try
        {
            if (this->hisTurn || places.size() == placesNum.size())
            {
                if (isInputsValid(places, placesNum))
                {
                    if (getResourceCount("IRON") > 3 && getResourceCount("WHEAT") > 2 && getNumberOfCity() < getCityLimit())
                    {
                        std::vector<std::shared_ptr<Tile>> t = board.findTiles(places, placesNum);
                        int node = board.findNode(t);
                        if (node == -1)
                            throw std::invalid_argument("Invalid node, cant find the other node to connect to");
                        bool canPlace = board.placeCity(node, *this);
                        if (canPlace && this->countCity < getCityLimit())
                        {
                            removeResource(2, "WHEAT");
                            removeResource(3, "IRON");
                            this->countCity++;
                            this->countSettlements--;
                            this->addVictoryPoints();
                            cout << getName() << " has build city" << endl;
                        }
                        else
                            throw std::invalid_argument("Invalid cant place city or got to the limit");
                    }
                    else
                        throw std::invalid_argument("Invalid dont have enough resource type or dont have enough city to build");
                }
                else
                    throw std::invalid_argument("Invalid Inputs");
            }
            else
                throw std::invalid_argument("Not the player turn or the places and numbers not of the same size");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
            return 0;
        }
        return 1;
    }
    bool Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    {
        try
        {
            if (this->hisTurn || places.size() == placesNum.size())
            {
                if (isInputsValid(places, placesNum))
                {
                    if (getResourceCount("WOOD") > 0 && getResourceCount("BRICK") > 0 && getNumberOfRoads() < getRoadsLimit())
                    {
                        std::vector<std::shared_ptr<Tile>> t = board.findTiles(places, placesNum);
                        int node = board.findNode(t);
                        if (node == -1)
                            throw std::invalid_argument("Invalid node, cant find the node to connect to");
                        int otherNode = board.findOtherNodeOfRoad(node, countNumOfTurn, *this);
                        if (otherNode == -1)
                            throw std::invalid_argument("Invalid node, cant find the other node to connect to");
                        bool canPlace = board.placeRoad(node, otherNode, *this);
                        if (canPlace && this->countRoads < getRoadsLimit())
                        {
                            removeResource(1, "WOOD");
                            removeResource(1, "BRICK");
                            this->countRoads++;
                            cout << getName() << " has build road" << endl;
                        }
                        else
                            throw std::invalid_argument("Invalid cant place road or got to the limit");
                    }
                    else
                        throw std::invalid_argument("Invalid dont have enough resource type or dont have enough roads to build");
                }
                else
                    throw std::invalid_argument("Invalid Inputs");
            }
            else
                throw std::invalid_argument("Not the player turn or the places and numbers not of the same size");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
            return 0;
        }
        return 1;
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
    void Player::printStatsOfPlayer() const
    {
        cout << this->getName() << "'s has in hand:";
        string s = "";
        if (getResourceCount("WOOD"))
            s += "\nWOOD:" + getResourceCount("WOOD");
        if (getResourceCount("BRICK"))
            s += "\nBRICK:" + getResourceCount("BRICK");
        if (getResourceCount("SHEEP"))
            s += "\nSHEEP:" + getResourceCount("SHEEP");
        if (getResourceCount("WHEAT"))
            s += "\nWHEAT:" + getResourceCount("WHEAT");
        if (getResourceCount("IRON"))
            s += "\nIRON:" + getResourceCount("IRON");

        if (getDevelopmentCardCount("KNIGHT"))
            s += "\nKNIGHT:" + getDevelopmentCardCount("KNIGHT");
        if (getDevelopmentCardCount("ROAD_BUILDER"))
            s += "\nROAD_BUILDER:" + getDevelopmentCardCount("ROAD_BUILDER");
        if (getDevelopmentCardCount("MONOPOLY"))
            s += "\nMONOPOLY:" + getDevelopmentCardCount("MONOPOLY");
        if (getDevelopmentCardCount("YEAR_OF_PLENTY"))
            s += "\nYEAR_OF_PLENTY:" + getDevelopmentCardCount("YEAR_OF_PLENTY");
        if (getDevelopmentCardCount("VICTORY_POINT"))
            s += "\nVICTORY_POINT:" + getDevelopmentCardCount("VICTORY_POINT");

        cout << s << endl;
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