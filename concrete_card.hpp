#pragma

#include "card.hpp"
namespace ariel
{
    class KnightCard : public Card
    {
    public:
        std::string getType() const override { return "Knight"; }
        void play() override
        {
            // Define what happens when a Knight card is played
        }
    };

    class RoadBuilderCard : public Card
    {
    public:
        std::string getType() const override { return "Road Builder"; }
        void play() override
        {
            // Define what happens when a Road Builder card is played
        }
    };

    // Other card types can be added here

}