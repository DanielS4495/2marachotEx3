#pragma once
#include <stdexcept>
#include <string>
#include <memory>
// namespace ariel {

// }
#include "player.hpp"

namespace ariel
{
    class Player;
    enum CardType
    {
        KNIGHT,
        ROAD_BUILDER,
        MONOPOLY,
        YEAR_OF_PLENTY,
        VICTORY_POINT
    };

    CardType getCardTypeFromString(const std::string &card)
    {
        static std::unordered_map<std::string, CardType> cardMap = {
            {"Knight", KNIGHT},
            {"Road Builder", ROAD_BUILDER},
            {"Monopoly", MONOPOLY},
            {"Year Of Plenty", YEAR_OF_PLENTY},
            {"VictoryPoint", VICTORY_POINT}};

        auto it = cardMap.find(card);
        if (it != cardMap.end())
        {
            return it->second;
        }
        else
        {
            throw std::invalid_argument("Invalid card type");
        }
    }
    class Card
    {

    public:
        virtual ~Card() = default;
        virtual std::string getType() const = 0;
        virtual const Player &getPlayer() const = 0;
        virtual void play() = 0;
        std::unordered_map<std::string, ResourceType> Resource::stringToResource = {
            {"WOOD", WOOD},
            {"BRICK", BRICK},
            {"SHEEP", SHEEP},
            {"WHEAT", WHEAT},
            {"ORE", ORE}}
    };

    class KnightCard : public Card
    {
    private:
        Player *player;

    public:
        KnightCard(const Player &player) : player(player) {}
        virtual const Player &getPlayer() const override
        {
            return player;
        }
        std::string getType() const override { return "Knight"; }
        void play() override
        {
        }
    };

    class RoadBuilderCard : public Card
    {
    private:
        Player player;

    public:
        RoadBuilderCard(const Player &player) : player(player) {}
        virtual const Player &getPlayer() const override
        {
            return player;
        }
        std::string getType() const override { return "Road Builder"; }
        void play() override // need 2 index to put the road
        {
        }
    };
    class MonopolyCard : public Card
    {
    private:
        Player player;

    public:
        MonopolyCard(const Player &player) : player(player) {}
        virtual const Player &getPlayer() const override
        {
            return player;
        }
        std::string getType() const override { return "Monopoly"; }
        void play() override // need resource to get from everyone
        {
        }
    };
    class YearOfPlentyCard : public Card
    {
    private:
        Player player;

    public:
        YearOfPlentyCard(const Player &player) : player(player) {}
        virtual const Player &getPlayer() const override
        {
            return player;
        }
        std::string getType() const override { return "Year Of Plenty"; }
        // void play(Player p, const std::string &getResource1, const std::string &getResource2) override // need two resource to get from the bank :)
        // {
        //     p.addResource(getResource1);
        //     p.addResource(getResource2);
        // }
        void play() override // need resource to get from everyone
        {
        }
    };
    class VictoryPointCard : public Card
    {
    private:
        Player player;

    public:
        VictoryPointCard(const Player &player) : player(player) {}
        virtual const Player &getPlayer() const override
        {
            return player;
        }
        std::string getType() const override { return "VictoryPoint"; }
        // void play(Player p) override // get one victory point
        // {
        //     p.addvictorypoints();
        // }
        void play() override // need resource to get from everyone
        {
        }
    };
    std::shared_ptr<ariel::Card> createCard(CardType type, const Player &player)
    {
        switch (type)
        {
        case KNIGHT:
            return std::static_pointer_cast<ariel::KnightCard>(std::make_shared<ariel::KnightCard>(player));
        case ROAD_BUILDER:
            return std::static_pointer_cast<ariel::RoadBuilderCard>(std::make_shared<ariel::RoadBuilderCard>(player));
        case MONOPOLY:
            return std::static_pointer_cast<ariel::MonopolyCard>(std::make_shared<ariel::MonopolyCard>(player));
        case YEAR_OF_PLENTY:
            return std::static_pointer_cast<ariel::YearOfPlentyCard>(std::make_shared<ariel::YearOfPlentyCard>(player));
        case VICTORY_POINT:
            return std::static_pointer_cast<ariel::VictoryPointCard>(std::make_shared<ariel::VictoryPointCard>(player));
        default:
            throw std::invalid_argument("Invalid card type");
        }
    }
}
