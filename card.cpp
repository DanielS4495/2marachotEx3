// #include "card.hpp"
// namespace ariel
// {
//     // class Player;
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

//     class KnightCard : public Card
//     {
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

// }
#include "card.hpp"

namespace ariel
{
    CardType getCardTypeFromString(const std::string &card)
    {
        static std::unordered_map<std::string, CardType> cardMap = {
            {"Knight", KNIGHT},
            {"Road Builder", ROAD_BUILDER},
            {"Monopoly", MONOPOLY},
            {"Year Of Plenty", YEAR_OF_PLENTY},
            {"Victory Point", VICTORY_POINT}};

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


    //need to do it in every class not in the card class


    Card::Card(int count) : countcard(count) {}
    int Card::getHowMuchLeft() const { return countcard; }
    void Card::reduceCard()
    {
        if (countcard > 0)
            --countcard;
    }

    KnightCard::KnightCard() : Card(14) {}

    std::string KnightCard::getType() const { return "Knight"; }

    RoadBuilderCard::RoadBuilderCard() : Card(2) {}

    std::string RoadBuilderCard::getType() const { return "Road Builder"; }

    MonopolyCard::MonopolyCard() : Card(2) {}

    std::string MonopolyCard::getType() const { return "Monopoly"; }

    YearOfPlentyCard::YearOfPlentyCard() : Card(2) {}

    std::string YearOfPlentyCard::getType() const { return "Year Of Plenty"; }

    VictoryPointCard::VictoryPointCard() : Card(5) {}

    std::string VictoryPointCard::getType() const { return "Victory Point"; }

    std::shared_ptr<Card> createCard(CardType type)
    {
        switch (type)
        {
        case KNIGHT:
            return std::make_shared<KnightCard>();
        case ROAD_BUILDER:
            return std::make_shared<RoadBuilderCard>();
        case MONOPOLY:
            return std::make_shared<MonopolyCard>();
        case YEAR_OF_PLENTY:
            return std::make_shared<YearOfPlentyCard>();
        case VICTORY_POINT:
            return std::make_shared<VictoryPointCard>();
        default:
            throw std::invalid_argument("Invalid card type");
        }
    }
}
