#include <string>
#include "player.hpp"
#include "tile.hpp"
#include <vector>
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

    class Node
    {
    private:
        // Hexagon *hexagons[2]; // Pointers to connected hexagons
        int number;
        bool hasSettlement;
        bool hasCity;
        Player *owner;
        vector<Node *> connectNode;
        vector<Tile *> tile;

    public:
        Node(int number, vector<Tile *> tile);
        // Hexagon *getHexagons(); // Pointers to connected hexagons
        vector<Tile *> getTile();
        int getNumber();
        bool getHasSettlement();
        bool getHasCity();
        Player *getOwner();
        vector<Node *> getConnectNode();
        void setHasSettlement(bool has);
        void setHasCity(bool has);
        void setOwner(Player &p);
        void setConnectNode(vector<Node *> node);
    };

    // class Board
    // {
    // public:
    //     Board(int size)
    //     {
    //         board = new Hexagon *[size];
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
    //     Hexagon **board;

    //     bool hasAdjacentSettlement(int x, int y)
    //     {
    //         // Implement logic to check for settlements in neighboring nodes
    //         // based on x, y coordinates within the board array
    //     }
    // };
}