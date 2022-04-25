#include <iostream>

using namespace std;

class Contessa : public Player {
    public:
        Contessa(coup::Game g, string name);
        string role();
        void block(Player p);
};
