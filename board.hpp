#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "tile.hpp"
#include "piece.hpp"
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
        // int BOARD_SIZE = 5;
        static std::shared_ptr<Board> instance;
        // int numberRobberTile = -1;
        int robberPresent = -1;
        // std::unordered_map<int, std::vector<int>> adjList;     // Adjacency list for settlements
        // std::unordered_map<int, std::vector<int>> roadAdjList; // Adjacency list for roads
        // std::unordered_map<int, std::shared_ptr<Tile>> tiles;
        std::vector<Tile *> tiles; // Tiles on the board
        std::vector<Node> nodes;
        std::vector<Road> roads;
        int hasRobber() const;
        void setRobber(int hasRobber);
        // std::unordered_map<int, std::shared_ptr<Piece>> placement; // Settlements placed on nodes
        // std::unordered_map<int, int> roads;                        // Roads placed on edges
        // std::unordered_map<std::pair<int, int>, Player> roads_;
        // std::unordered_map<int, std::shared_ptr<Piece>> city;              // city placed on nodes
        // vector<Tile *> findTiles(vector<string> place, vector<int> number); // find the tiles we looking for
        // int findNode(vector<Tile *> t);                                     // find the node we are looking for
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
        // std::shared_ptr<Piece> getPieceAtNode(int node);
        // void removePieceAtNode(int node);
        // void placePieceAtNode(int node, std::shared_ptr<Piece> piece);
        void printBoard() const;
        void moveRobber(int tileNumber);
        void giveResourceByDice(int dice);
        vector<Tile *> findTiles(vector<string> place, vector<int> number); // find the tiles we looking for
        int findNode(vector<Tile *> t);                                     // find the node we are looking for
        // std::shared_ptr<Tile *> getTile(int tileNumber) const;
        // Node getNodeWithInt(size_t i) const;
    };

}
