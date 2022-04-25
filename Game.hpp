#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace coup {
    class Game {
        vector<string> players_in_game;
        unsigned long curr_turn;
        public:
            Game();
            vector<string> players();
            string turn();
            string winner();
            void add_player(string name);
    };
}