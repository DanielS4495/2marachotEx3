
#include <stdexcept>

#include "board.hpp"
#include "player.hpp"
#include "tile.cpp"
namespace ariel
{ // need to reduce one to all the tiles and nodes
    // std::shared_ptr<Board> Board::instance = nullptr;
    std::vector<std::shared_ptr<Tile>> tiles;

    Board::Board()
    { // create tiles and give them numbers of nodes that are connected to them
        // because we create them after the tile
        // give us the oppsition to find the node using tiles
        //  std::vector<std::shared_ptr<Tile>> tiles;
        tiles.push_back(std::make_shared<MountainsTile>(10, std::vector<int>{0, 3, 4, 7, 8, 9}));
        tiles.push_back(std::make_shared<PastureTile>(2, std::vector<int>{1, 4, 5, 9, 10, 11}));
        tiles.push_back(std::make_shared<ForestTile>(9, std::vector<int>{2, 5, 6, 11, 12, 13}));
        tiles.push_back(std::make_shared<AgriculturalTile>(12, std::vector<int>{7, 8, 14, 16, 17, 18}));
        tiles.push_back(std::make_shared<HillsTile>(6, std::vector<int>{8, 9, 10, 18, 19, 20}));
        tiles.push_back(std::make_shared<PastureTile>(4, std::vector<int>{10, 11, 12, 20, 21, 22}));
        tiles.push_back(std::make_shared<HillsTile>(10, std::vector<int>{12, 13, 15, 22, 23, 24}));
        tiles.push_back(std::make_shared<AgriculturalTile>(9, std::vector<int>{16, 17, 25, 27, 28, 29}));
        tiles.push_back(std::make_shared<ForestTile>(11, std::vector<int>{17, 18, 19, 29, 30, 31}));
        tiles.push_back(std::make_shared<DesertTile>(0, std::vector<int>{19, 20, 21, 31, 32, 33}));
        tiles.push_back(std::make_shared<ForestTile>(3, std::vector<int>{21, 22, 23, 33, 34, 35}));
        tiles.push_back(std::make_shared<MountainsTile>(8, std::vector<int>{23, 24, 26, 35, 36, 37}));
        tiles.push_back(std::make_shared<ForestTile>(8, std::vector<int>{28, 29, 30, 38, 39, 40}));
        tiles.push_back(std::make_shared<MountainsTile>(3, std::vector<int>{30, 31, 32, 40, 41, 42}));
        tiles.push_back(std::make_shared<AgriculturalTile>(4, std::vector<int>{32, 33, 34, 42, 43, 44}));
        tiles.push_back(std::make_shared<PastureTile>(5, std::vector<int>{34, 35, 36, 44, 45, 46}));
        tiles.push_back(std::make_shared<HillsTile>(5, std::vector<int>{39, 40, 41, 47, 48, 49}));
        tiles.push_back(std::make_shared<AgriculturalTile>(6, std::vector<int>{41, 42, 43, 49, 50, 51}));
        tiles.push_back(std::make_shared<PastureTile>(11, std::vector<int>{43, 44, 45, 51, 52, 53}));

        // create Node and connect them to tiles
        int number = 0;
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[0]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[1]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[2]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[0]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[0], tiles[1]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[1], tiles[2]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[2]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[0], tiles[3]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[0], tiles[3], tiles[4]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[0], tiles[1], tiles[4]})); // 10
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[1], tiles[4], tiles[5]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[1], tiles[2], tiles[5]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[2], tiles[5], tiles[6]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[2], tiles[6]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[3]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[6]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[3], tiles[7]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[3], tiles[7], tiles[8]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[3], tiles[4], tiles[8]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[4], tiles[8], tiles[9]})); // 20
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[4], tiles[5], tiles[9]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[5], tiles[9], tiles[10]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[5], tiles[6], tiles[10]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[6], tiles[10], tiles[11]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[6], tiles[11]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[7]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[11]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[7]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[7], tiles[12]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[7], tiles[8], tiles[12]})); // 30
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[8], tiles[12], tiles[13]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[8], tiles[9], tiles[13]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[9], tiles[13], tiles[14]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[9], tiles[10], tiles[14]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[10], tiles[14], tiles[15]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[10], tiles[11], tiles[15]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[11], tiles[15]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[11]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[12]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[12], tiles[16]})); // 40
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[12], tiles[13], tiles[16]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[13], tiles[16], tiles[17]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[13], tiles[14], tiles[17]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[14], tiles[17], tiles[18]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[14], tiles[15], tiles[18]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[15], tiles[18]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[15]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[16]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[16]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[16], tiles[17]})); // 50
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[17]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[17], tiles[18]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[18]}));
        nodes.push_back(Node(number++, vector<shared_ptr<Tile>>{tiles[18]}));

        // conncte node to other node
        size_t id = 0;
        nodes[id++].setConnectNode(vector<Node>{nodes[3], nodes[4]});
        nodes[id++].setConnectNode(vector<Node>{nodes[4], nodes[5]});
        nodes[id++].setConnectNode(vector<Node>{nodes[5], nodes[6]});
        nodes[id++].setConnectNode(vector<Node>{nodes[0], nodes[7]});
        nodes[id++].setConnectNode(vector<Node>{nodes[0], nodes[1], nodes[9]});
        nodes[id++].setConnectNode(vector<Node>{nodes[1], nodes[2], nodes[11]});
        nodes[id++].setConnectNode(vector<Node>{nodes[2], nodes[13]});
        nodes[id++].setConnectNode(vector<Node>{nodes[3], nodes[8], nodes[14]});
        nodes[id++].setConnectNode(vector<Node>{nodes[7], nodes[9], nodes[18]});
        nodes[id++].setConnectNode(vector<Node>{nodes[4], nodes[8], nodes[10]}); // 10
        nodes[id++].setConnectNode(vector<Node>{nodes[9], nodes[11], nodes[20]});
        nodes[id++].setConnectNode(vector<Node>{nodes[5], nodes[10], nodes[12]});
        nodes[id++].setConnectNode(vector<Node>{nodes[11], nodes[13], nodes[22]});
        nodes[id++].setConnectNode(vector<Node>{nodes[6], nodes[12], nodes[15]});
        nodes[id++].setConnectNode(vector<Node>{nodes[7], nodes[16]});
        nodes[id++].setConnectNode(vector<Node>{nodes[13], nodes[24]});
        nodes[id++].setConnectNode(vector<Node>{nodes[14], nodes[17], nodes[25]});
        nodes[id++].setConnectNode(vector<Node>{nodes[16], nodes[18], nodes[29]});
        nodes[id++].setConnectNode(vector<Node>{nodes[8], nodes[17], nodes[19]});
        nodes[id++].setConnectNode(vector<Node>{nodes[18], nodes[20], nodes[31]}); // 20
        nodes[id++].setConnectNode(vector<Node>{nodes[10], nodes[19], nodes[21]});
        nodes[id++].setConnectNode(vector<Node>{nodes[20], nodes[22], nodes[33]});
        nodes[id++].setConnectNode(vector<Node>{nodes[12], nodes[21], nodes[23]});
        nodes[id++].setConnectNode(vector<Node>{nodes[22], nodes[24], nodes[35]});
        nodes[id++].setConnectNode(vector<Node>{nodes[15], nodes[23], nodes[26]});
        nodes[id++].setConnectNode(vector<Node>{nodes[16], nodes[27]});
        nodes[id++].setConnectNode(vector<Node>{nodes[24], nodes[37]});
        nodes[id++].setConnectNode(vector<Node>{nodes[25], nodes[28]});
        nodes[id++].setConnectNode(vector<Node>{nodes[27], nodes[29], nodes[38]});
        nodes[id++].setConnectNode(vector<Node>{nodes[17], nodes[28], nodes[30]}); // 30
        nodes[id++].setConnectNode(vector<Node>{nodes[29], nodes[31], nodes[40]});
        nodes[id++].setConnectNode(vector<Node>{nodes[19], nodes[30], nodes[32]});
        nodes[id++].setConnectNode(vector<Node>{nodes[31], nodes[33], nodes[42]});
        nodes[id++].setConnectNode(vector<Node>{nodes[21], nodes[32], nodes[34]});
        nodes[id++].setConnectNode(vector<Node>{nodes[33], nodes[35], nodes[44]});
        nodes[id++].setConnectNode(vector<Node>{nodes[23], nodes[34], nodes[36]});
        nodes[id++].setConnectNode(vector<Node>{nodes[35], nodes[37], nodes[46]});
        nodes[id++].setConnectNode(vector<Node>{nodes[26], nodes[36]});
        nodes[id++].setConnectNode(vector<Node>{nodes[28], nodes[39]});
        nodes[id++].setConnectNode(vector<Node>{nodes[38], nodes[40], nodes[47]}); // 40
        nodes[id++].setConnectNode(vector<Node>{nodes[30], nodes[39], nodes[41]});
        nodes[id++].setConnectNode(vector<Node>{nodes[40], nodes[42], nodes[49]});
        nodes[id++].setConnectNode(vector<Node>{nodes[32], nodes[41], nodes[43]});
        nodes[id++].setConnectNode(vector<Node>{nodes[42], nodes[44], nodes[51]});
        nodes[id++].setConnectNode(vector<Node>{nodes[34], nodes[43], nodes[45]});
        nodes[id++].setConnectNode(vector<Node>{nodes[44], nodes[46], nodes[53]});
        nodes[id++].setConnectNode(vector<Node>{nodes[36], nodes[45]});
        nodes[id++].setConnectNode(vector<Node>{nodes[39], nodes[48]});
        nodes[id++].setConnectNode(vector<Node>{nodes[47], nodes[49]});
        nodes[id++].setConnectNode(vector<Node>{nodes[41], nodes[48], nodes[50]}); // 50
        nodes[id++].setConnectNode(vector<Node>{nodes[49], nodes[51]});
        nodes[id++].setConnectNode(vector<Node>{nodes[43], nodes[50], nodes[52]});
        nodes[id++].setConnectNode(vector<Node>{nodes[51], nodes[53]});
        nodes[id++].setConnectNode(vector<Node>{nodes[45], nodes[52]});
    }
    Board::~Board() // need to delete the board and all the tile
    {
        // for (Tile *tile : tiles)
        // {
        //     delete tile;
        // }
        // tiles.clear();
    }
    // std::shared_ptr<Board> Board::getInstance()
    // {
    //     if (!instance)
    //     {
    //         instance = std::shared_ptr<Board>(new Board());
    //     }
    //     return instance;
    // }
    std::vector<std::shared_ptr<Tile>> Board::findTiles(const std::vector<std::string> &places, const std::vector<int> &placesNum)
    {
        std::vector<std::shared_ptr<Tile>> matchingTiles; // Stores found tiles
        try
        {
            // Check if place and number vectors have the same size
            if (places.size() != placesNum.size())
            {
                throw std::invalid_argument("Place and number vectors must have the same size");
            }

            for (size_t i = 0; i < places.size(); ++i)
            {

                for (std::shared_ptr<Tile> tile : tiles)
                {
                    // Check if place and number match
                    if ((tile->getType() == places[i]) && (tile->getNumber() == placesNum[i]))
                    {

                        matchingTiles.push_back(tile); // Add matching tile pointer to the vector
                        break;                         // Exit inner loop once a match is found
                    }
                }
            }
        }
        catch (const std::exception &e)
        {
            cout << e.what() << endl;
        }
        return matchingTiles;
    }
    int Board::hasRobber() const
    {
        return this->robberPresent;
    }
    void Board::setRobber(int hasRobber)
    {
        this->robberPresent = hasRobber;
    }
    // int Board::findNode(std::vector<std::shared_ptr<Tile>> t)
    // {
    //     // if he has only one then there is two node that can be found!
    //     // so it will choose the one with no placement at all if there is both then he will take the second one
    //     if (t.size() == 1)
    //     {
    //         int x = -1;
    //         vector<int> tile = t[(size_t)0]->getNode();
    //         for (int i : tile)
    //         {
    //             if (vector<Node>{nodes[(size_t)i].getTile().size() == 1)
    //             {
    //                 if (!nodes[(size_t)i].getHasCity() || !nodes[(size_t)i].getHasSettlement())
    //                     return i;
    //                 else
    //                     x = i;
    //             }
    //         }
    //         if (x != -1)
    //             return x;
    //     }
    //     vector<int> firstNode = t[(size_t)0]->getNode();
    //     vector<int> secendNode = t[(size_t)1]->getNode();
    //     if (t.size() == 3)
    //     {
    //         vector<int> thirdNode = t[(size_t)2]->getNode();
    //         for (int i : firstNode) // iterate throw the node of the first tile
    //         {
    //             for (int j = 1; j <= firstNode.size(); j++)
    //             {
    //                 if (i == secendNode[(size_t)j]) // check if first and secend node are the same
    //                     for (int k : thirdNode)     // iterate throw the node of the third tile
    //                     {
    //                         if (i == k)
    //                             return i;
    //                     }
    //                 if (i == thirdNode[(size_t)j]) // check if first and third node are the same
    //                     for (int k : secendNode)   // iterate throw the node of the secend tile
    //                     {
    //                         if (i == k)
    //                             return i;
    //                     }
    //             }
    //         }
    //     }
    //     for (int i : firstNode)
    //     {
    //         for (int j : secendNode)
    //         {
    //             if (i == j)
    //                 if (vector<Node>{nodes[(size_t)i].getTile().size() == 2) // check if has two tile connected and not three
    //                     return i;
    //         }
    //     }
    //     return -1;
    // }
    int Board::findNode(std::vector<std::shared_ptr<Tile>> t)
    {
        if (t.empty())
        {
            // Handle empty vector
            return -1;
        }
        if (t.size() == 1)
        {
            int x = -1;
            vector<int> tile = t[0]->getNode();
            for (int i : tile)
            {
                if (nodes[(size_t)i].getTile().size() == 1)
                {
                    if (!nodes[(size_t)i].getHasCity() && !nodes[(size_t)i].getHasSettlement())
                        return i;
                    else
                        x = i;
                }
            }
            if (x != -1)
                return x;
        }
        if (t.size() == 2)
        {
            const vector<int> &t1 = t[0]->getNode();
            for (const int &i : t1)
            {
                std::vector<std::shared_ptr<ariel::Tile>> t2 = this->nodes[(size_t)i].getTile();
                if (t2.size() == 2)
                {
                    if (t2[1]->getType() == t[1]->getType() || t2[0]->getType() == t[1]->getType())
                    {
                        return i;
                    }
                }
            }
        }
        if (t.size() == 3)
        {
            vector<int> t1 = t[(size_t)0]->getNode();
            for (int i : t1)
            {
                std::vector<std::shared_ptr<ariel::Tile>> t2 = nodes[(size_t)i].getTile();
                if (t2.size() == 3)
                {
                    if (t2[1]->getType() == t[1]->getType() || t2[0]->getType() == t[1]->getType() || t2[2]->getType() == t[1]->getType())
                    {
                        if (t2[1]->getType() == t[2]->getType() || t2[0]->getType() == t[2]->getType() || t2[2]->getType() == t[2]->getType())
                        {
                            return i;
                        }
                    }
                }
            }
        }
        return -1;
    }
    int Board::findOtherNodeOfRoad(int node, int numberOfTurn, Player &player)
    { // go over all the road check if one of them connect to the connectNode of the node
        if (node == -1)
            return -1;
        if (numberOfTurn > 1)
        {
            for (Road r : roads)
            {
                if (r.getOwner() == &player)
                {
                    vector<Node> vecNode = nodes.at((size_t)node).getConnectNode(); // the nodes that connect to the node
                    for (Node n : vecNode)
                    {
                        if (r.getNode1()->getNumber() == n.getNumber()) // found the node that i can connect using road
                            return n.getNumber();

                        if (r.getNode2()->getNumber() == n.getNumber()) // found the node that i can connect using road
                            return n.getNumber();
                    }
                }
            }
        }
        else
        {
            vector<Node> vecNode = nodes.at((size_t)node).getConnectNode();
            int randomNode = rand() % 3; // random of the connected node
            return vecNode.at((size_t)randomNode).getNumber();
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
    PlacementError Board::ValidateSettlement(int node, const Player &player, int countTurn) const
    {
        // check for invalid node
        if (node < 0 || node > 53)
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
        if (countTurn > 2)
        { // if the his first and secend time doesnt need connecting to road
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
        }
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
        if (node < 0 || node > 53)
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
        if (node1 < 0 || node1 > 53||node2 < 0 || node2 > 53)
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
    bool Board::placeSettlement(int node, Player &player, int countTurn)
    {
        // Validate placement and handle potential errors (implement based on game rules)
        PlacementError error = ValidateSettlement(node, player, countTurn);
        if (error != PlacementError::SUCCESS)
        {
            std::cerr << "Error placing settlement: code " << static_cast<int>(error) << std::endl;
            return false;
        }
        // Valid placement
        nodes[(size_t)node].setHasSettlement(true, player);
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
        nodes[(size_t)node].setHasCity(true, player);
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
    void Board::giveResourceByDice(int dice, int moverobber)
    {
        std::cout << "Rolled: " << dice << std::endl;
        if (dice != 7)
            for (std::shared_ptr<Tile> t : tiles)
            {
                if (t->getNumber() == dice)
                    if (t->getNumber() != robberPresent)
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
            }
        else
        {
            // need to take half of the card from players that have more than 7 card
            if (moverobber > 0 && moverobber < 20)
                setRobber(moverobber);
        }
    }
    void Board::printBoard() const
    {
        int count = 0;
        for (std::shared_ptr<Tile> tile : tiles)
        {
            count++;

            std::cout << tile->getType() << " (" << tile->getNumber() << ") ";
            // if (tile->getType() != "Desert")
            //     std::cout << " " << tile->getResource()->getType() << " ";
            if (count == 3 || count == 7 || count == 12 || count == 16 || count == 19)
                std::cout << std::endl;
        }
    }
    // void Board::printBoard() const
    // {
    //     const int resourceSpace = 3; // Adjust spacing for resource type symbol
    //     int BOARD_SIZE=5;
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