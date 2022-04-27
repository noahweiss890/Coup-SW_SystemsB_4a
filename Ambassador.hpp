#include <iostream>
#include "Player.hpp"

using namespace coup;
using namespace std;

class Ambassador : public Player {
    public:
        Ambassador(Game g, string name) : Player(g, name) {
            
        }
        void transfer(Player from, Player to);
        string role();
        void block(Player p);
};
