#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;

class Duke : public Player {
    public:
        Duke(Game g, string name) : Player(g, name) {
            //  g.add_player(*this);
        }
        void tax();
        string role();
        void block(Player p);
};
