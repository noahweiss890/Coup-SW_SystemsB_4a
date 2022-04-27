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
        Player *affected;
    public:
        Player(Game g, string player_name);
        void income();
        void foreign_aid();
        void coup(Player p);
        int coins();
        string get_name();
        int get_status();
        void set_status(int s);
        string get_last_action();
        void set_money(int m);
        void must_coup();
        string role();
        Player* get_affected();
};
