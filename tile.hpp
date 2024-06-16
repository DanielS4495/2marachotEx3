//danielsamson10@gmail.com
#pragma once
#include "resource.hpp"
#include "hexagon.hpp"
#include <memory>
#include <string>
#include <vector>

namespace ariel
{
    class Tile
    {
    public:
        virtual ~Tile() = default;
        virtual std::string getType() const = 0;
        virtual std::string getResource() const = 0;
        virtual int getNumber() const = 0;
        virtual vector<int> getNode() const = 0;
    };
}
