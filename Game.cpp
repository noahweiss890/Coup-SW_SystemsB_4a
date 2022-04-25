#include <iostream>
#include <vector>
#include <string>
#include "Game.hpp"

using namespace std;

namespace coup {

    vector<string> Game::players() {
        vector<string> plrs;
        for(string name : this->players_in_game) {
            plrs.push_back(name);
        }
        return plrs;
    }

    string Game::turn() {
        if(this->players_in_game.empty()) {
            throw invalid_argument("no players in the game yet!");
        }
        return this->players_in_game[this->curr_turn];
    }

    string Game::winner() {
        if(this->players_in_game.size() > 1) {
            throw invalid_argument("game not over!");
        }
        return this->players_in_game[0];
    }
}