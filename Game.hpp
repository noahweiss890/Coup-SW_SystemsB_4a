#pragma once

#include <iostream>
#include <vector>
#include <string>


using namespace std;

namespace coup {
    class Game {
        vector<string> players_in_game;
        vector<int> players_status;
        unsigned long curr_turn;
        public:
            vector<string> players();
            string turn();
            string winner();
            void add_player(string name);
            void next_turn();
            void change_status(string name, int status);
    };
}
