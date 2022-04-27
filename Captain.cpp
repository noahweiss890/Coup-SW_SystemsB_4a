#include "Captain.hpp"

void Captain::steal(Player from) {
    if(this->game.turn() != this->name) {
        throw invalid_argument("not your turn!");
    }
    this->must_coup();
    if(from.get_status() != 0 || from.coins() < 2) {
        throw invalid_argument("illegal steal!");
    }
    this->set_money(2);
    from.set_money(-2);
    this->affected = &from;
    this->last_action = "STEAL";
    this->game.next_turn();
}

string Captain::role() {
    return "Captain";
}

void Captain::block(Player p) {
    if(p.get_status() != 0 || p.role() != "Captain" || p.get_last_action() != "STEAL") {
        throw invalid_argument("invalid block!");
    }
    p.set_money(-2);
    p.get_affected()->set_money(2);
}
