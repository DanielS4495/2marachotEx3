#pragma

#include <string>
#include <memory>
#include "development_card.hpp"
namespace ariel
{
    class Card
    {
    public:
        virtual ~Card() = default;
        virtual std::string getType() const = 0;
        virtual void play() = 0;
    };
}
