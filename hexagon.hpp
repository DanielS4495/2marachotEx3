//danielsamson10@gmail.com
#pragma once
#include "player.hpp"
namespace ariel
{
    class Tile;
    class Node
    {
    private:
        int number;
        bool hasSettlement;
        bool hasCity;
        Player *owner=nullptr;
        vector<Node> connectNode;
        std::vector<std::shared_ptr<Tile>> tiles;

    public:
        ~Node() = default;
        Node(int number,const std::vector<std::shared_ptr<Tile>> &tiles);
        std::vector<std::shared_ptr<Tile>> getTile() const;
        int getNumber() const;
        bool getHasSettlement() const;
        bool getHasCity() const;
        Player *getOwner() const;
        vector<Node> getConnectNode() const;
        void setHasSettlement(bool has,Player &p);
        void setHasCity(bool has,Player &p);
        void setOwner(Player &p);
        void setConnectNode(vector<Node> node);
    };
    class Road
    {
    private:
        Node *n1;
        Node *n2;
        bool hasRoad;
        Player *owner;

    public:
        ~Road() = default;
        Road(Node &n1, Node &n2, Player &p);
        bool getHasRoad() const;
        Node *getNode1() const;
        Node *getNode2() const;
        Player *getOwner() const;
        void setRoad(bool has);
    };

}