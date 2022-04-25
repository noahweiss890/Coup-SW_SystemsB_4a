#include <iostream>
#include "Player.hpp"

using namespace std;

class Captain : public Player {
    public:
        Captain(coup::Game g, string name);
        void steal(Player from);
        string role();
        void block(Player p);
};
