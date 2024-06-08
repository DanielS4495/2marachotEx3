
#include "tile.hpp"
#include <memory>
#include <string>
namespace ariel
{
    bool Tile::hasRobber() const
    {
        return this->robberPresent;
    }

    void Tile::placeRobber(bool hasRobber)
    {
        robberPresent = hasRobber;
    }
    class ForestTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        ForestTile(int num, std::vector<int> node) : resource(std::make_shared<Wood>()), number(num), node(node) {}
        std::string getType() const override { return "Forest"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class HillsTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        HillsTile(int num, std::vector<int> node) : resource(std::make_shared<Brick>()), number(num), node(node) {}
        std::string getType() const override { return "Hills"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class PastureTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        PastureTile(int num, std::vector<int> node) : resource(std::make_shared<Sheep>()), number(num), node(node) {}
        std::string getType() const override { return "Pasture Land"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class AgriculturalTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        AgriculturalTile(int num, std::vector<int> node) : resource(std::make_shared<Wheat>()), number(num), node(node) {}
        std::string getType() const override { return "Agricultural Land"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

    class MountainsTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        MountainsTile(int num, std::vector<int> node) : resource(std::make_shared<Ore>()), number(num), node(node) {}
        std::string getType() const override { return "Mountains"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };
    class DesertTile : public Tile
    {
        std::shared_ptr<Resource> resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        DesertTile(int num, std::vector<int> node) : resource(NULL), number(num), node(node) {}
        std::string getType() const override { return "Mountains"; }
        std::shared_ptr<Resource> getResource() const override { return resource; }
        int getNumber() const override { return number; }
    };

}
