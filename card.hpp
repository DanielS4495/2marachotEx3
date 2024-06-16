//danielsamson10@gmail.com
#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include <stdexcept>

namespace ariel
{
    // Enumeration for different card types
    enum CardType
    {
        KNIGHT,
        ROAD_BUILDER,
        MONOPOLY,
        YEAR_OF_PLENTY,
        VICTORY_POINT
    };

    // Function to convert a string representation of a card to CardType
    CardType getCardTypeFromString(const std::string &card);

    class Card
    {
    public:
        virtual ~Card() = default;               // Destructor (usually empty for abstract classes)
        virtual std::string getType() const = 0; // Pure virtual function to get card type
        virtual int getHowMuchLeft() const = 0;  // Pure virtual function to get remaining uses
        virtual void reduceCard() = 0;           // Pure virtual function to reduce remaining uses
    };

    class KnightCard : public Card
    {
    private:
        static int countcard; // Static member to track remaining cards

    public:
        std::string getType() const override { return "Knight"; }
        int getHowMuchLeft() const override { return countcard; }
        void reduceCard() override
        {
            if (countcard > 0)
                --countcard;
        }
    };

    class RoadBuilderCard : public Card
    {
    private:
        static int countcard;

    public:
        std::string getType() const override { return "Road Builder"; }
        int getHowMuchLeft() const override { return countcard; }
        void reduceCard() override
        {
            if (countcard > 0)
                --countcard;
        }
    };

    class MonopolyCard : public Card
    {
    private:
        static int countcard;

    public:
        std::string getType() const override { return "Monopoly"; }
        int getHowMuchLeft() const override { return countcard; }
        void reduceCard() override
        {
            if (countcard > 0)
                --countcard;
        }
    };

    class YearOfPlentyCard : public Card
    {
    private:
        static int countcard;

    public:
        std::string getType() const override { return "Year of Plenty"; }
        int getHowMuchLeft() const override { return countcard; }
        void reduceCard() override
        {
            if (countcard > 0)
                --countcard;
        }
    };

    class VictoryPointCard : public Card
    {
    private:
        static int countcard;

    public:
        std::string getType() const override { return "Victory Point"; }
        int getHowMuchLeft() const override { return countcard; }
        void reduceCard() override
        {
            if (countcard > 0)
                --countcard;
        }
    };

    // Function to create a card object based on the CardType
    std::shared_ptr<Card> createCard(CardType type);
}
