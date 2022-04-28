#include "Game.hpp"

namespace coup {

    vector<string> Game::players() {
        vector<string> plrs;
        for(unsigned long i = 0; i < this->players_in_game.size(); i++) {
            if(this->players_status.at(i) == 0) {
                plrs.push_back(this->players_in_game.at(i));
            }
        }
        return plrs;
    }

    vector<int> Game::statuses() {
        vector<int> stts;
        for(unsigned long i = 0; i < this->players_status.size(); i++) {
            stts.push_back(this->players_status.at(i));
        }
        return stts;
    }

    string Game::turn() {
        if(this->players_in_game.empty()) {
            throw invalid_argument("no players in the game yet!");
        }
        return this->players_in_game.at(this->curr_turn);
    }

    string Game::winner() {
        string win;
        for(unsigned long i = 0; i < this->players_in_game.size(); i++) {
            if(this->players_status.at(i) == 0) {
                if(!win.empty()) {
                    throw invalid_argument("game not over yet!");
                }
                win = this->players_in_game.at(i);
            }
        }
        return win;
    }

    void Game::add_player(string const &name) {
        if(started) {
            throw invalid_argument("game already started, cant add more players!");
        }
        this->players_in_game.push_back(name);
        this->players_status.push_back(0);
    }

    void Game::next_turn() {
        if(!this->started) {
            this->started = true;
        }
        this->curr_turn = (this->curr_turn + 1) % this->players_in_game.size();
        while(this->players_status.at(this->curr_turn) != 0) {
            this->curr_turn = (this->curr_turn + 1) % this->players_in_game.size();
        }
    }

    void Game::change_status(string const &name, int status) {
        for(unsigned long i = 0; i < this->players_in_game.size(); i++) {
            if(this->players_in_game.at(i) == name) {
                this->players_status.at(i) = status;
                return;
            }
        }
        throw invalid_argument("player not in game!");
    }
}
