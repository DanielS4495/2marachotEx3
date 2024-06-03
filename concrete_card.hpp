// #pragma

// #include "card.hpp"
// #include "player.hpp"
// namespace ariel
// {
//     class KnightCard : public Card
//     {
//     public:
//         std::string getType() const override { return "Knight"; }
//         void play() override 
//         {
//         }
//     };

//     class RoadBuilderCard : public Card
//     {
//     public:
//         std::string getType() const override { return "Road Builder"; }
//         void play() override //need 2 index to put the road
//         {
//         }
//     };
//     class MonopolyCard : public Card
//     {
//     public:
//         std::string getType() const override { return "Monopoly"; }
//         void play() override //need resource to get from everyone
//         {
//         }
//     };
//     class YearOfPlentyCard : public Card
//     {
//     public:
//         std::string getType() const override { return "Year Of Plenty"; }
//         void play(Player p,const std::string &getResource1,const std::string &getResource2) override //need two resource to get from the bank :)
//         {
//             p.addResource(getResource1);
//             p.addResource(getResource2);
//         }
//     };
//     class VictoryPointCard : public Card
//     {
//     public:
//         std::string getType() const override { return "VictoryPoint"; }
//         void play(Player p) override //get one victory point
//         {
//             p.addvictorypoints();
//         }
//     };
// }
