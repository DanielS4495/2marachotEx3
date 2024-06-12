#include "hexagon.hpp"
#include "tile.hpp"
namespace ariel
{
    Node::Node(int number, vector<Tile *> tile)
    {
        this->number = number;
        this->tile = tile;
        this->hasSettlement = NULL;
        this->hasCity = NULL;
        this->owner = NULL;
    }
    Node::Node(int number, Tile *tile)
    {
        vector<Tile *> t;
        t.push_back(tile);
        Node(number, t);
    }
    Node::Node(int number, Tile *tile1, Tile *tile2)
    {
        vector<Tile *> t;
        t.push_back(tile1);

        t.push_back(tile1);

        Node(number, t);
    }
    Node::Node(int id, Tile *tile1, Tile *tile2, Tile *tile3)
    {
        vector<Tile *> t;
        t.push_back(tile1);

        t.push_back(tile2);

        t.push_back(tile3);
        Node(id, t);
    }
    vector<Tile *> Node::getTile() const
    {
        return this->tile;
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
    // vector<Node> Node::getConnectNodeByRoads() const
    // {
    //     return this->connectNodeByRoads;
    // }
    void Node::setHasSettlement(bool has) //if has city cant put also settlement
    {
        if(!getHasCity())
        this->hasSettlement = has;
    }
    void Node::setHasCity(bool has) //change first settlement before change city
    {
        if(!getHasSettlement())
        this->hasCity = has;
    }
    void Node::setOwner(Player &p)
    {
        this->owner = &p;
    }
    void Node::setConnectNode(vector<Node> node)
    {
        this->connectNode = node;
    }
    void Node::setConnectNode(Node node)
    {
        vector<Node> n;
        n.push_back(node);
        setConnectNode(n);
    }
    void Node::setConnectNode(Node node1, Node node2)
    {
        vector<Node> n;
        n.push_back(node1);
        n.push_back(node2);
        setConnectNode(n);
    }
    void Node::setConnectNode(Node node1, Node node2, Node node3)
    {
        vector<Node> n;
        n.push_back(node1);
        n.push_back(node2);
        n.push_back(node3);
        setConnectNode(n);
    }
    Road::Road(Node &n1, Node &n2, Player &p)
    {
        this->n1=&n1;
        this->n2=&n2;
        this->owner=&p;
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