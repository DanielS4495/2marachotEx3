#pragma once
// #include <string>
#include "player.hpp"
// #include "tile.hpp"
// #include <vector>
namespace ariel
{
    // class Hexagon
    // {
    // private:
    //     // Resource type (enum or string)
    //     std::string resourceType;
    //     int number;
    //     // Flag for robber presence (optional)
    //     bool hasRobber;
    //     vector<int> node; // connected node number

    // public:
    //     Hexagon(int number, std::string resourceType, vector<int> nodes);
    //     std::string getResourceType();
    //     int getNumber();
    //     bool getHasRobber();
    //     vector<int> getnodes();
    // };
    class Tile;
    class Node
    {
    private:
        // Hexagon hexagons[2]; // Pointers to connected hexagons
        int number;
        bool hasSettlement;
        bool hasCity;
        Player *owner=nullptr;
        vector<Node> connectNode;
        // vector<Node> connectNodeByRoads;
        // vector<Tile *> tile;
        // std::shared_ptr<Tile> tiles;
        std::vector<std::shared_ptr<Tile>> tiles;

    public:
        ~Node() = default;
        Node(int number,const std::vector<std::shared_ptr<Tile>> &tiles);
        // helper
        // Node(int number, std::shared_ptr<Tile> tile);
        // Node(int number, std::shared_ptr<Tile> tile1, std::shared_ptr<Tile> tile2);
        // Node(int number, std::shared_ptr<Tile> tile1, std::shared_ptr<Tile> tile2, std::shared_ptr<Tile> tile3);
        // get
        std::vector<std::shared_ptr<Tile>> getTile() const;
        int getNumber() const;
        bool getHasSettlement() const;
        bool getHasCity() const;
        Player *getOwner() const;
        vector<Node> getConnectNode() const;
        // vector<Node> getConnectNodeByRoads() const;
        // set
        void setHasSettlement(bool has,Player &p);
        void setHasCity(bool has,Player &p);
        void setOwner(Player &p);
        // void setConnectNodeByRoads(Node node);
        void setConnectNode(vector<Node> node);
        // helper
        // void setConnectNode(Node node);
        // void setConnectNode(Node node1, Node node2);
        // void setConnectNode(Node node1, Node node2, Node node3);
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