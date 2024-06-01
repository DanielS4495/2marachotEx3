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
        std::vector<std::shared_ptr<Tile>> tiles;
    public:
        Board();
        void printBoard() const;
        void Board::moveRobber(int tileNumber);
        std::shared_ptr<Tile> Board::getTile(int tileNumber) const;
    };
}
