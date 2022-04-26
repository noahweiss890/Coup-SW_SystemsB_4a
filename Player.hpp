#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Game.hpp"

using namespace coup;
using namespace std;

class Player {
    protected:
        int money;
        string name;
        string last_action;
    public:
        Player(Game g, string player_name);
        void income();
        void foreign_aid();
        void coup(Player p);
        int coins();
};
#endif