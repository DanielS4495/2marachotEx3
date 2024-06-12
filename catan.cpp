#include "catan.hpp"
namespace ariel
{
    // Board &board;
    // Catan::Catan(const std::vector<Player> &players)
    //     : players(players), currentPlayerIndex(0), ifBuild(false), board(*(Board::getInstance()))
    // {
    //     chooseStartingPlayer(); // Assuming this is a member function
    // }
    // Catan::Catan(const std::vector<Player> &players)
    //     : players(players), currentPlayerIndex(0), ifBuild(false) {
    //     board = Board::getInstance();
    //     chooseStartingPlayer();
    // }
    //
    // // Board &Catan::getBoard()
    // // {
    // //     return board;
    // // }
    //
    // std::shared_ptr<Board> Catan::getBoard() const {
    //     return board;
    // }
    Catan::Catan(const std::vector<Player> &players) : players(players), ifBuild(false), board(std::make_shared<Board>())
    {
        chooseStartingPlayer();
        giveResourceStart();
    }
    Board &Catan::getBoard()
    {
        if (!board)
        {
            board = std::make_shared<Board>();
        }
        return *board;
    }
    Catan &Catan::getInstance(const std::vector<Player> &players)
    {
        // // static Catan instance(players);
        // // board = Board::getInstance();
        // static Catan instance;
        // instance.players = players;
        // instance.currentPlayerIndex = 0;
        // // instance.chooseStartingPlayer();
        // instance.getBoard();
        // return instance;
        // board =*(Board::getInstance());
        static Catan instance(players);
        return instance;
    }
    Player *Catan::getCurrentPlayer() const
    {
        return this->currentPlayer;
    }
    void Catan::start() // do two rounds of place settlement and roads
    {
        giveResourceStart();
        
        // Game starting logic
    }

    // void Catan::playTurn()
    // {
    //     // Player *currentPlayer = getCurrentPlayer();
    //     std::cout << currentPlayer->getName() << "'s turn." << std::endl;
    //     int rollResult = rollDice();
    //     std::cout << "Rolled: " << rollResult << std::endl;
    //     if (rollResult == 7)
    //     {
    //         for (Player p : players)
    //         {
    //             while (p.countResources() > 7)
    //             {
    //                 cout << p.getName() << ": what resource do you want to return?" << endl;
    //                 cout << "choose from: WOOD/BRICK/SHEEP/WHEAT/IRON" << endl; // put resource type
    //                 string res;
    //                 cin<<res<<endl;
    //                 int count=p.getResourceCount(res);
    //                 cout << "enter how much: between 1 to " << count<< endl; // put how much resource have
    //                 cin<<count<<endl;
    //                 p.removeResource(count,res);
    //             }
    //         }
    //     }
    //     else
    //     {
    //         board.get()->giveResourceByDice(rollResult);
    //     }
    //     // string resource="";
    //     // for (const auto &player : players){ //go over all player
    //     //     bool robber(Tile::hasRobber()); //check if there is robber
    //     //     if(!robber){
    //     //     resource = Tile::getResource.(); //get name resource
    //     //      check if there is a piece right next to the resource
    //     //     player.addResource(resource); //give player serource
    //     //     }
    //     // }
    //     // bool exit = true;
    //     // string resource = "";
    //     // while (exit)
    //     // {
    //     //     string s;
    //     //     std::cout << "What you want to do: " << std::endl;
    //     //     std::cout << "1. if want to Buy S/C/R/D: type its latter" << std::endl;
    //     //     std::cout << "2. if want Use D: type ud" << std::endl;
    //     //     std::cout << "3. End Turn: type e" << std::endl;
    //     //     cin<<s<<endl;
    //     //     if(s=="S"){
    //     //     }
    //     //     if(s=="C"){
    //     //     }
    //     // }
    //     // Distribute resources based on the roll result
    //     // Implement trading and building logic
    //     setIfBuild(true); // when the player build he cant trade
    //     // Move to the next player
    //     // turnIndex = (turnIndex + 1) % players.size(); //do i need this?
    //     nextPlayer(); // i need to do first end turn
    // }
    void Catan::nextPlayer()
    {
        setIfBuild(false);
        currentPlayer->endTurn();
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        currentPlayer = &players[currentPlayerIndex];
        currentPlayer->startTurn();
    }
    bool Catan::checkVictory()
    {
        return currentPlayer->getVictoryPoints() >= 10;
    }
    bool Catan::checkBuild()
    {
        return ifBuild;
    }
    void Catan::chooseStartingPlayer()
    {
        // Find oldest player
        int maxAge = 0;
        size_t oldestPlayerIndex = 0; // Initialize index to avoid potential issues

        for (size_t i = 0; i < players.size(); ++i)
        {
            if (maxAge < players[i].getAge())
            {
                maxAge = players[i].getAge();
                oldestPlayerIndex = i;
            }
        }

        std::cout << "Starting player is " << players[oldestPlayerIndex].getName() << std::endl;
        currentPlayerIndex = oldestPlayerIndex; // Assign the index of the oldest player
        currentPlayer = &players[currentPlayerIndex];
        currentPlayer->startTurn();
    }
    void Catan::setIfBuild(bool b)
    {
        ifBuild = b;
    }
    void Catan::printWinner()
    { // need to free all the space from everything
        for (Player player : players)
        {
            if (player.getVictoryPoints() >= 10)
            {
                std::cout << player.getName() << " wins the game!" << std::endl;
                return;
            }
        }
        std::cout << "None of the players reached 10 points yet." << std::endl;
    }
    void Catan::giveResourceStart()
    {
        // ResourceType resourceType;
        // resourceType = getResourceTypeFromString("WOOD");
        // std::shared_ptr<Resource> res1 = createResource(resourceType);
        // resourceType = getResourceTypeFromString("SHEEP");
        // std::shared_ptr<Resource> res2 = createResource(resourceType);
        // resourceType = getResourceTypeFromString("WHEAT");
        // std::shared_ptr<Resource> res3 = createResource(resourceType);
        // resourceType = getResourceTypeFromString("IRON");
        // std::shared_ptr<Resource> res4 = createResource(resourceType);
        if (ifstart)
        {
            for (Player p : players)
            {
                p.addResource(4, "WOOD");  // two roads two sett..
                p.addResource(2, "SHEEP"); // two sett..
                p.addResource(2, "WHEAT"); // two sett..
                p.addResource(4, "BRICK"); // two roads two sett..
            }
            ifstart = false;
        }
    }
}