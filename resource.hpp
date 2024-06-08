// #pragma once
// #include <stdexcept>
// #include <memory>
// #include <string>
// #include <unordered_map>
// namespace ariel
// {
//     enum ResourceType
//     {
//         WOOD,
//         BRICK,
//         SHEEP,
//         WHEAT,
//         ORE

//     };

//     ResourceType getResourceTypeFromString(const std::string &resource)
//     {
//         static std::unordered_map<std::string, ResourceType> resourceMap = {
//             {"WOOD", WOOD},
//             {"BRICK", BRICK},
//             {"SHEEP", SHEEP},
//             {"WHEAT", WHEAT},
//             {"ORE", ORE}};

//         auto it = resourceMap.find(resource);
//         if (it != resourceMap.end())
//         {
//             return it->second;
//         }
//         else
//         {
//             throw std::invalid_argument("Invalid resource type");
//         }
//     }
//     std::unordered_map<std::string,ResourceType> stringToResource = {
//         {"WOOD", ResourceType::WOOD},
//         {"BRICK", ResourceType::BRICK},
//         {"SHEEP", ResourceType::SHEEP},
//         {"WHEAT", ResourceType::WHEAT},
//         {"ORE", ResourceType::ORE}};

//     class Resource
//     {
//     public:
//         virtual ~Resource() = default;
//         virtual std::string getType() const = 0;
//     };

//     class Wood : public Resource
//     {
//     public:
//         std::string getType() const override { return "Wood"; }
//     };

//     class Brick : public Resource
//     {
//     public:
//         std::string getType() const override { return "Brick"; }
//     };

//     class Sheep : public Resource
//     {
//     public:
//         std::string getType() const override { return "Sheep"; }
//     };

//     class Wheat : public Resource
//     {
//     public:
//         std::string getType() const override { return "Wheat"; }
//     };

//     class Ore : public Resource
//     {
//     public:
//         std::string getType() const override { return "Ore"; }
//     };
//     std::shared_ptr<ariel::Resource> createResource(ResourceType type)
//     {
//         switch (type)
//         {
//         case WOOD:
//             return std::static_pointer_cast<ariel::Resource>(std::make_shared<ariel::Wood>());
//         case BRICK:
//             return std::static_pointer_cast<ariel::Resource>(std::make_shared<ariel::Brick>());
//         case SHEEP:
//             return std::static_pointer_cast<ariel::Resource>(std::make_shared<ariel::Sheep>());
//         case WHEAT:
//             return std::static_pointer_cast<ariel::Resource>(std::make_shared<ariel::Wheat>());
//         case ORE:
//             return std::static_pointer_cast<ariel::Resource>(std::make_shared<ariel::Ore>());
//         default:
//             throw std::invalid_argument("Invalid Resource type");
//         }
//     }

// }
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
        ORE
    };

    ResourceType getResourceTypeFromString(const std::string &resource);
    extern std::unordered_map<std::string, ResourceType> stringToResource;

    class Resource
    {
    public:
        virtual ~Resource() = default;
        virtual std::string getType() const = 0;
    };

    class Wood : public Resource
    {
    public:
        std::string getType() const override { return "Wood"; }
    };

    class Brick : public Resource
    {
    public:
        std::string getType() const override { return "Brick"; }
    };

    class Sheep : public Resource
    {
    public:
        std::string getType() const override { return "Sheep"; }
    };

    class Wheat : public Resource
    {
    public:
        std::string getType() const override { return "Wheat"; }
    };

    class Ore : public Resource
    {
    public:
        std::string getType() const override { return "Ore"; }
    };

    std::shared_ptr<ariel::Resource> createResource(ResourceType type);
}
