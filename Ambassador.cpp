#include "Ambassador.hpp"

Ambassador::Ambassador(coup::Game g, string player_name) : Player(g, player_name) {
    g.add_player(player_name);
}

void Ambassador::transfer(Player from, Player to) {

}

string Ambassador::role() {
    return "Ambassador";
}

void Ambassador::block(Player p) {

}