#include "Game.hpp"

class Player {
    protected:
        int money;
        string name;
        string last_action;
    public:
        Player(string player_name) {
            money = 0;
            name = player_name;
        }
        void income();
        void foreign_aid();
        void coup(Player p);
        int coins();
};