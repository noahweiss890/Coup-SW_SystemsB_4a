#pragma once

#include "Game.hpp"

using namespace coup;
using namespace std;

class Player {
    protected:
        Game game;
        int money;
        string name;
        string last_action;
        int status;
    public:
        Player(Game g, string player_name);
        void income();
        void foreign_aid();
        virtual void coup(Player p);
        int coins();
        string get_name();
        int get_status();
        void set_money(int m);
        void must_coup();
};
