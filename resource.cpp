//danielsamson10@gmail.com
#include "resource.hpp"
#include <stdexcept>

namespace ariel
{
    ResourceType getResourceTypeFromString(const std::string &resource)
    {
        static std::unordered_map<std::string, ResourceType> resourceMap = {
            {"WOOD", WOOD},
            {"BRICK", BRICK},
            {"SHEEP", SHEEP},
            {"WHEAT", WHEAT},
            {"IRON", IRON}};

        auto it = resourceMap.find(resource);
        if (it != resourceMap.end())
        {
            return it->second;
        }
        else
        {
            throw std::invalid_argument("Invalid resource type");
        }
    }

    std::unordered_map<std::string, ResourceType> resourceTypeToString = {
        {"WOOD", ResourceType::WOOD},
        {"BRICK", ResourceType::BRICK},
        {"SHEEP", ResourceType::SHEEP},
        {"WHEAT", ResourceType::WHEAT},
        {"IRON", ResourceType::IRON}};

}
