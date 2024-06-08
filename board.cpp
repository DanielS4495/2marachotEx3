
#include <stdexcept>

#include "board.hpp"
#include "player.hpp"
#include "tile.cpp"
namespace ariel
{
    std::shared_ptr<Board> Board::instance = nullptr;
    Board::Board()
    {
        // // Initialize the board with different tiles and numbers
        // tiles.push_back(std::make_shared<ForestTile>(5));
        // tiles.push_back(std::make_shared<HillsTile>(6)); //גבעות
        // tiles.push_back(std::make_shared<PastureTile>(8));//מרעה
        // tiles.push_back(std::make_shared<FieldsTile>(9));//שדות
        // tiles.push_back(std::make_shared<Mountains>(10));
        // tiles.push_back(std::make_shared<DesertTile>());

        // tiles[1] = std::make_shared<Tile>(MountainsTile::MountainsTile(10), 10);
        // tiles[2] = std::make_shared<Tile>(PastureTile, 2);
        // tiles[3] = std::make_shared<Tile>(ForestTile, 9);
        // tiles[4] = std::make_shared<Tile>(FieldsTile, 12);
        // tiles[5] = std::make_shared<Tile>(HillsTile, 6);
        // tiles[6] = std::make_shared<Tile>(PastureTile, 4);
        // tiles[7] = std::make_shared<Tile>(HillsTile, 10);
        // tiles[8] = std::make_shared<Tile>(FieldsTile, 9);
        // tiles[9] = std::make_shared<Tile>(ForestTile, 11);
        // tiles[10] = std::make_shared<Tile>(DESERTE, 0); // Desert has no number
        // tiles[11] = std::make_shared<Tile>(ForestTile, 3);
        // tiles[12] = std::make_shared<Tile>(Mountains, 8);
        // tiles[13] = std::make_shared<Tile>(ForestTile, 8);
        // tiles[14] = std::make_shared<Tile>(Mountains, 3);
        // tiles[15] = std::make_shared<Tile>(FieldsTile, 4);
        // tiles[16] = std::make_shared<Tile>(PastureTile, 5);
        // tiles[17] = std::make_shared<Tile>(HillsTile, 5);
        // tiles[18] = std::make_shared<Tile>(FieldsTile, 6);
        // tiles[19] = std::make_shared<Tile>(PastureTile, 11);
        // adjList = {
        //     {1, {2, 4, 5}},
        //     {2, {1, 3, 5, 6}},
        //     {3, {2, 6, 7}},
        //     {4, {1, 5, 8, 9}},
        //     {5, {1, 2, 4, 6, 9, 10}},
        //     {6, {2, 3, 5, 7, 10, 11}},
        //     {7, {3, 6, 11, 12}},
        //     {8, {4, 9, 13}},
        //     {9, {4, 5, 8, 10, 13, 14}},
        //     {10, {5, 6, 9, 11, 14, 15}},
        //     {11, {6, 7, 10, 12, 15, 16}},
        //     {12, {7, 11, 16}},
        //     {13, {8, 9, 14, 17}},
        //     {14, {9, 10, 13, 15, 17, 18}},
        //     {15, {10, 11, 14, 16, 18, 19}},
        //     {16, {11, 12, 15, 19}},
        //     {17, {13, 14, 18}},
        //     {18, {14, 15, 17, 19}},
        //     {19, {15, 16, 18}}};
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


        int id = 1;
        nodes.push_back(new Node(id++, {tiles[1]}));
        nodes.push_back(new Node(id++, {tiles[2]}));
        nodes.push_back(new Node(id++, {tiles[3]}));
        nodes.push_back(new Node(id++, {tiles[1]}));
        nodes.push_back(new Node(id++, {tiles[1], tiles[2]}));
        nodes.push_back(new Node(id++, {tiles[2], tiles[3]}));
        nodes.push_back(new Node(id++, {tiles[3]}));
        nodes.push_back(new Node(id++, {tiles[1], tiles[4]}));
        nodes.push_back(new Node(id++, {tiles[1], tiles[4], tiles[5]}));
        nodes.push_back(new Node(id++, {tiles[1], tiles[2], tiles[5]})); //10
        nodes.push_back(new Node(id++, {tiles[2], tiles[5], tiles[6]}));
        nodes.push_back(new Node(id++, {tiles[2], tiles[3], tiles[6]}));
        nodes.push_back(new Node(id++, {tiles[3], tiles[6], tiles[7]}));
        nodes.push_back(new Node(id++, {tiles[3], tiles[7]}));
        nodes.push_back(new Node(id++, {tiles[4]}));
        nodes.push_back(new Node(id++, {tiles[7]}));
        nodes.push_back(new Node(id++, {tiles[4], tiles[8]}));
        nodes.push_back(new Node(id++, {tiles[4], tiles[8], tiles[9]}));
        nodes.push_back(new Node(id++, {tiles[4], tiles[5], tiles[9]}));
        nodes.push_back(new Node(id++, {tiles[5], tiles[9], tiles[10]})); //20
        nodes.push_back(new Node(id++, {tiles[5], tiles[6], tiles[10]}));
        nodes.push_back(new Node(id++, {tiles[6], tiles[10], tiles[11]}));
        nodes.push_back(new Node(id++, {tiles[6], tiles[7], tiles[11]}));
        nodes.push_back(new Node(id++, {tiles[7], tiles[11], tiles[12]}));
        nodes.push_back(new Node(id++, {tiles[7], tiles[12]}));
        nodes.push_back(new Node(id++, {tiles[8]}));
        nodes.push_back(new Node(id++, {tiles[12]}));
        nodes.push_back(new Node(id++, {tiles[8]}));
        nodes.push_back(new Node(id++, {tiles[8], tiles[13]}));
        nodes.push_back(new Node(id++, {tiles[8], tiles[9],tiles[13]})); //30
        nodes.push_back(new Node(id++, {tiles[9],tiles[13], tiles[14]}));
        nodes.push_back(new Node(id++, {tiles[9],tiles[10], tiles[14]}));
        nodes.push_back(new Node(id++, {tiles[10], tiles[14], tiles[15]}));
        nodes.push_back(new Node(id++, {tiles[10], tiles[11], tiles[15]}));
        nodes.push_back(new Node(id++, {tiles[11], tiles[15], tiles[16]}));
        nodes.push_back(new Node(id++, {tiles[11], tiles[12], tiles[16]}));
        nodes.push_back(new Node(id++, {tiles[12], tiles[16]}));
        nodes.push_back(new Node(id++, {tiles[12]}));
        nodes.push_back(new Node(id++, {tiles[13]}));
        nodes.push_back(new Node(id++, {tiles[13], tiles[17]})); //40
        nodes.push_back(new Node(id++, {tiles[13], tiles[14], tiles[17]}));
        nodes.push_back(new Node(id++, {tiles[14], tiles[17], tiles[18]}));
        nodes.push_back(new Node(id++, {tiles[14], tiles[15], tiles[18]}));
        nodes.push_back(new Node(id++, {tiles[15], tiles[18], tiles[19]}));
        nodes.push_back(new Node(id++, {tiles[15], tiles[16], tiles[19]}));
        nodes.push_back(new Node(id++, {tiles[16], tiles[19]}));
        nodes.push_back(new Node(id++, {tiles[16]}));
        nodes.push_back(new Node(id++, {tiles[17]}));
        nodes.push_back(new Node(id++, {tiles[17]}));
        nodes.push_back(new Node(id++, {tiles[17], tiles[18]})); //50
        nodes.push_back(new Node(id++, {tiles[18]}));
        nodes.push_back(new Node(id++, {tiles[18], tiles[19]}));
        nodes.push_back(new Node(id++, {tiles[19]}));
        nodes.push_back(new Node(id++, {tiles[19]}));





        id=1;
        nodes[id++]->setConnectNode({nodes[4],nodes[5]});
        nodes[id++]->setConnectNode({nodes[5],nodes[6]});
        nodes[id++]->setConnectNode({nodes[6],nodes[7]});
        nodes[id++]->setConnectNode({nodes[1],nodes[8]});
        nodes[id++]->setConnectNode({nodes[1],nodes[2],nodes[10]});
        nodes[id++]->setConnectNode({nodes[2],nodes[3],nodes[12]});
        nodes[id++]->setConnectNode({nodes[3],nodes[14]});
        nodes[id++]->setConnectNode({nodes[4],nodes[9],nodes[15]});
        nodes[id++]->setConnectNode({nodes[8],nodes[10],nodes[19]});
        nodes[id++]->setConnectNode({nodes[5],nodes[9],nodes[11]}); //10
        nodes[id++]->setConnectNode({nodes[10],nodes[12],nodes[21]});
        nodes[id++]->setConnectNode({nodes[6],nodes[11],nodes[13]});
        nodes[id++]->setConnectNode({nodes[12],nodes[14],nodes[23]});
        nodes[id++]->setConnectNode({nodes[7],nodes[13],nodes[16]});
        nodes[id++]->setConnectNode({nodes[8],nodes[17]});
        nodes[id++]->setConnectNode({nodes[14],nodes[25]});
        nodes[id++]->setConnectNode({nodes[15],nodes[18],nodes[26]});
        nodes[id++]->setConnectNode({nodes[17],nodes[19],nodes[30]});
        nodes[id++]->setConnectNode({nodes[9],nodes[18],nodes[20]});
        nodes[id++]->setConnectNode({nodes[19],nodes[21],nodes[32]}); //20
        nodes[id++]->setConnectNode({nodes[11],nodes[20],nodes[22]});
        nodes[id++]->setConnectNode({nodes[21],nodes[23],nodes[34]});
        nodes[id++]->setConnectNode({nodes[13],nodes[22],nodes[24]});
        nodes[id++]->setConnectNode({nodes[23],nodes[25],nodes[36]});
        nodes[id++]->setConnectNode({nodes[16],nodes[24],nodes[27]});
        nodes[id++]->setConnectNode({nodes[17],nodes[28]});
        nodes[id++]->setConnectNode({nodes[25],nodes[38]});
        nodes[id++]->setConnectNode({nodes[26],nodes[29]});
        nodes[id++]->setConnectNode({nodes[28],nodes[30],nodes[39]});
        nodes[id++]->setConnectNode({nodes[18],nodes[29],nodes[31]}); //30
        nodes[id++]->setConnectNode({nodes[30],nodes[32],nodes[41]});
        nodes[id++]->setConnectNode({nodes[20],nodes[31],nodes[33]});
        nodes[id++]->setConnectNode({nodes[32],nodes[34],nodes[43]});
        nodes[id++]->setConnectNode({nodes[22],nodes[33],nodes[35]});
        nodes[id++]->setConnectNode({nodes[34],nodes[36],nodes[45]});
        nodes[id++]->setConnectNode({nodes[24],nodes[35],nodes[37]});
        nodes[id++]->setConnectNode({nodes[36],nodes[38],nodes[47]});
        nodes[id++]->setConnectNode({nodes[27],nodes[37]});
        nodes[id++]->setConnectNode({nodes[29],nodes[40]});
        nodes[id++]->setConnectNode({nodes[39],nodes[41],nodes[48]}); //40
        nodes[id++]->setConnectNode({nodes[31],nodes[40],nodes[42]});
        nodes[id++]->setConnectNode({nodes[41],nodes[43],nodes[50]});
        nodes[id++]->setConnectNode({nodes[33],nodes[42],nodes[44]});
        nodes[id++]->setConnectNode({nodes[43],nodes[45],nodes[52]});
        nodes[id++]->setConnectNode({nodes[35],nodes[44],nodes[46]});
        nodes[id++]->setConnectNode({nodes[45],nodes[47],nodes[54]});
        nodes[id++]->setConnectNode({nodes[37],nodes[46]});
        nodes[id++]->setConnectNode({nodes[40],nodes[49]}); 
        nodes[id++]->setConnectNode({nodes[48],nodes[50]});
        nodes[id++]->setConnectNode({nodes[42],nodes[49],nodes[51]}); //50
        nodes[id++]->setConnectNode({nodes[50],nodes[52]});
        nodes[id++]->setConnectNode({nodes[44],nodes[51],nodes[53]});
        nodes[id++]->setConnectNode({nodes[52],nodes[54]});
        nodes[id++]->setConnectNode({nodes[46],nodes[53]});
        
        
       
    }
    std::shared_ptr<Board> Board::getInstance()
    {
        if (!instance)
        {
            instance = std::shared_ptr<Board>(new Board());
        }
        return instance;
    }
    Board::~Board()
    {
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
        // Ensure the placement is valid
        if (!areAdjacent(node1, node2) || roads.find(node1) != roads.end() || roads.find(node2) != roads.end())
        {
            return false; // Invalid road placement
        }

        roadAdjList[node1].push_back(node2);
        roadAdjList[node2].push_back(node1);
        roads[node1] = std::make_shared<Road>();
        roads[node2] = std::make_shared<Road>();
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

    // void Board::printBoard() const
    // {
    //     for (const auto &tile : tiles)
    //     {
    //         std::cout << tile.second.get().getType() << " (" << tile.getNumber() << ") ";
    //         if (tile->getResource()->getType() != "None")
    //         {
    //             std::cout << "- Resource: " << tile->getResource()->getType();
    //         }
    //         std::cout << std::endl;
    //     }
    // }
    // void Board::moveRobber(int tileNumber)
    // {
    //     for (const auto &tile : tiles)
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
    //     for (const auto &tile : tiles)
    //     {
    //         if (tile->getNumber() == tileNumber)
    //         {
    //             return tile;
    //         }
    //     }
    //     return nullptr; // If tile not found
    // }
    void Board::printBoard() const
    {
        const int resourceSpace = 3; // Adjust spacing for resource type symbol

        // Top border for the board (optional)
        for (int x = 0; x < BOARD_SIZE * (resourceSpace + 1) + 1; ++x)
        {
            std::cout << "-";
        }
        std::cout << std::endl;

        for (int y = 0; y < BOARD_SIZE; ++y)
        {
            for (int x = 0; x < BOARD_SIZE; ++x)
            {
                // Check if the current position has a hexagon
                if (board[y][x].resourceType.empty())
                {
                    // Print empty spaces with proper alignment
                    for (int i = 0; i < resourceSpace; ++i)
                    {
                        std::cout << " ";
                    }
                }
                else
                {
                    // Print resource type symbol for the hexagon
                    std::cout << board[y][x].resourceType;
                }

                // Add spacing between resource types
                std::cout << " ";
            }

            // Print settlement information for the row (adjust logic for your layout)
            for (int x = 0; x < BOARD_SIZE; ++x)
            {
                if (y > 0 && getNode(x, y - 1).hasSettlement)
                {
                    std::cout << (getNode(x, y - 1).owner ? "[S" << *(getNode(x, y - 1).owner)->getName() << "]" : "[S ]");
                }
                else
                {
                    // Print empty spaces for settlements with proper alignment
                    for (int i = 0; i < resourceSpace + 2; ++i)
                    { // Adjust spacing as needed
                        std::cout << " ";
                    }
                }
            }
            std::cout << std::endl;
        }

        // Bottom border for the board (optional)
        for (int x = 0; x < BOARD_SIZE * (resourceSpace + 1) + 1; ++x)
        {
            std::cout << "-";
        }
        std::cout << std::endl;
    }

}
