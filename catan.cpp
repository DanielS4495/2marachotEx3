#include "catan.hpp"
#include <limits>
namespace ariel
{
    Catan::Catan(const std::vector<Player *> &players) : board(std::shared_ptr<Board>()), players(players), ifBuild(false)
    {
        chooseStartingPlayer();
        giveResourceStart();
        start();//start two rounds
        playTurn(); // start the game
    }
    // std::shared_ptr<Board> Catan::getBoard()
    // {
    //     if (!board)
    //     {
    //         board = std::make_shared<Board>();
    //     }
    //     return board;
    // }
    // Catan::~Catan()
    // {
    //  delete board;
    // }
    Catan &Catan::getInstance(const std::vector<Player *> &players)
    {

        static Catan instance(players);
        return instance;
    }
    Player *Catan::getCurrentPlayer() const
    {
        return this->currentPlayer;
    }
    void Catan::start() // do two rounds of place settlement and roads
    {
        std::vector<std::string> places;
        std::vector<int> numberPlaces;
        std::string inputString;
        int inputNumber;
        int i = 0;
        while (i < 6)
        {
            if (i % 2 == 0)
                std::cout << currentPlayer->getName() << "'s turn.\n now you build two settelemnt and two road" << std::endl;
            std::cout << "Enter up to 3 places (press Enter to stop):" << std::endl;
            for (int i = 0; i < 3; ++i)
            {
                std::cout << "Enter place " << i + 1 << ": ";
                std::getline(std::cin, inputString);
                // Break the loop if no input is provided
                if (inputString.empty())
                {
                    break;
                }
                places.push_back(inputString);
            }
            std::cout << "Enter up to 3 numbers accordantly to the places (press negative number to stop):" << std::endl;
            for (int i = 0; i < 3; ++i)
            {
                std::cout << "Enter number " << i + 1 << ": ";
                // Check if the input operation was successful
                if (!(std::cin >> inputNumber))
                {
                    std::cin.clear();                                                   // Clear the error state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
                    std::cout << "Invalid input. Please enter a valid integer." << std::endl;
                    --i; // Decrement the counter to allow re-entering the input
                    continue;
                }
                // Break the loop if no input is provided
                if (inputNumber > -1)
                    numberPlaces.push_back(inputNumber);
                else
                    break;
            }
            currentPlayer->placeSettelemnt(places, numberPlaces, *board);
            currentPlayer->placeRoad(places, numberPlaces, *board);
            if (i % 2 == 1)
                nextPlayer();
            i++;
        }
    }
    // Game starting logic
    void Catan::playTurn()
    {
        // Player *currentPlayer = getCurrentPlayer();
        std::cout << currentPlayer->getName() << "'s turn." << std::endl;
        // int rollResult = rollDice();
        // std::cout << "Rolled: " << rollResult << std::endl;
        // if (rollResult == 7)
        // {
        //     for (Player *p : players)
        //     {
        //         while (p->countResources() > 7)
        //         {
        //             cout << p->getName() << ": what resource do you want to return?" << endl;
        //             cout << "choose from: WOOD/BRICK/SHEEP/WHEAT/IRON" << endl; // put resource type
        //             string res;
        //             cin>>res;
        //             int count=p->getResourceCount(res);
        //             cout << "enter how much: between 1 to " << count<< endl; // put how much resource have
        //             cin>>count;
        //             p->removeResource(count,res);
        //         }
        //     }
        // }
        // else
        // {
        //     board->giveResourceByDice(rollResult,0);
        // }

        // string s = "";
        // while (s != "end turn")
        // {
        //     if (this->currentPlayer->hasDevelopment())
        //     {

        //         cout << this->currentPlayer->getName() << ": what do you want to do this turn?" << endl;
        //         cout << "choose from: Use Development/ Roll Dice" << endl;
        //         cin >> s;
        //         if (s == "Use Development")
        //             while (s == "out")
        //             {
        //                 cout << "if you dont want type out else type one of the development to use:\n  KNIGHT / ROAD_BUILDER / MONOPOLY / YEAR_OF_PLENTY / VICTORY_POINT" << endl;
        //                 cin >> s;
        //                 this->currentPlayer->useDevelopment(s);
        //             }
        //         else
        //             this->currentPlayer->rollDice();
        //     }
        //     else
        //     {
        //         this->currentPlayer->rollDice();
        //     }
        //     cout << "choose from: Buy / Trade / end Turn" << endl;
        //     cin >> s;
        //     if (s == "Buy")
        //     {
        //         cout << "what do you want to buy choose from: Settelment / City / Road / Development" << endl;
        //         cin >> s;
        //         if (s == "S"){
        //             cout << "choose places" << endl;
        //         vector<string> places;
        //         cin >> places[0];
        //         cin >> places[1];
        //         cout << "choose number of places" << endl;
        //         vector<int> numplaces;
        //         cin >> numplaces[0];
        //         cin >> numplaces[1];
        //         currentPlayer->placeSettelemnt(places,numplaces);
        //         }

        //     }
        // }
        // nextPlayer();

        // string resource="";
        // for (const auto &player : players){ //go over all player
        //     bool robber(Tile::hasRobber()); //check if there is robber
        //     if(!robber){
        //     resource = Tile::getResource.(); //get name resource
        //      check if there is a piece right next to the resource
        //     player.addResource(resource); //give player serource
        //     }
        // }
        // bool exit = true;
        // string resource = "";
        // while (exit)
        // {
        //     string s;
        //     std::cout << "What you want to do: " << std::endl;
        //     std::cout << "1. if want to Buy S/C/R/D: type its latter" << std::endl;
        //     std::cout << "2. if want Use D: type ud" << std::endl;
        //     std::cout << "3. End Turn: type e" << std::endl;
        //     cin<<s<<endl;
        //     if(s=="S"){
        //     }
        //     if(s=="C"){
        //     }
        // }
        // Distribute resources based on the roll result
        // Implement trading and building logic
        setIfBuild(true); // when the player build he cant trade
        // Move to the next player
        // turnIndex = (turnIndex + 1) % players.size(); //do i need this?
        // nextPlayer(); // i need to do first end turn
    }
    void Catan::nextPlayer()
    {
        setIfBuild(false);
        currentPlayer->endTurn();
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        currentPlayer = players[currentPlayerIndex];
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
            if (maxAge < players[i]->getAge())
            {
                maxAge = players[i]->getAge();
                oldestPlayerIndex = i;
            }
        }

        std::cout << "Starting player is " << players[oldestPlayerIndex]->getName() << std::endl;
        currentPlayerIndex = oldestPlayerIndex; // Assign the index of the oldest player
        currentPlayer = players[currentPlayerIndex];
        currentPlayer->startTurn();
    }
    void Catan::setIfBuild(bool b)
    {
        ifBuild = b;
    }
    void Catan::printWinner()
    { // need to free all the space from everything
        for (Player *player : players)
        {
            if (player->getVictoryPoints() >= 10)
            {
                std::cout << player->getName() << " wins the game!" << std::endl;
                return;
            }
        }
        std::cout << "None of the players reached 10 points yet." << std::endl;
    }
    void Catan::giveResourceStart()
    {
        if (!ifstart)
        {
            for (Player *p : players)
            {
                p->addResource(4, "WOOD");  // two roads two sett..
                p->addResource(2, "SHEEP"); // two sett..
                p->addResource(2, "WHEAT"); // two sett..
                p->addResource(4, "BRICK"); // two roads two sett..
            }
            ifstart = true;
        }
    }
}