#pragma
#include "tile.hpp"
#include "concrete_resource.hpp"
#include <memory>
#include <string>
namespace ariel{
    class Tile{
    bool Tile::hasRobber() const
    {
        return robberPresent;
    }

    void Tile::placeRobber(bool hasRobber)
    {
        robberPresent = hasRobber;
    }
    }
    class ForestTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;

    public:
        ForestTile(int num) : resource(std::make_shared<Wood>()), number(num) {}
        std::string getType() const override { return "Forest"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class HillsTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;

    public:
        HillsTile(int num) : resource(std::make_shared<Brick>()), number(num) {}
        std::string getType() const override { return "Hills"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class PastureTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;

    public:
        PastureTile(int num) : resource(std::make_shared<Wool>()), number(num) {}
        std::string getType() const override { return "Pasture Land"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class FieldsTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;

    public:
        FieldsTile(int num) : resource(std::make_shared<Grain>()), number(num) {}
        std::string getType() const override { return "Agricultural Land"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class MountainsTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;

    public:
        MountainsTile(int num) : resource(std::make_shared<Ore>()), number(num) {}
        std::string getType() const override { return "Mountains"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class DesertTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;

    public:
        DesertTile() : resource(std::make_shared<None>()), number(0) {}
        std::string getType() const override { return "Desert"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };
}
