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

    // std::shared_ptr<Resource> createResource(ResourceType type)
    // {
    //     switch (type)
    //     {
    //     case WOOD:
    //         return std::make_shared<Wood>();//std::static_pointer_cast<Resource>(std::make_shared<Wood>());
    //     case BRICK:
    //         return std::make_shared<Brick>();//std::static_pointer_cast<Resource>(std::make_shared<Brick>());
    //     case SHEEP:
    //         return std::make_shared<Sheep>();//std::static_pointer_cast<Resource>(std::make_shared<Sheep>());
    //     case WHEAT:
    //         return std::make_shared<Wheat>();//std::static_pointer_cast<Resource>(std::make_shared<Wheat>());
    //     case IRON:
    //         return std::make_shared<Iron>();//std::static_pointer_cast<Resource>(std::make_shared<Iron>());
    //     default:
    //         throw std::invalid_argument("Invalid Resource type");
    //     }
    // }
}
