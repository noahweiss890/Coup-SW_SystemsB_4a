#include <iostream>
#include "Player.hpp"

using namespace std;

class Ambassador : public Player {
    public:
        Ambassador(coup::Game g, string name);
        void transfer(Player from, Player to);
        string role();
        void block(Player p);
};
