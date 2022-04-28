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
        bool started;
        public:
            Game() {
                curr_turn = 0;
                started = false;
            }
            vector<string> players();
            vector<int> statuses();
            string turn();
            string winner();
            void add_player(string const &name);
            void next_turn();
            void change_status(string const &name, int status);
    };
}
