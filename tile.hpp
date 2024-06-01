#pragma

#include "resource.hpp"
#include <memory>
#include <string>
namespace ariel
{

    class Tile
    {
    private:
        bool robberPresent = false;

    public:
        virtual ~Tile() = default;
        virtual std::string getType() const = 0;
        virtual std::shared_ptr<Resource> getResource() const = 0;
        virtual int getNumber() const = 0;
        bool hasRobber() const;
        void placeRobber(bool hasRobber);
    };

}
