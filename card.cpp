//danielsamson10@gmail.com
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

    // Initialize the static member outside the class
    int KnightCard::countcard = 14;
    int RoadBuilderCard::countcard = 2;
    int MonopolyCard::countcard = 2;
    int YearOfPlentyCard::countcard = 2;
    int VictoryPointCard::countcard = 5;

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
