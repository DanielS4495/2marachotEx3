#pragma

#include "resource.hpp"
namespace ariel{
class Wood : public Resource {
public:
    std::string getType() const override { return "Wood"; }
};

class Brick : public Resource {
public:
    std::string getType() const override { return "Brick"; }
};

class Wool : public Resource {
public:
    std::string getType() const override { return "Wool"; }
};

class Grain : public Resource {
public:
    std::string getType() const override { return "Grain"; }
};

class Ore : public Resource {
public:
    std::string getType() const override { return "Ore"; }
};

class None : public Resource {
public:
    std::string getType() const override { return "None"; }
};

}