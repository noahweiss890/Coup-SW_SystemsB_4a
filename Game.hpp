#pragma once

#include <iostream>
#include <vector>
#include <string>
// #include "Player.hpp"


using namespace std;

namespace coup {
    class Game {
        vector<string> players_in_game;
        // vector<Player> players_in_game;
        unsigned long curr_turn;
        public:
            vector<string> players();
            string turn();
            string winner();
            void add_player(string name);
            // void add_player(Player p);
            void next_turn();
    };
}
