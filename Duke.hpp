#include <iostream>
#include "Player.hpp"

using namespace std;

class Duke : public Player {
    public:
        Duke(coup::Game g, string name);
        void tax();
        string role();
        void block(Player p);
};
