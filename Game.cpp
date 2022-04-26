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

    // vector<string> Game::players() {
    //     vector<string> plrs;
    //     for(Player p : this->players_in_game) {
    //         plrs.push_back(p.get_name());
    //     }
    //     return plrs;
    // }

    string Game::turn() {
        return "Noah";
        // if(this->players_in_game.empty()) {
        //     throw invalid_argument("no players in the game yet!");
        // }
        // return this->players_in_game.at(this->curr_turn);
    }

    // string Game::turn() {
    //     if(this->players_in_game.empty()) {
    //         throw invalid_argument("no players in the game yet!");
    //     }
    //     return this->players_in_game.at(this->curr_turn).get_name();
    // }

    string Game::winner() {
        return "Noah";
    }

    // string Game::winner() {
    //     string win = "";
    //     for(Player p : this->players_in_game) {
    //         if(p.get_status() == 0) {
    //             if(!win.empty()) {
    //                 throw invalid_argument("game not over yet!");
    //             }
    //             win = p.get_name();
    //         }
    //     }
    //     return win;
    // }

    void Game::add_player(string name) {
        this->players_in_game.push_back(name);
    }

    // void Game::add_player(Player p) {
    //     this->players_in_game.push_back(p);
    // }

    void Game::next_turn() {
        
    }

    // void Game::next_turn() {
    //     this->curr_turn = (this->curr_turn + 1) % this->players_in_game.size();
    //     while(this->players_in_game.at(this->curr_turn).get_status() != 0) {
    //         this->curr_turn = (this->curr_turn + 1) % this->players_in_game.size();
    //     }
    // }
}