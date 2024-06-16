//danielsamson10@gmail.com
#pragma once
#include <stdexcept>
#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "tile.hpp"
#include "hexagon.hpp"

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
        // static std::shared_ptr<Board> instance;
        int robberPresent = -1;
        // std::vector<Tile *> tiles; // Tiles on the board
        std::vector<std::shared_ptr<Tile>> tiles;
        // std::vector<std::shared_ptr<Node>> nodes;
        // std::vector<std::shared_ptr<Road>> roads;
        std::vector<Node> nodes;
        std::vector<Road> roads;
        int hasRobber() const;
        
        int findRoad(int n1, int n2) const;
        PlacementError ValidateSettlement(int node, const Player &player, int countTurn) const;
        PlacementError ValidateCity(int node, const Player &player) const;
        PlacementError ValidateRoad(int node1, int node2, const Player &player) const;

    public:
        Board(const Board &) = delete;               // Disable copy constructor
        Board &operator=(const Board &) = delete;    // Disable assignment operator
        // static std::shared_ptr<Board> getInstance(); // give access as singelton
        // ~Board();
        Board();
        bool placeSettlement(int node, Player &player, int countTurn);
        bool placeCity(int node, Player &player);
        bool placeRoad(int node1, int node2, Player &player);
        void setRobber(int hasRobber); //set robber in tile
        // bool placeSettlementFirstTime(int node, Player &player);
        // bool placeRoadFirstTime(int node1, int node2, Player &player);
        void printBoard() const;
        // void moveRobber(int tileNumber);
        void giveResourceByDice(int dice, int moverobber);
        std::vector<std::shared_ptr<Tile>> findTiles(const std::vector<std::string> &places, const std::vector<int> &placesNum); // find the tiles we looking for
        int findNode(std::vector<std::shared_ptr<Tile>> t);    //find nodes using tiles                                                                  // find the node we are looking for
        int findOtherNodeOfRoad(int Node,int numberofturn, Player &player);             //find the other node that can co                                                          // get node and return the other node for the road
    };

}
