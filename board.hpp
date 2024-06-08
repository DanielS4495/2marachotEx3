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
    class Player;
    class Catan;
    class Board
    {
    private:
        int BOARD_SIZE = 5;
        static std::shared_ptr<Board> instance;
        std::unordered_map<int, std::vector<int>> adjList;           // Adjacency list for settlements
        std::unordered_map<int, std::vector<int>> roadAdjList;       // Adjacency list for roads
        // std::unordered_map<int, std::shared_ptr<Tile>> tiles;
        std::vector<Tile *> tiles;                                   // Tiles on the board
        std::vector<Node *> nodes;   
        std::unordered_map<int, std::shared_ptr<Piece>> settlements; // Settlements placed on nodes
        std::unordered_map<int, std::shared_ptr<Piece>> roads;       // Roads placed on edges
        std::unordered_map<int, std::shared_ptr<Piece>> city;        // city placed on nodes

    public:
        Board(const Board &) = delete;               // Disable copy constructor
        Board &operator=(const Board &) = delete;    // Disable assignment operator
        static std::shared_ptr<Board> getInstance(); // give access as singelton
        ~Board();
        Board();
        bool areAdjacent(int node1, int node2);
        bool placeSettlement(int node, const Player &player);
        bool placeCity(int node, const Player &player);
        bool placeRoad(int node1, int node2, const Player &player);
        std::shared_ptr<Piece> getPieceAtNode(int node);
        void removePieceAtNode(int node);
        void placePieceAtNode(int node, std::shared_ptr<Piece> piece);

        void printBoard() const;
        void moveRobber(int tileNumber);
        std::shared_ptr<Tile> getTile(int tileNumber) const;
    };

}
