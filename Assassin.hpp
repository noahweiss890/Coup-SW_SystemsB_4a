#include <iostream>
#include "Player.hpp"

using namespace std;

class Assassin : public Player {
    public:
        Assassin(coup::Game g, string name);
        void coup(Player p);
        string role();
};
