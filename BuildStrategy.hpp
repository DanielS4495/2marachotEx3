// strategy.hpp
#ifndef STRATEGY_HPP
#define STRATEGY_HPP

class BuildStrategy {
public:
    virtual void build() = 0;
};

class RoadBuildStrategy : public BuildStrategy {
public:
    void build() override {
        // Logic to build a road
    }
};

class SettlementBuildStrategy : public BuildStrategy {
public:
    void build() override {
        // Logic to build a settlement
    }
};

class CityBuildStrategy : public BuildStrategy {
public:
    void build() override {
        // Logic to build a city
    }
};
#endif // STRATEGY_HPP
