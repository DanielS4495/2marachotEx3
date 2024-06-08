#include "hexagon.hpp"
namespace ariel
{
    ariel::Node::Node(int number, vector<Tile *> tile)
    {
        this->number = number;
        this->tile = tile;
        this->hasSettlement = NULL;
        this->hasCity = NULL;
        this->owner = NULL;
    }
    vector<Tile *> Node::getTile()
    {
        return this->tile;
    }
    int Node::getNumber()
    {
        return this->number;
    }
    bool Node::getHasSettlement()
    {
        return this->hasSettlement;
    }
    bool Node::getHasCity()
    {
        return this->hasCity;
    }
    Player *Node::getOwner()
    {
        return this->owner;
    }
    vector<Node *> Node::getConnectNode()
    {
        return this->connectNode;
    }
    void Node::setHasSettlement(bool has)
    {
        this->hasSettlement = has;
    }
    void Node::setHasCity(bool has)
    {
        this->hasCity = has;
    }
    void Node::setOwner(Player &p)
    {
        this->owner = &p;
    }
    void Node::setConnectNode(vector<Node *> node)
    {
        this->connectNode = node;
    }
}