//danielsamson10@gmail.com
#pragma once
#include <string>
#include <memory>
#include <unordered_map>

namespace ariel
{
    enum ResourceType
    {
        WOOD,
        BRICK,
        SHEEP,
        WHEAT,
        IRON
    };

    ResourceType getResourceTypeFromString(const std::string &resource);
}
