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
    Node::Node(int number, Tile* tile)
    {
        vector<Tile *> t;
        t.push_back(tile);
        Node(number, t);
    }
    Node::Node(int number, Tile* tile1, Tile* tile2)
    {
        vector<Tile *> t;
        t.push_back(tile1);

        t.push_back(tile1);

        Node(number, t);
    }
    Node::Node(int id, Tile* tile1, Tile* tile2, Tile* tile3)
    {
        vector<Tile *> t;
        t.push_back(tile1);

        t.push_back(tile2);

        t.push_back(tile3);
        Node(id, t);
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
    vector<Node> Node::getConnectNode()
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
}