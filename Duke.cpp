#include "Duke.hpp"

void Duke::tax() {
    if(this->game.turn() != this->name) {
        throw invalid_argument("not your turn!");
    }
    this->must_coup();
    this->set_money(3);
    this->last_action = "TAX";
    this->game.next_turn();
}

string Duke::role() {
    return "Duke";
}

void Duke::block(Player p) {
    if(p.get_status() != 0 || p.get_last_action() != "FOREIGN AID") {
        throw invalid_argument("illegal block!");
    }
    p.set_money(-2);
}