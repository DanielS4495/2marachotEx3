//danielsamson10@gmail.com
#include "catan.hpp"
namespace ariel
{
    Catan::Catan(const std::vector<Player *> &players) : board(std::shared_ptr<Board>()), players(players), ifBuild(false)
    {
        chooseStartingPlayer();
        giveResourceStart();
        start();    // start two rounds
        playTurn(); // start the game
    }
    Board &Catan::getBoard()
    {
        if (!board)
        {
            board = std::make_shared<Board>();
        }
        return *board;
    }
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
        int i = 0;
        while (i < 6)
        {
            if (i % 2 == 0)
                std::cout << currentPlayer->getName() << "'s turn, Now you build first settelemnt and road" << std::endl;
            else
                std::cout << currentPlayer->getName() << "'s turn, Now you build secend settelemnt and road" << std::endl;

            if (!buildFromUser("Settelemnt,Road"))
                i--; // if didnt secceeded try again

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
        string input1 = "", input2 = "";
        int dice = 0;
        if (this->currentPlayer->hasDevelopment())
        {

            // cout << this->currentPlayer->getName() << ": what do you want to do this turn?" << endl;
            cout << "choose from: Use Development/ Roll Dice" << endl;
            cin >> input1;
            if (input1 == "Use Development")
            {
                while (true)
                {
                    this->currentPlayer->printDevelopment();
                    cin >> input2;
                    int c = this->currentPlayer->getDevelopmentCardCount(input2);
                    if (c > 0)
                    {
                        this->currentPlayer->useDevelopment(input2);
                        this->UseDevelopmentOfCurrentPlayer(input2);
                        break;
                    }
                    else
                        cout << "dont have enough of this card choose different one" << endl;
                }
            }
            else
            {
                dice = this->currentPlayer->rollDice(*board);
                if (dice == 7)
                    gotSevenInDice();
            }
        }
        else
        {
            dice = this->currentPlayer->rollDice(*board);
            if (dice == 7)
                gotSevenInDice();
        }
        while (true)
        {
            cout << "choose from: Use_Development / Buy / Trade / Print_Player_Resource /Print_Board / Print_Player_Points / End_Turn" << endl;
            cin >> input1;
            if (input1 == "Use_Development")
            {
                while (true)
                {
                    this->currentPlayer->printDevelopment();
                    cin >> input2;
                    int c = this->currentPlayer->getDevelopmentCardCount(input2);
                    if (c > 0)
                    {
                        this->currentPlayer->useDevelopment(input2);
                        this->UseDevelopmentOfCurrentPlayer(input2);
                        break;
                    }
                    else
                        cout << "dont have enough of this card choose different one" << endl;
                }
            }
            else if (input1 == "Buy")
            {
                cout << "what do you want to buy?\nchoose from: Settelment / City / Road / Development / End_Turn" << endl;
                cin >> input2;
                if (input2 == "Settelment" || input2 == "City" || input2 == "Road")
                {
                    buildFromUser(input2);
                }
                else if (input2 == "Development")
                {
                    currentPlayer->buyDevelopmentCard();
                }
            }
            else if (input1 == "Trade")
            {

                if (!this->ifBuild)
                {
                    bool find = false;
                    while (!find)
                    {
                        cout << "Enter the name you want to trade with, else type end" << endl;
                        cin >> input2;
                        if (input2 == "end")
                            break;
                        Player *other;
                        for (Player *p : players)
                        { 
                            if (p->getName() == input2)
                            {
                                find = true;
                                other = p;
                            }
                        }
                        if (find)
                        {
                            string give, get;
                            int giveNum, getNum;
                            cout << "Enter the string of the give resource" << endl;
                            cin >> give;
                            cout << "Enter how much of the give resource: need more than 0" << endl;
                            cin >> giveNum;
                            cout << "Enter the string of the get resource" << endl;
                            cin >> get;
                            cout << "Enter how much of the get resource: need more than 0" << endl;
                            cin >> getNum;
                            currentPlayer->trade(*other, give, get, giveNum, getNum);
                        }
                        else
                            cout << "did not find the player you are looking try again" << endl;
                    }
                }
                else
                    cout << "player has already build so he cant trade" << endl;
            }
            else if (input1 == "Print_Player_Resource")
                this->currentPlayer->printStatsOfPlayer();
            else if (input1 == "Print_Board")
                this->board->printBoard();
            else if (input1 == "Print_Player_Points")
                cout << this->currentPlayer->getVictoryPoints() << endl;
            else if (input1 == "End Turn")
                break;
        }
        nextPlayer();
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
        size_t oldestPlayerIndex = 0; 

        for (size_t i = 0; i < players.size(); ++i)
        {
            if (maxAge < players[i]->getAge())
            {
                maxAge = players[i]->getAge();
                oldestPlayerIndex = i;
            }
        }

        std::cout << "Starting player is " << players[oldestPlayerIndex]->getName() << std::endl;
        currentPlayerIndex = oldestPlayerIndex; 
        currentPlayer = players[currentPlayerIndex];
        currentPlayer->startTurn();
    }
    bool Catan::buildFromUser(string WhatBuild)
    {
        std::vector<std::string> places;
        std::vector<int> numberPlaces;
        std::string inputString;
        std::cout << "Enter up to 3 places (press Enter to stop):" << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "Enter place " << i + 1 << ": ";
            std::getline(std::cin, inputString);
            // Break the loop if no input is provided
            if (!inputString.empty())
            {
                places.push_back(inputString);
            }
            else
                break;
        }
        std::cout << "Enter up to 3 numbers accordantly to the places (press negative number or enter to stop):" << std::endl;
        int i = 0;
        int inputNumber1 = -1, inputNumber2 = -1, inputNumber3 = -1;
        while (i < places.size())
        {
            std::cout << "Enter number " << i + 1 << ": ";
            if (inputNumber1 == -1)
            {
                cin >> inputNumber1;
                i++;
            }
            else if (inputNumber2 == -1)
            {
                cin >> inputNumber2;
                i++;
            }
            else if (inputNumber3 == -1)
            {
                cin >> inputNumber3;
                i++;
            }
        }
        if (inputNumber2 == -1)
        {
            numberPlaces.push_back(inputNumber1);
        }
        else if (inputNumber3 == -1)
        {
            numberPlaces.push_back(inputNumber1);
            numberPlaces.push_back(inputNumber2);
        }
        else
        {
            numberPlaces.push_back(inputNumber1);
            numberPlaces.push_back(inputNumber2);
            numberPlaces.push_back(inputNumber3);
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << places.size() << numberPlaces.size() << endl;
        if (WhatBuild == "Settelemnt")
            if (currentPlayer->placeSettelemnt(places, numberPlaces, getBoard()))
                return 1;
            else
                return 0;
        else if (WhatBuild == "City")
            if (currentPlayer->placeCity(places, numberPlaces, getBoard()))
                return 1;
            else
                return 0;
        else if (WhatBuild == "Road")
            if (currentPlayer->placeRoad(places, numberPlaces, getBoard()))
                return 1;
            else
                return 0;
        else if (WhatBuild == "Settelemnt,Road")
        {
            if (currentPlayer->placeSettelemnt(places, numberPlaces, getBoard()))
                return 1;
            else
                return 0;
            if (currentPlayer->placeRoad(places, numberPlaces, getBoard()))
                return 1;
            else
                return 0;
        }
        setIfBuild(true);
    }
    void Catan::gotSevenInDice() 
    {
        for (Player *p : players)
        {
            while (p->countResources() > 7)
            {
                cout << p->getName() << ": what resource do you want to return you have more than 7 resources?" << endl;
                cout << "choose from: WOOD / BRICK / SHEEP / WHEAT / IRON" << endl; 
                string res;
                cin >> res;
                int count = p->getResourceCount(res);
                cout << "You got " << count << "from this resource, put number to reduce" << endl;
                cin >> count;
                p->removeResource(count, res);
            }
        }
        cout << "All player has less than 8 cards at hand" << endl;
    }
    void Catan::UseDevelopmentOfCurrentPlayer(const string &removeDevelopment)
    {
        // move robber
        if (removeDevelopment == "KNIGHT")
        {
            while (true)
            {
                cout << "Enter number between 1 to 18 to put the knight in tile" << endl;
                int x;
                cin >> x;
                if (x > 0 && x < 19)
                {
                    board->setRobber(x);
                    break;
                }
                else
                    cout << "wrong, choose again" << endl;
            }
        }
        // build two road
        else if (removeDevelopment == "ROAD_BUILDER")
        {
            this->currentPlayer->addResource(2, "WOOD");
            this->currentPlayer->addResource(2, "BRICK");
            buildFromUser("Road");
            buildFromUser("Road");
        }
        // take one resource and get from every player all they have from that resource
        else if (removeDevelopment == "MONOPOLY")
        {

            cout << "Enter one resource to get from every player" << endl;
            string s;
            cin >> s;
            for (Player *p : players)
            {
                if (this->currentPlayer != p)
                {
                    int countget = p->getResourceCount(s);
                    if (countget > 0)
                        this->currentPlayer->trade(*p, s, s, 1, countget);
                }
            }
        }
        // get two resources
        else if (removeDevelopment == "YEAR_OF_PLENTY")
        {
            cout << "Enter first resource" << endl;
            string s1;
            cin >> s1;
            this->currentPlayer->addResource(1, s1);

            cout << "Enter secend resource" << endl;
            string s2;
            cin >> s2;
            this->currentPlayer->addResource(1, s2);
        }
        // get one victory point
        else if (removeDevelopment == "VICTORY_POINT")
            this->currentPlayer->addVictoryPoints();
    }
    void Catan::setIfBuild(bool b)
    {
        ifBuild = b;
    }
    void Catan::printWinner()
    { 
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