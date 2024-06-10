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
        Player *owner;
        vector<Node > connectNode;
        vector<Tile *> tile;

    public:
        ~Node() = default;
        Node(int number, vector<Tile *> tile);                   // 1
        Node(int number, Tile* tile);                            // 2
        Node(int number, Tile* tile1, Tile* tile2);              // 3
        Node(int number, Tile* tile1, Tile* tile2, Tile* tile3); // 4
        // Hexagon getHexagons(); // Pointers to connected hexagons
        vector<Tile *> getTile();
        int getNumber();
        bool getHasSettlement();
        bool getHasCity();
        Player* getOwner();
        vector<Node > getConnectNode();
        void setHasSettlement(bool has);
        void setHasCity(bool has);
        void setOwner(Player &p);
        void setConnectNode(vector<Node > node);
        void setConnectNode(Node node);
        void setConnectNode(Node node1, Node node2);
        void setConnectNode(Node node1, Node node2, Node node3);
    };
    // Node createNode(int id, Tile tile1 = nullptr, Tile tile2 = nullptr, Tile tile3 = nullptr) {
    //   std::vector<Tile> connectedTiles;
    //   connectedTiles.push_back(tile1);
    //   connectedTiles.push_back(tile2);
    //   connectedTiles.push_back(tile3);

    //   // Remove any nullptr values from the vector (optional)
    //   connectedTiles.erase(std::remove(connectedTiles.begin(), connectedTiles.end(), nullptr), connectedTiles.end());
    // std::remove()
    //   return new Node(id, connectedTiles);
    // }

    // class Board
    // {
    // public:
    //     Board(int size)
    //     {
    //         board = new Hexagon [size];
    //         for (int i = 0; i < size; ++i)
    //         {
    //             board[i] = new Hexagon[size];
    //             // Initialize hexagon resource types here
    //         }
    //     }

    //     Node getNode(int x, int y)
    //     {
    //         // Implement logic to calculate node based on x, y coordinates
    //         // within the board array
    //     }

    //     bool canPlaceSettlement(int x, int y)
    //     {
    //         Node node = getNode(x, y);
    //         // Check if node is unoccupied and adjacent to existing settlements
    //         return !node.hasSettlement && hasAdjacentSettlement(x, y);
    //     }

    // private:
    //     Hexagon board;

    //     bool hasAdjacentSettlement(int x, int y)
    //     {
    //         // Implement logic to check for settlements in neighboring nodes
    //         // based on x, y coordinates within the board array
    //     }
    // };
}