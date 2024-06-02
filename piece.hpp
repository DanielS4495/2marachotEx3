#include <string> // Add this include for string usage
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
        virtual Player getType() const = 0; // Pure virtual function to get the piece type
        virtual PieceType getPlayer() const = 0;
        virtual ~Piece() {} // Virtual destructor to allow proper cleanup of derived classes
    };

    class Road : public Piece
    {
        private::std::string player;

    public:
        Road(const std::string &player) const override
        {
            *this->player = player;
        }
        virtual PieceType getType() const override { return ROAD_PIECE; }
    };

    class Settlement : public Piece
    {
        private::std::string player;

    public:
        virtual PieceType getPlayer() const override
        {
            return player;
        }
        Settlement(const std::string &player)
        {
            *this->player = player;
        }

        virtual PieceType getType() const override
        {
            return SETTLEMENT_PIECE;
        }
    };

    class City : public Piece
    {
    private:
        std::string player;

    public:
        City(const std::string &player)
        {
            *this->player = player;
        }
        virtual PieceType getPlayer() const override
        {
            return player;
        }
        virtual PieceType getType() const override
        {
            return CITY_PIECE;
        }
    };
}