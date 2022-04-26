#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;

class Captain : public Player {
    public:
        Captain(Game g, string name) : Player(g, name) {
             g.add_player(name);
        }
        void steal(Player from);
        string role();
        void block(Player p);
};
