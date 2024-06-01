#include "Tile.hpp"
namespace ariel{
    bool Tile::hasRobber() const
    {
        return robberPresent;
    }

    void Tile::placeRobber(bool hasRobber)
    {
        robberPresent = hasRobber;
    }
}