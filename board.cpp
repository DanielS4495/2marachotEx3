
#include <stdexcept>

#include "board.hpp"
#include "player.hpp"
#include "tile.cpp"
namespace ariel
{
    std::shared_ptr<Board> Board::instance = nullptr;
    Board::Board()
    {   //create tiles and give them numbers of nodes that are connected to them
        //because we create them after the tile
        //give us the oppsition to find the node using tiles
        tiles.push_back(new MountainsTile(10, {1, 4, 5, 8, 9, 10}));
        tiles.push_back(new PastureTile(2, {2, 5, 6, 10, 11, 12}));
        tiles.push_back(new ForestTile(9, {3, 6, 7, 12, 13, 14}));
        tiles.push_back(new AgriculturalTile(12, {8, 9, 15, 17, 18, 19}));
        tiles.push_back(new HillsTile(6, {9, 10, 11, 19, 20, 21}));
        tiles.push_back(new PastureTile(4, {11, 12, 13, 21, 22, 23}));
        tiles.push_back(new HillsTile(10, {13, 14, 16, 23, 24, 25}));
        tiles.push_back(new AgriculturalTile(9, {17, 18, 26, 28, 29, 30}));
        tiles.push_back(new ForestTile(11, {18, 19, 20, 30, 31, 32}));
        tiles.push_back(new DesertTile(0, {20, 21, 22, 32, 33, 34}));
        tiles.push_back(new ForestTile(3, {22, 23, 24, 34, 35, 36}));
        tiles.push_back(new MountainsTile(8, {24, 25, 27, 36, 37, 38}));
        tiles.push_back(new ForestTile(8, {29, 30, 31, 39, 40, 41}));
        tiles.push_back(new MountainsTile(3, {31, 32, 33, 41, 42, 43}));
        tiles.push_back(new AgriculturalTile(4, {33, 34, 35, 43, 44, 45}));
        tiles.push_back(new PastureTile(5, {35, 36, 37, 45, 46, 47}));
        tiles.push_back(new HillsTile(5, {40, 41, 42, 48, 49, 50}));
        tiles.push_back(new AgriculturalTile(6, {42, 43, 44, 50, 51, 52}));
        tiles.push_back(new PastureTile(11, {44, 45, 46, 52, 53, 54}));
        
        //create node and connect them to tiles
        int number = 1;
        nodes.push_back(Node(number++, tiles[1]));
        nodes.push_back(Node(number++, tiles[2]));
        nodes.push_back(Node(number++, tiles[3]));
        nodes.push_back(Node(number++, tiles[1]));
        nodes.push_back(Node(number++, tiles[1], tiles[2]));
        nodes.push_back(Node(number++, tiles[2], tiles[3]));
        nodes.push_back(Node(number++, tiles[3]));
        nodes.push_back(Node(number++, tiles[1], tiles[4]));
        nodes.push_back(Node(number++, tiles[1], tiles[4], tiles[5]));
        nodes.push_back(Node(number++, tiles[1], tiles[2], tiles[5])); // 10
        nodes.push_back(Node(number++, tiles[2], tiles[5], tiles[6]));
        nodes.push_back(Node(number++, tiles[2], tiles[3], tiles[6]));
        nodes.push_back(Node(number++, tiles[3], tiles[6], tiles[7]));
        nodes.push_back(Node(number++, tiles[3], tiles[7]));
        nodes.push_back(Node(number++, tiles[4]));
        nodes.push_back(Node(number++, tiles[7]));
        nodes.push_back(Node(number++, tiles[4], tiles[8]));
        nodes.push_back(Node(number++, tiles[4], tiles[8], tiles[9]));
        nodes.push_back(Node(number++, tiles[4], tiles[5], tiles[9]));
        nodes.push_back(Node(number++, tiles[5], tiles[9], tiles[10])); // 20
        nodes.push_back(Node(number++, tiles[5], tiles[6], tiles[10]));
        nodes.push_back(Node(number++, tiles[6], tiles[10], tiles[11]));
        nodes.push_back(Node(number++, tiles[6], tiles[7], tiles[11]));
        nodes.push_back(Node(number++, tiles[7], tiles[11], tiles[12]));
        nodes.push_back(Node(number++, tiles[7], tiles[12]));
        nodes.push_back(Node(number++, tiles[8]));
        nodes.push_back(Node(number++, tiles[12]));
        nodes.push_back(Node(number++, tiles[8]));
        nodes.push_back(Node(number++, tiles[8], tiles[13]));
        nodes.push_back(Node(number++, tiles[8], tiles[9], tiles[13])); // 30
        nodes.push_back(Node(number++, tiles[9], tiles[13], tiles[14]));
        nodes.push_back(Node(number++, tiles[9], tiles[10], tiles[14]));
        nodes.push_back(Node(number++, tiles[10], tiles[14], tiles[15]));
        nodes.push_back(Node(number++, tiles[10], tiles[11], tiles[15]));
        nodes.push_back(Node(number++, tiles[11], tiles[15], tiles[16]));
        nodes.push_back(Node(number++, tiles[11], tiles[12], tiles[16]));
        nodes.push_back(Node(number++, tiles[12], tiles[16]));
        nodes.push_back(Node(number++, tiles[12]));
        nodes.push_back(Node(number++, tiles[13]));
        nodes.push_back(Node(number++, tiles[13], tiles[17])); // 40
        nodes.push_back(Node(number++, tiles[13], tiles[14], tiles[17]));
        nodes.push_back(Node(number++, tiles[14], tiles[17], tiles[18]));
        nodes.push_back(Node(number++, tiles[14], tiles[15], tiles[18]));
        nodes.push_back(Node(number++, tiles[15], tiles[18], tiles[19]));
        nodes.push_back(Node(number++, tiles[15], tiles[16], tiles[19]));
        nodes.push_back(Node(number++, tiles[16], tiles[19]));
        nodes.push_back(Node(number++, tiles[16]));
        nodes.push_back(Node(number++, tiles[17]));
        nodes.push_back(Node(number++, tiles[17]));
        nodes.push_back(Node(number++, tiles[17], tiles[18])); // 50
        nodes.push_back(Node(number++, tiles[18]));
        nodes.push_back(Node(number++, tiles[18], tiles[19]));
        nodes.push_back(Node(number++, tiles[19]));
        nodes.push_back(Node(number++, tiles[19]));

        //conncte node to other node
        size_t id = 1;
        nodes[id++].setConnectNode(nodes[4], nodes[5]);
        nodes[id++].setConnectNode(nodes[5], nodes[6]);
        nodes[id++].setConnectNode(nodes[6], nodes[7]);
        nodes[id++].setConnectNode(nodes[1], nodes[8]);
        nodes[id++].setConnectNode(nodes[1], nodes[2], nodes[10]);
        nodes[id++].setConnectNode(nodes[2], nodes[3], nodes[12]);
        nodes[id++].setConnectNode(nodes[3], nodes[14]);
        nodes[id++].setConnectNode(nodes[4], nodes[9], nodes[15]);
        nodes[id++].setConnectNode(nodes[8], nodes[10], nodes[19]);
        nodes[id++].setConnectNode(nodes[5], nodes[9], nodes[11]); // 10
        nodes[id++].setConnectNode(nodes[10], nodes[12], nodes[21]);
        nodes[id++].setConnectNode(nodes[6], nodes[11], nodes[13]);
        nodes[id++].setConnectNode(nodes[12], nodes[14], nodes[23]);
        nodes[id++].setConnectNode(nodes[7], nodes[13], nodes[16]);
        nodes[id++].setConnectNode(nodes[8], nodes[17]);
        nodes[id++].setConnectNode(nodes[14], nodes[25]);
        nodes[id++].setConnectNode(nodes[15], nodes[18], nodes[26]);
        nodes[id++].setConnectNode(nodes[17], nodes[19], nodes[30]);
        nodes[id++].setConnectNode(nodes[9], nodes[18], nodes[20]);
        nodes[id++].setConnectNode(nodes[19], nodes[21], nodes[32]); // 20
        nodes[id++].setConnectNode(nodes[11], nodes[20], nodes[22]);
        nodes[id++].setConnectNode(nodes[21], nodes[23], nodes[34]);
        nodes[id++].setConnectNode(nodes[13], nodes[22], nodes[24]);
        nodes[id++].setConnectNode(nodes[23], nodes[25], nodes[36]);
        nodes[id++].setConnectNode(nodes[16], nodes[24], nodes[27]);
        nodes[id++].setConnectNode(nodes[17], nodes[28]);
        nodes[id++].setConnectNode(nodes[25], nodes[38]);
        nodes[id++].setConnectNode(nodes[26], nodes[29]);
        nodes[id++].setConnectNode(nodes[28], nodes[30], nodes[39]);
        nodes[id++].setConnectNode(nodes[18], nodes[29], nodes[31]); // 30
        nodes[id++].setConnectNode(nodes[30], nodes[32], nodes[41]);
        nodes[id++].setConnectNode(nodes[20], nodes[31], nodes[33]);
        nodes[id++].setConnectNode(nodes[32], nodes[34], nodes[43]);
        nodes[id++].setConnectNode(nodes[22], nodes[33], nodes[35]);
        nodes[id++].setConnectNode(nodes[34], nodes[36], nodes[45]);
        nodes[id++].setConnectNode(nodes[24], nodes[35], nodes[37]);
        nodes[id++].setConnectNode(nodes[36], nodes[38], nodes[47]);
        nodes[id++].setConnectNode(nodes[27], nodes[37]);
        nodes[id++].setConnectNode(nodes[29], nodes[40]);
        nodes[id++].setConnectNode(nodes[39], nodes[41], nodes[48]); // 40
        nodes[id++].setConnectNode(nodes[31], nodes[40], nodes[42]);
        nodes[id++].setConnectNode(nodes[41], nodes[43], nodes[50]);
        nodes[id++].setConnectNode(nodes[33], nodes[42], nodes[44]);
        nodes[id++].setConnectNode(nodes[43], nodes[45], nodes[52]);
        nodes[id++].setConnectNode(nodes[35], nodes[44], nodes[46]);
        nodes[id++].setConnectNode(nodes[45], nodes[47], nodes[54]);
        nodes[id++].setConnectNode(nodes[37], nodes[46]);
        nodes[id++].setConnectNode(nodes[40], nodes[49]);
        nodes[id++].setConnectNode(nodes[48], nodes[50]);
        nodes[id++].setConnectNode(nodes[42], nodes[49], nodes[51]); // 50
        nodes[id++].setConnectNode(nodes[50], nodes[52]);
        nodes[id++].setConnectNode(nodes[44], nodes[51], nodes[53]);
        nodes[id++].setConnectNode(nodes[52], nodes[54]);
        nodes[id++].setConnectNode(nodes[46], nodes[53]);
    }
    vector<Tile *> Board::findTile(vector<string> place, vector<int> number)
    {
        return vector<Tile *>();
    }
    Node *Board::findNode(vector<Tile *> t)
    {
        if (t.size() == 3)
            vector<int> firstNode = t[1]->getNode();
        vector<int> secendNode = t[2]->getNode();
        vector<int> thirdNode = t[3]->getNode();
        for (int i = 0; i < 6; i++)
        {
        }
        return nullptr;
    }
    std::shared_ptr<Board> Board::getInstance()
    {
        if (!instance)
        {
            instance = std::shared_ptr<Board>(new Board());
        }
        return instance;
    }
    Board::~Board() // need to delete the board and all the node and the tile
    {
        for (Tile *tile : tiles)
        {
            delete tile;
        }
        // for (Node node: nodes)
        // {
        //     delete node;
        // }
    }
    // bool Board::areAdjacent(int node1, int node2)
    // {
    //     for (const auto &adjNode : adjList[node1])
    //     {
    //         if (adjNode == node2)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    bool Board::placeSettlement(int node, const Player &player)
    {
        // Ensure the placement is valnumber
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

        settlements[node] = std::make_shared<Settelemnt>();
        return true;
    }
    bool Board::placeCity(int node, const Player &player)
    {
        std::shared_ptr<Piece> piece = getPieceAtNode(node);

        // Check if the piece at the node is a Settlement and belongs to the player
        // if (piece && piece->getType() == "settlement" && piece->getPlayer().getName() == player.getName())
        // {
        //     // Remove the settlement
        //     removePieceAtNode(node);

        //     // Place the city
        //     std::shared_ptr<Piece> city = std::make_shared<City>(player);
        //     placePieceAtNode(node, city);

        //     return true;
        // }

        // No settlement of the same player at the node
        return false;
    }
    bool Board::placeRoad(int node1, int node2, const Player &player)
    {
        // Ensure the placement is valnumber
        // if (!areAdjacent(node1, node2) || roads.find(node1) != roads.end() || roads.find(node2) != roads.end())
        // {
        //     return false; // Invalnumber road placement
        // }

        // roadAdjList[node1].push_back(node2);
        // roadAdjList[node2].push_back(node1);
        // roads[node1] = std::make_shared<Road>();
        // roads[node2] = std::make_shared<Road>();
        return true;
    }

    std::shared_ptr<Piece> Board::getPieceAtNode(int node)
    {
        return std::shared_ptr<Piece>();
    }

    // std::shared_ptr<Tile> getTile(int node)
    // {
    //     if (&tiles.find(node) != &tiles.end())
    //     {
    //         return &tiles[node];
    //     }
    //     return nullptr;
    // }

    void Board::removePieceAtNode(int node)
    {
    }

    void Board::placePieceAtNode(int node, std::shared_ptr<Piece> piece)
    {
    }

    // vonumber Board::printBoard() const
    // {
    //     for (const auto &tile : &tiles)
    //     {
    //         std::cout << tile.second.get().getType() << " (" << tile.getNumber() << ") ";
    //         if (tile->getResource()->getType() != "None")
    //         {
    //             std::cout << "- Resource: " << tile->getResource()->getType();
    //         }
    //         std::cout << std::endl;
    //     }
    // }
    // vonumber Board::moveRobber(int tileNumber)
    // {
    //     for (const auto &tile : &tiles)
    //     {
    //         if (tile->getNumber() == tileNumber)
    //         {
    //             robber.moveTo(tile.get());
    //             tile->placeRobber(true);
    //         }
    //         else
    //         {
    //             tile->placeRobber(false);
    //         }
    //     }
    // }
    // std::shared_ptr<Tile> Board::getTile(int tileNumber) const
    // {
    //     for (const auto &tile : &tiles)
    //     {
    //         if (tile->getNumber() == tileNumber)
    //         {
    //             return tile;
    //         }
    //     }
    //     return nullptr; // If tile not found
    // }
    // void Board::printBoard() const
    // {
    //     const int resourceSpace = 3; // Adjust spacing for resource type symbol

    //     // Top border for the board (optional)
    //     for (int x = 0; x < BOARD_SIZE * (resourceSpace + 1) + 1; ++x)
    //     {
    //         std::cout << "-";
    //     }
    //     std::cout << std::endl;

    //     for (int y = 0; y < BOARD_SIZE; ++y)
    //     {
    //         for (int x = 0; x < BOARD_SIZE; ++x)
    //         {
    //             // Check if the current position has a hexagon
    //             if (board[y][x].resourceType.empty())
    //             {
    //                 // Print empty spaces with proper alignment
    //                 for (int i = 0; i < resourceSpace; ++i)
    //                 {
    //                     std::cout << " ";
    //                 }
    //             }
    //             else
    //             {
    //                 // Print resource type symbol for the hexagon
    //                 std::cout << board[y][x].resourceType;
    //             }

    //             // Add spacing between resource types
    //             std::cout << " ";
    //         }

    //         // Print settlement information for the row (adjust logic for your layout)
    //         for (int x = 0; x < BOARD_SIZE; ++x)
    //         {
    //             if (y > 0 && getNode(x, y - 1).hasSettlement)
    //             {
    //                 std::cout << (getNode(x, y - 1).owner ? "[S" << *(getNode(x, y - 1).owner)->getName() << "]" : "[S ]");
    //             }
    //             else
    //             {
    //                 // Print empty spaces for settlements with proper alignment
    //                 for (int i = 0; i < resourceSpace + 2; ++i)
    //                 { // Adjust spacing as needed
    //                     std::cout << " ";
    //                 }
    //             }
    //         }
    //         std::cout << std::endl;
    //     }

    //     // Bottom border for the board (optional)
    //     for (int x = 0; x < BOARD_SIZE * (resourceSpace + 1) + 1; ++x)
    //     {
    //         std::cout << "-";
    //     }
    //     std::cout << std::endl;
    // }

}
