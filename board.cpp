#pragma

#include "board.hpp"
namespace ariel
{

    
        

    
        Board()
        {
            // Initialize the board with different tiles and numbers
            tiles.push_back(std::make_shared<ForestTile>(5));
            tiles.push_back(std::make_shared<HillsTile>(6));
            tiles.push_back(std::make_shared<PastureTile>(8));
            tiles.push_back(std::make_shared<FieldsTile>(9));
            tiles.push_back(std::make_shared<MountainsTile>(10));
            tiles.push_back(std::make_shared<DesertTile>());
            // Add more tiles as needed up to 19
        }

        void printBoard() const
        {
            for (const auto &tile : tiles)
            {
                std::cout << tile->getType() << " (" << tile->getNumber() << ") ";
                if (tile->getResource()->getType() != "None")
                {
                    std::cout << "- Resource: " << tile->getResource()->getType();
                }
                std::cout << std::endl;
            }
        }
        void Board::moveRobber(int tileNumber)
        {
            for (const auto &tile : tiles)
            {
                if (tile->getNumber() == tileNumber)
                {
                    robber.moveTo(tile.get());
                    tile->placeRobber(true);
                }
                else
                {
                    tile->placeRobber(false);
                }
            }
        }
        std::shared_ptr<Tile> Board::getTile(int tileNumber) const
        {
            for (const auto &tile : tiles)
            {
                if (tile->getNumber() == tileNumber)
                {
                    return tile;
                }
            }
            return nullptr; // If tile not found
        }
    }

