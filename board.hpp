#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "tile.hpp"
// #include "piece.hpp"
#include "hexagon.hpp"
// #include "player.hpp"

namespace ariel
{
    enum class PlacementError
    {
        SUCCESS,
        DONT_HAVE_ROAD_CONNECTED,
        INVALID_NODE,
        NODE_OCCUPIED,
        ROAD_OCCUPIED,
        ADJACENT_SETTLEMENT,
        NO_SETTLEMENT_TO_UPGRADE,
        ROAD_CONNECTION_REQUIRED,
        PLAYER_SETTLEMENT_LIMIT,
        PLAYER_ROAD_LIMIT,
        NODE_OCCUPIED_NOT_BY_SETTLEMENT,
    };
    class Player;
    class Catan;
    class Board
    {
    private:
        static std::shared_ptr<Board> instance;
        int robberPresent = -1;
        std::vector<Tile *> tiles; // Tiles on the board
        std::vector<Node> nodes;
        std::vector<Road> roads;
        int hasRobber() const;
        void setRobber(int hasRobber);
        int findRoad(int n1, int n2) const;
        PlacementError ValidateSettlement(int node, const Player &player) const;
        PlacementError ValidateCity(int node, const Player &player) const;
        PlacementError ValidateRoad(int node1, int node2, const Player &player) const;

    public:
        Board(const Board &) = delete;               // Disable copy constructor
        Board &operator=(const Board &) = delete;    // Disable assignment operator
        static std::shared_ptr<Board> getInstance(); // give access as singelton
        ~Board();
        Board();
        bool placeSettlement(int node, Player &player);
        bool placeCity(int node, Player &player);
        bool placeRoad(int node1, int node2, Player &player);
        void printBoard() const;
        // void moveRobber(int tileNumber);
        void giveResourceByDice(int dice,int moverobber);
        vector<Tile *> findTiles(vector<string> place, vector<int> number); // find the tiles we looking for
        int findNode(vector<Tile *> t);                                     // find the node we are looking for
        int findOtherNodeOfRoad(int Node,Player &player);                                   // get node and return the other node for the road
    };

}
