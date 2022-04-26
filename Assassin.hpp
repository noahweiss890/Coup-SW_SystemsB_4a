#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;

class Assassin : public Player {
    public:
        Assassin(Game g, string name) : Player(g, name) {
            // g.add_player(*this);
        }
        void coup(Player p);
        string role();
};
