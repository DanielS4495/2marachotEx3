//danielsamson10@gmail.com
#include "tile.hpp"
#include <memory>
#include <string>
namespace ariel
{

    class ForestTile : public Tile
    {
    private:
        std::string resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        ForestTile(int num, std::vector<int> node) : resource("WOOD"), number(num), node(node) {}
        std::string getType() const override { return "Forest"; }
        std::string getResource() const override { return resource; }
        int getNumber() const override { return number; }
        vector<int> getNode() const override { return node; }
    };

    class HillsTile : public Tile
    {
    private:
        std::string resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        HillsTile(int num, std::vector<int> node) : resource("BRICK"), number(num), node(node) {}
        std::string getType() const override { return "Hills"; }
        std::string getResource() const override { return resource; }
        int getNumber() const override { return number; }
        vector<int> getNode() const override { return node; }
    };

    class PastureTile : public Tile
    {
    private:
        std::string resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        PastureTile(int num, std::vector<int> node) : resource("SHEEP"), number(num), node(node) {}
        std::string getType() const override { return "Pasture Land"; }
        std::string getResource() const override { return resource; }
        int getNumber() const override { return number; }
        vector<int> getNode() const override { return node; }
    };

    class AgriculturalTile : public Tile
    {
    private:
        std::string resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        AgriculturalTile(int num, std::vector<int> node) : resource("WHEAT"), number(num), node(node) {}
        std::string getType() const override { return "Agricultural Land"; }
        std::string getResource() const override { return resource; }
        int getNumber() const override { return number; }
        vector<int> getNode() const override { return node; }
    };

    class MountainsTile : public Tile
    {
    private:
        std::string resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        MountainsTile(int num, std::vector<int> node) : resource("IRON"), number(num), node(node) {}
        std::string getType() const override { return "Mountains"; }
        std::string getResource() const override { return resource; }
        int getNumber() const override { return number; }
        vector<int> getNode() const override { return node; }
    };
    class DesertTile : public Tile
    {
    private:
        std::string resource;
        int number;
        std::vector<int> node; // connected node number

    public:
        DesertTile(int num, std::vector<int> node) : resource(""), number(0), node(node) {}
        std::string getType() const override { return "Desert"; }
        std::string getResource() const override { return resource; }
        int getNumber() const override { return number; }
        vector<int> getNode() const override { return node; }
    };

}
