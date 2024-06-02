#pragma

#include "tile.hpp"
#include <vector>
#include <memory>
#include <iostream>
namespace ariel
{

    class Board
    {
    private:
        std::unordered_map<int, std::vector<int>> adjList;                // Adjacency list for settlements
        std::unordered_map<int, std::vector<int>> roadAdjList;            // Adjacency list for roads
        std::unordered_map<int, std::shared_ptr<Tile>> tiles;             // Tiles on the board
        std::unordered_map<int, std::shared_ptr<Settlement>> settlements; // Settlements placed on nodes
        std::unordered_map<int, std::shared_ptr<Road>> roads;             // Roads placed on edges

    public:
        Board();
        void printBoard() const;
        void Board::moveRobber(int tileNumber);
        std::shared_ptr<Tile> Board::getTile(int tileNumber) const;
    };
}
