#pragma once
#include <string>
namespace ariel
{
    class Player;
}
namespace ariel
{
    enum PieceType
    {
        ROAD_PIECE,
        SETTLEMENT_PIECE,
        CITY_PIECE
    };

    class Piece
    {
    public:
        virtual std::string getType() const = 0;
        virtual const Player &getPlayer() const = 0;
        virtual ~Piece() {}
    };

    class Road : public Piece
    {
    private:
        Player player;

    public:
        Road(const Player &player) : player(player) {}

        virtual const Player &getPlayer() const override
        {
            return player;
        }

        virtual std::string getType() const override { return "road"; }
    };

    class Settlement : public Piece
    {
    private:
        Player player;

    public:
        Settlement(const Player &player) : player(player) {}

        virtual const Player &getPlayer() const override
        {
            return player;
        }

        virtual std::string getType() const override { return "settlement"; }
    };

    class City : public Piece
    {
    private:
        Player player;

    public:
        City(const Player &player) : player(player) {}

        virtual const Player &getPlayer() const override
        {
            return player;
        }

        virtual std::string getType() const override { return "city"; }
    };
}
