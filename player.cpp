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
        // this->board=board;
    }
    // void Player::setBoard(const std::shared_ptr<Board> &board)
    // {
    //     this->board=board;
    // }
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
    // void Player::addResource(int count, const std::string &getResource)
    // {
    //     if (count <= 0)
    //     {
    //         throw std::invalid_argument("Resource count must be positive");
    //     }

    //     ResourceType resourceType = getResourceTypeFromString(getResource);
    //     std::shared_ptr<Resource> resource = createResource(resourceType);

    //     // Attempt to insert the new resource with count
    //     auto insertionResult = resources.emplace(resource, count);

    //     // Check if insertion was successful (i.e., resource didn't exist before)
    //     if (!insertionResult.second)
    //     {
    //         // If resource already existed, update its count
    //         insertionResult.first->second += count;
    //     }
    // }

    void Player::addResource(int count, const std::string &getResource)
    {
        ResourceType resourceType = getResourceTypeFromString(getResource);
        // std::shared_ptr<Resource> res = createResource(resourceType);
        if (count > 0)
            resources[resourceType] += count;
    }

    // void Player::addResource(int count, const std::string &getResource)
    // {
    //     if (count <= 0)
    //     {
    //         return; // Handle non-positive count (optional)
    //     }

    //     ResourceType resourceType = getResourceTypeFromString(getResource);
    //     std::shared_ptr<Resource> res = createResource(resourceType);

    //     // Check if resource already exists in the map (optional)
    //     auto it = resources.find(res.get());
    //     if (it != resources.end())
    //     {
    //         it->second += count; // Update existing resource count
    //     }
    //     else
    //     {
    //         // Add new resource if not found
    //         resources[res.get()] = count;
    //     }
    // }
    void Player::removeResource(int count, const std::string &removeResource)
    {
        ResourceType resourceType = getResourceTypeFromString(removeResource);
        // std::shared_ptr<Resource> res = createResource(resourceType);
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
    int Player::countResources() // for dice=7 need to remove if you have moreN then 7 resources
    {
        // string listres = {"wood", "ss"};
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
        CardType developmentType = getCardTypeFromString(getDevelopment);
        // std::shared_ptr<Card> card = createCard(developmentType);
        development[developmentType]++;
    }

    // when i use road or knight i need to sent to catan so it will check with all the player who has the most
    // when i use knight go to catan and check who has the most knight so he will get the card instead another player
    void Player::useDevelopment(const std::string &removeDevelopment)
    {
        try
        {
            CardType developmentType = getCardTypeFromString(removeDevelopment);
            // std::shared_ptr<Card> card = createCard(developmentType);
            if (development[developmentType] > 0)
                development[developmentType]--;
            else
                throw std::invalid_argument("Invalid dont have enough resource type");

            if (removeDevelopment == "knight")
            {
                this->knight++;
                // if()//sent to catan to check if this player deserve cardknight
                this->setKnightCard(true);
            }
            if (removeDevelopment == "Road Builder")
                this->countRoads++;
            // if(removeDevelopment== "Monopoly"){
            //     cout<<"choose one resource to get from all the player"<<endl;
            //     string s;
            //     cin>>s;

            // }
            //  if(removeDevelopment=="Year Of Plenty")
            //  if(removeDevelopment== "Victory Point")
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
        // std::shared_ptr<Card> card = createCard(developmentType);
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
    // when i use road i need to sent to catan so it will check with all the player who has the most
    // void Player::pieceBuild(const std::string &getPiece, const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    // { // need to do while so i can try to put city in someplace and get true or false if false try someplace else or if there is no place at all to put
    //   // need func to do that
    // }

    void Player::rollDice(Board &board)
    {
        try
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
                board.giveResourceByDice(dice, robber);
            }
            else
                throw std::invalid_argument("Not the player turn");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
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
                        // check if both the resource are valid
                        //  ResourceType resourceType1 = getResourceTypeFromString(getResource);
                        //  std::shared_ptr<Resource> res = createResource(resourceType1);
                        //  ResourceType resourceType2 = getResourceTypeFromString(giveResource);
                        //  std::shared_ptr<Resource> res = createResource(resourceType2);
                        // check both the amount
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
                    // std::shared_ptr<Card> card = createCard(c);
                    cout << "the player:" << this->getName() << "got this card:" << c << endl;
                    development[c]++;
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
        if (getDevelopmentCardCount("Knight") > 0)
            return false;
        if (getDevelopmentCardCount("Road Builder") > 0)
            return false;
        if (getDevelopmentCardCount("Monopoly") > 0)
            return false;
        if (getDevelopmentCardCount("Year Of Plenty") > 0)
            return false;
        if (getDevelopmentCardCount("Victory Point") > 0)
            return false;
        return true;
    }
    void Player::placeSettelemnt(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    { // check if there are enough resource to build
        try
        {
            if (this->hisTurn)
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
                throw std::invalid_argument("Not the player turn");
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
        if (countResources() < 1)
            endTurn();
    }
    void Player::placeCity(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    {
        try
        {
            if (this->hisTurn)
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
                        this->addVictoryPoints();
                        cout << getName() << " has build city" << endl;
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
    void Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board)
    {
        try
        {
            if (this->hisTurn)
            {

                if (getResourceCount("WOOD") > 0 && getResourceCount("BRICK") > 0 && getNumberOfRoads() < getRoadsLimit())
                {
                    std::vector<std::shared_ptr<Tile>> t = board.findTiles(places, placesNum);
                    int node = board.findNode(t);
                    if (node == -1)
                        throw std::invalid_argument("Invalid node, cant find the node to connect to");
                    int otherNode = board.findOtherNodeOfRoad(node,countNumOfTurn, *this);
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