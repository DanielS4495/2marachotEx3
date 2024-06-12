
#include <stdexcept>

#include "board.hpp"
#include "player.hpp"
#include "tile.cpp"
namespace ariel
{
    std::shared_ptr<Board> Board::instance = nullptr;
    Board::Board()
    { // create tiles and give them numbers of nodes that are connected to them
        // because we create them after the tile
        // give us the oppsition to find the node using tiles
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

        // create node and connect them to tiles
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

        // conncte node to other node
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
    vector<Tile *> Board::findTiles(vector<string> place, vector<int> number)
    {
        vector<Tile *> matchingTiles; // Stores found tiles
        size_t i = 1, j = 1;
        // Iterate through all tiles in the board
        while (i < place.size() || j < number.size())
        {
            for (Tile *tile : tiles)
            {
                // Check if place and number match (assuming tile has attributes for place and number)
                if (i < place.size() || j < number.size())
                    if (tile->getType() == place[j] && tile->getNumber() == number[i])
                    {
                        matchingTiles.push_back(tile); // Add matching tile pointer to the vector
                        j++;
                        i++;
                        break;
                    }
                    else
                        break; // so it wont iterate everything again for nothing
            }
        }
        return matchingTiles;
    }
    int Board::hasRobber() const
    {
        return this->robberPresent;
    }

    void Board::setRobber(int hasRobber)
    {
        robberPresent = hasRobber;
    }
    int Board::findNode(vector<Tile *> t)
    { // if he has only one then there is two node that can be found!
        // so it will choose the one with no placement at all if there is both then he will take the second one
        if (t.size() == 1)
        {
            int x = -1;
            vector<int> tile = t[1]->getNode();
            for (int i : tile)
            {
                if (nodes[(size_t)i].getTile().size() == 1)
                    if (!nodes[(size_t)i].getHasCity() || !nodes[(size_t)i].getHasSettlement())
                        return i;
                    else
                        x = i;
            }
            if (x != -1)
                return x;
        }
        vector<int> firstNode = t[1]->getNode();
        vector<int> secendNode = t[2]->getNode();
        if (t.size() == 3)
        {
            vector<int> thirdNode = t[3]->getNode();
            for (int i : firstNode) // iterate throw the node of the first tile
            {
                for (int j = 1; j <= firstNode.size(); j++)
                {
                    if (i == secendNode[(size_t)j]) // check if first and secend node are the same
                        for (int k : thirdNode)     // iterate throw the node of the third tile
                        {
                            if (i == k)
                                return i;
                        }
                    if (i == thirdNode[(size_t)j]) // check if first and third node are the same
                        for (int k : secendNode)   // iterate throw the node of the secend tile
                        {
                            if (i == k)
                                return i;
                        }
                }
            }
        }
        for (int i : firstNode)
        {
            for (int j : secendNode)
            {
                if (i == j)
                    if (nodes[(size_t)i].getTile().size() == 2) // check if has two tile connected and not three
                        return i;
            }
        }
        return -1;
    }

    int Board::findRoad(int n1, int n2) const
    {
        bool b = false;
        for (int i; i < roads.size(); i++)
        {
            Road r = roads[(size_t)i];
            int r1 = r.getNode1()->getNumber();
            int r2 = r.getNode1()->getNumber();
            if ((r1 == n1 || r1 == n2) && (r1 == n1 || r1 == n2))
            {
                b = true;
                return i;
            }
        }
        return -1;
    }

    PlacementError Board::ValidateSettlement(int node, const Player &player) const
    {
        // check for invalid node
        if (node > 0 && node < 55)
        {
            return PlacementError::INVALID_NODE;
        }
        // check for occupied
        if (nodes[(size_t)node].getHasSettlement() || nodes[(size_t)node].getHasCity())
        {
            return PlacementError::NODE_OCCUPIED;
        }
        // check for Adjacent Settlement
        vector<Node> n1 = nodes[(size_t)node].getConnectNode();
        for (Node node : n1)
        {
            if (node.getHasSettlement())
                return PlacementError::ADJACENT_SETTLEMENT;
        }
        // Check for road connection
        bool b = false;
        vector<Node> n2 = nodes[(size_t)node].getConnectNode();
        for (Node n : n2)
        {
            int s = findRoad(n.getNumber(), node);
            if (s != -1)
                if (*roads[(size_t)s].getOwner() == player)
                    b = true;
        }
        if (!b)
            return PlacementError::DONT_HAVE_ROAD_CONNECTED;
        //  Check player settlement limit
        if (player.getNumberOfSettlement() >= player.getSettlementLimit())
        {
            return PlacementError::PLAYER_SETTLEMENT_LIMIT;
        }
        // can be implement settlement
        return PlacementError::SUCCESS;
    }
    PlacementError Board::ValidateCity(int node, const Player &player) const
    {
        // check for invalid node
        if (node > 0 && node < 55)
        {
            return PlacementError::INVALID_NODE;
        }
        // check for occupied
        if (nodes[(size_t)node].getHasCity())
        {
            return PlacementError::NODE_OCCUPIED;
        }
        // check for not occupied by settlement
        if (!nodes[(size_t)node].getHasSettlement())
        {
            return PlacementError::NODE_OCCUPIED_NOT_BY_SETTLEMENT;
        }
        //  Check player city limit
        if (player.getCityLimit() <= player.getNumberOfCity())
        {
            return PlacementError::PLAYER_SETTLEMENT_LIMIT;
        }
        // can be implement city
        return PlacementError::SUCCESS;
    }

    PlacementError Board::ValidateRoad(int node1, int node2, const Player &player) const
    {
        // check for invalid node
        if (node1 > 0 && node1 < 55 && node2 > 0 && node2 < 55)
        {
            return PlacementError::INVALID_NODE;
        }
        if (node1 == node2)
            return PlacementError::INVALID_NODE;
        //  Check player road limit
        if (player.getRoadsLimit() <= player.getNumberOfRoads())
        {
            return PlacementError::PLAYER_ROAD_LIMIT;
        }
        // check for occupied by road
        if (findRoad(node1, node2) != -1)
            return PlacementError::ROAD_OCCUPIED;
        // can be implement road
        return PlacementError::SUCCESS;
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
    }
    bool Board::placeSettlement(int node, Player &player)
    {
        // Validate placement and handle potential errors (implement based on game rules)
        PlacementError error = ValidateSettlement(node, player);
        if (error != PlacementError::SUCCESS)
        {
            std::cerr << "Error placing settlement: code " << static_cast<int>(error) << std::endl;
            return false;
        }
        // catch (const std::exception &e)
        // {
        //     cout << e.what() << endl;
        // }
        // Valid placement
        nodes[(size_t)node].setHasSettlement(true);
        nodes[(size_t)node].setOwner(player);
        return true;
    }

    bool Board::placeCity(int node, Player &player)
    {
        PlacementError error = ValidateCity(node, player);
        if (error != PlacementError::SUCCESS)
        {
            std::cerr << "Error placing city: code " << static_cast<int>(error) << std::endl;
            return false;
        }
        nodes[(size_t)node].setHasSettlement(false);
        nodes[(size_t)node].setHasCity(true);
        return true;
    }

    bool Board::placeRoad(int node1, int node2, Player &player)
    {
        PlacementError error = ValidateRoad(node1, node2, player);
        if (error != PlacementError::SUCCESS)
        {
            std::cerr << "Error placing road: code " << static_cast<int>(error) << std::endl;
            return false;
        }

        // check if there is road connect of the same player by checking
        Road r = Road(nodes[(size_t)node1], nodes[(size_t)node2], player);
        roads.push_back(r);
        return true;
    }
    // void Board::moveRobber(int tileNumber)
    // {
    //     if (this->robberPresent == -1)
    //         setRobber(tileNumber);
    //     else
    //     {
    //         // tiles[(size_t)numberRobberTile]->setRobber(false);
    //         // tiles[(size_t)tileNumber]->setRobber(false);
    //     }
    // }
    void Board::giveResourceByDice(int dice)
    {
        // for(Node n:nodes){

        // }
        for (Tile *t : tiles)
        {
            if (t->getNumber() == dice)
                if (t->getNumber()!=robberPresent)
                {
                    vector<int> c = t->getNode();
                    for (int i : c)
                    {
                        if (nodes[(size_t)i].getHasSettlement())
                            nodes[(size_t)i].getOwner()->addResource(1, t->getResource());
                        if (nodes[(size_t)i].getHasCity())
                            nodes[(size_t)i].getOwner()->addResource(1, t->getResource());
                    }
                }
        }`
        
    }
    // std::shared_ptr<Piece> Board::getPieceAtNode(int node)
    // {
    //     return std::shared_ptr<Piece>();
    // }
    // void Board::removePieceAtNode(int node)
    // {
    // }

    // void Board::placePieceAtNode(int node, std::shared_ptr<Piece> piece)
    // {
    // }

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
