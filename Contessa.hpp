#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;

class Contessa : public Player {
    public:
        Contessa(Game g, string name) : Player(g, name) {
             g.add_player(name);
        }
        string role();
        void block(Player p);
};
