#pragma once

#include "resource.hpp"
#include <memory>
#include <string>
#include <vector>

namespace ariel
{
    class Tile
    {
    private:
        bool robberPresent = false;

    public:
        virtual std::string getType() const = 0;
        virtual std::shared_ptr<Resource> getResource() const = 0;
        virtual int getNumber() const = 0;
        // virtual vector<int> node;
        virtual std::vector<int> getNodesId(); // connected node number
        bool hasRobber() const;
        void placeRobber(bool hasRobber);
    };
}
