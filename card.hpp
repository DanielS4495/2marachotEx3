// #pragma once
// #include <stdexcept>
// #include <string>
// #include <memory>
// #include <iostream>
// #include <stdexcept>
// #include <unordered_map>
// using namespace std;
// namespace ariel
// {
//     class Card
//     {

//     public:
//         virtual ~Card() = default;
//         virtual std::string getType() const = 0;
//         virtual int getHowMuchLeft() const = 0;
//         virtual void reduceCard() const = 0;
//     };

//     class KnightCard : public Card
//     {
//     private:
//         static int countcard = 0;
//     public:
//         std::string getType() const override { return "Knight"; }
//     };

//     class RoadBuilderCard : public Card
//     {
//     public:
//         std::string getType() const override { return "Road Builder"; }
//     };
//     class MonopolyCard : public Card
//     {
//     public:
//         std::string getType() const override { return "Monopoly"; }
//     };
//     class YearOfPlentyCard : public Card
//     {
//     public:
//         std::string getType() const override { return "Year Of Plenty"; }
//     };
//     class VictoryPointCard : public Card
//     {
//     public:
//         std::string getType() const override { return "VictoryPoint"; }
//     };

//     enum CardType
//     {
//         KNIGHT,
//         ROAD_BUILDER,
//         MONOPOLY,
//         YEAR_OF_PLENTY,
//         VICTORY_POINT
//     };

//     CardType getCardTypeFromString(const std::string &card)
//     {
//         static std::unordered_map<std::string, CardType> cardMap = {
//             {"Knight", KNIGHT},
//             {"Road Builder", ROAD_BUILDER},
//             {"Monopoly", MONOPOLY},
//             {"Year Of Plenty", YEAR_OF_PLENTY},
//             {"VictoryPoint", VICTORY_POINT}};

//         auto it = cardMap.find(card);
//         if (it != cardMap.end())
//         {
//             return it->second;
//         }
//         else
//         {
//             throw std::invalid_argument("Invalid card type");
//         }
//     }
//     std::unordered_map<std::string, CardType> stringToDevelopment = {
//         {"Knight", KNIGHT},
//         {"Road Builder", ROAD_BUILDER},
//         {"Monopoly", MONOPOLY},
//         {"Year Of Plenty", YEAR_OF_PLENTY},
//         {"VictoryPoint", VICTORY_POINT}};
//     std::shared_ptr<ariel::Card> createCard(CardType type)
//     {
//         switch (type)
//         {
//         case KNIGHT:
//             return std::static_pointer_cast<ariel::KnightCard>(std::make_shared<ariel::KnightCard>());
//         case ROAD_BUILDER:
//             return std::static_pointer_cast<ariel::RoadBuilderCard>(std::make_shared<ariel::RoadBuilderCard>());
//         case MONOPOLY:
//             return std::static_pointer_cast<ariel::MonopolyCard>(std::make_shared<ariel::MonopolyCard>());
//         case YEAR_OF_PLENTY:
//             return std::static_pointer_cast<ariel::YearOfPlentyCard>(std::make_shared<ariel::YearOfPlentyCard>());
//         case VICTORY_POINT:
//             return std::static_pointer_cast<ariel::VictoryPointCard>(std::make_shared<ariel::VictoryPointCard>());
//         default:
//             throw std::invalid_argument("Invalid card type");
//         }
//     };
// }
// #pragma once
// #include <string>
// #include <memory>
// #include <unordered_map>
// #include <stdexcept>

// namespace ariel
// {
//     enum CardType
//     {
//         KNIGHT,
//         ROAD_BUILDER,
//         MONOPOLY,
//         YEAR_OF_PLENTY,
//         VICTORY_POINT
//     };

//     CardType getCardTypeFromString(const std::string &card)
//     {
//         static std::unordered_map<std::string, CardType> cardMap = {
//             {"Knight", KNIGHT},
//             {"Road Builder", ROAD_BUILDER},
//             {"Monopoly", MONOPOLY},
//             {"Year Of Plenty", YEAR_OF_PLENTY},
//             {"Victory Point", VICTORY_POINT}};

//         auto it = cardMap.find(card);
//         if (it != cardMap.end())
//         {
//             return it->second;
//         }
//         else
//         {
//             throw std::invalid_argument("Invalid card type");
//         }
//     };

//     class Card
//     {
//     protected:
//         int countcard; // Number of times the card can be used
//     public:
//         Card(int count) : countcard(count) {}
//         virtual ~Card() = default;
//         virtual std::string getType() const = 0;
//         virtual int getHowMuchLeft() const { return countcard; }
//         virtual void reduceCard()
//         {
//             if (countcard > 0)
//                 --countcard;
//         }
//     };

//     class KnightCard : public Card
//     {
//     public:
//         KnightCard() : Card(3) {} // Initial count, for example, 3 times
//         std::string getType() const override { return "Knight"; }
//     };

//     class RoadBuilderCard : public Card
//     {
//     public:
//         RoadBuilderCard() : Card(2) {} // Initial count, for example, 2 times
//         std::string getType() const override { return "Road Builder"; }
//     };

//     class MonopolyCard : public Card
//     {
//     public:
//         MonopolyCard() : Card(1) {} // Initial count, for example, 1 time
//         std::string getType() const override { return "Monopoly"; }
//     };

//     class YearOfPlentyCard : public Card
//     {
//     public:
//         YearOfPlentyCard() : Card(2) {} // Initial count, for example, 2 times
//         std::string getType() const override { return "Year Of Plenty"; }
//     };

//     class VictoryPointCard : public Card
//     {
//     public:
//         VictoryPointCard() : Card(1) {} // Initial count, for example, 1 time
//         std::string getType() const override { return "Victory Point"; }
//     };
//     static std::shared_ptr<Card> createCard(CardType type)
//     {
//         switch (type)
//         {
//         case KNIGHT:
//             return std::make_shared<KnightCard>();
//         case ROAD_BUILDER:
//             return std::make_shared<RoadBuilderCard>();
//         case MONOPOLY:
//             return std::make_shared<MonopolyCard>();
//         case YEAR_OF_PLENTY:
//             return std::make_shared<YearOfPlentyCard>();
//         case VICTORY_POINT:
//             return std::make_shared<VictoryPointCard>();
//         default:
//             throw std::invalid_argument("Invalid card type");
//         }
//     };
// }
#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include <stdexcept>

namespace ariel
{
    enum CardType
    {
        KNIGHT,
        ROAD_BUILDER,
        MONOPOLY,
        YEAR_OF_PLENTY,
        VICTORY_POINT
    };

    CardType getCardTypeFromString(const std::string &card);

    class Card
    {
    protected:
        int countcard; // Number of times the card can be used
    public:
        Card(int count);
        virtual ~Card() = default;
        virtual std::string getType() const = 0;
        virtual int getHowMuchLeft() const;
        virtual void reduceCard();
    };

    class KnightCard : public Card
    {
    public:
        KnightCard();
        std::string getType() const override;
    };

    class RoadBuilderCard : public Card
    {
    public:
        RoadBuilderCard();
        std::string getType() const override;
    };

    class MonopolyCard : public Card
    {
    public:
        MonopolyCard();
        std::string getType() const override;
    };

    class YearOfPlentyCard : public Card
    {
    public:
        YearOfPlentyCard();
        std::string getType() const override;
    };

    class VictoryPointCard : public Card
    {
    public:
        VictoryPointCard();
        std::string getType() const override;
    };

    std::shared_ptr<Card> createCard(CardType type);
}
