//danielsamson10@gmail.com
#include "hexagon.hpp"
#include "tile.hpp"
namespace ariel
{
    Node::Node(int number, const std::vector<std::shared_ptr<Tile>> &tiles)
    {
        this->number = number;
        this->tiles = tiles;
        this->hasSettlement = false;
        this->hasCity = false;
        this->owner = NULL;
    }
    std::vector<std::shared_ptr<Tile>> Node::getTile() const
    {
        return this->tiles;
    }
    int Node::getNumber() const
    {
        return this->number;
    }
    bool Node::getHasSettlement() const
    {
        return this->hasSettlement;
    }
    bool Node::getHasCity() const
    {
        return this->hasCity;
    }
    Player *Node::getOwner() const
    {
        return this->owner;
    }
    vector<Node> Node::getConnectNode() const
    {
        return this->connectNode;
    }
    void Node::setHasSettlement(bool has, Player &p) // if has city cant put also settlement
    {
        if (!getHasCity())
        {
            this->hasSettlement = has;
            this->setOwner(p);
        }
        else cout<<"cant place settlement player has already city in here"<<endl;
    }
    void Node::setHasCity(bool has, Player &p) // change first settlement before change city
    {
            this->setHasSettlement(false,p);
            this->hasCity = has;
            this->setOwner(p);
    }
    void Node::setOwner(Player &p)
    {
        this->owner = &p;
    }
    void Node::setConnectNode(vector<Node> node)
    {
        this->connectNode = node;
    }
    Road::Road(Node &n1, Node &n2, Player &p)
    {
        this->n1 = &n1;
        this->n2 = &n2;
        this->owner = &p;
    }
    bool Road::getHasRoad() const
    {
        return this->hasRoad;
    }
    Node *Road::getNode1() const
    {
        return this->n1;
    }
    Node *Road::getNode2() const
    {
        return this->n2;
    }
    Player *Road::getOwner() const
    {
        return this->owner;
    }
    void Road::setRoad(bool has)
    {
        this->hasRoad = has;
    }
}