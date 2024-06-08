#pragma once
#include <string>
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
        virtual ~Piece() {}
    };

    class Road : public Piece
    {
        virtual std::string getType() const override { return "road"; }
    };

    class Settelemnt : public Piece
    {
        virtual std::string getType() const override { return "settlement"; }
    };

    class City : public Piece
    {
        virtual std::string getType() const override { return "city"; }
    };
}
