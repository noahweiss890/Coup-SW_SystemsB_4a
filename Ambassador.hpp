#include <iostream>
#include "Player.hpp"

using namespace std;

class Ambassador : public Player {
    public:
        Ambassador(Game g, string name) : Player(g, name) {
             g.add_player(name);
        }
        void transfer(Player from, Player to);
        string role();
        void block(Player p);
};
