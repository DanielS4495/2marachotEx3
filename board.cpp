#pragma
#include <stdexcept>

#include "board.hpp"
namespace ariel
{

    Board::Board()
    {
        // // Initialize the board with different tiles and numbers
        // tiles.push_back(std::make_shared<ForestTile>(5));
        // tiles.push_back(std::make_shared<HillsTile>(6)); //גבעות
        // tiles.push_back(std::make_shared<PastureTile>(8));//מרעה
        // tiles.push_back(std::make_shared<FieldsTile>(9));//שדות
        // tiles.push_back(std::make_shared<MountainsTile>(10));
        // tiles.push_back(std::make_shared<DesertTile>());

        tiles[1] = std::make_shared<Tile>(MountainsTile, 10);
        tiles[2] = std::make_shared<Tile>(PastureTile, 2);
        tiles[3] = std::make_shared<Tile>(ForestTile, 9);
        tiles[4] = std::make_shared<Tile>(FieldsTile, 12);
        tiles[5] = std::make_shared<Tile>(HillsTile, 6);
        tiles[6] = std::make_shared<Tile>(PastureTile, 4);
        tiles[7] = std::make_shared<Tile>(HillsTile, 10);
        tiles[8] = std::make_shared<Tile>(FieldsTile, 9);
        tiles[9] = std::make_shared<Tile>(ForestTile, 11);
        tiles[10] = std::make_shared<Tile>(DESERTE, 0); // Desert has no number
        tiles[11] = std::make_shared<Tile>(ForestTile, 3);
        tiles[12] = std::make_shared<Tile>(MountainsTile, 8);
        tiles[13] = std::make_shared<Tile>(ForestTile, 8);
        tiles[14] = std::make_shared<Tile>(MountainsTile, 3);
        tiles[15] = std::make_shared<Tile>(FieldsTile, 4);
        tiles[16] = std::make_shared<Tile>(PastureTile, 5);
        tiles[17] = std::make_shared<Tile>(HillsTile, 5);
        tiles[18] = std::make_shared<Tile>(FieldsTile, 6);
        tiles[19] = std::make_shared<Tile>(PastureTile, 11);
        adjList = {
            {1, {2, 4, 5}},
            {2, {1, 3, 5, 6}},
            {3, {2, 6, 7}},
            {4, {1, 5, 8, 9}},
            {5, {1, 2, 4, 6, 9, 10}},
            {6, {2, 3, 5, 7, 10, 11}},
            {7, {3, 6, 11, 12}},
            {8, {4, 9, 13}},
            {9, {4, 5, 8, 10, 13, 14}},
            {10, {5, 6, 9, 11, 14, 15}},
            {11, {6, 7, 10, 12, 15, 16}},
            {12, {7, 11, 16}},
            {13, {8, 9, 14, 17}},
            {14, {9, 10, 13, 15, 17, 18}},
            {15, {10, 11, 14, 16, 18, 19}},
            {16, {11, 12, 15, 19}},
            {17, {13, 14, 18}},
            {18, {14, 15, 17, 19}},
            {19, {15, 16, 18}}};
    }
    static std::shared_ptr<Board> getInstance()
    {
        static std::shared_ptr<Board> instance(new Board());
        return instance;
    }
    bool Board::areAdjacent(int node1, int node2)
    {
        for (const auto &adjNode : adjList[node1])
        {
            if (adjNode == node2)
            {
                return true;
            }
        }
        return false;
    }

    bool Board::placeSettlement(int node, const Player &player)
    {
        // Ensure the placement is valid
        if (settlements.find(node) != settlements.end())
        {
            return false; // Settlement already exists
        }

        // Check if any neighboring nodes already have settlements
        for (const auto &adjNode : adjList[node])
        {
            if (settlements.find(adjNode) != settlements.end())
            {
                return false; // Settlement adjacent to another settlement
            }
        }

        settlements[node] = std::make_shared<Settlement>(node);
        return true;
    }
    bool Board::placeCity(int node, const Player &player)
    {
        std::shared_ptr<Piece> piece = getPieceAtNode(node);

        // Check if the piece at the node is a Settlement and belongs to the player
        if (piece && piece->getType() == "settlement" && piece->getPlayer().getName() == player.getName())
        {
            // Remove the settlement
            removePieceAtNode(node);

            // Place the city
            std::shared_ptr<Piece> city = std::make_shared<City>(player);
            placePieceAtNode(node, city);

            return true;
        }

        // No settlement of the same player at the node
        return false;
    }
    bool Board::placeRoad(int node1, int node2, const Player &player)
    {
        // Ensure the placement is valid
        if (!areAdjacent(node1, node2) || roads.find(node1) != roads.end() || roads.find(node2) != roads.end())
        {
            return false; // Invalid road placement
        }

        roadAdjList[node1].push_back(node2);
        roadAdjList[node2].push_back(node1);
        roads[node1] = std::make_shared<Road>(node1);
        roads[node2] = std::make_shared<Road>(node2);
        return true;
    }

    std::shared_ptr<Piece> Board::getPieceAtNode(int node)
    {
        return std::shared_ptr<Piece>();
    }

    // std::shared_ptr<Tile> getTile(int node)
    // {
    //     if (tiles.find(node) != tiles.end())
    //     {
    //         return tiles[node];
    //     }
    //     return nullptr;
    // }

    void Board::removePieceAtNode(int node)
    {
    }

    void Board::placePieceAtNode(int node, std::shared_ptr<Piece> piece)
    {
    }

    void Board::printBoard() const
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
