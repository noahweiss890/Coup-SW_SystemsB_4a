#include "Ambassador.hpp"

using namespace coup;

void Ambassador::transfer(Player &from, Player &to) {
    if(this->game->turn() != this->name) {
        throw invalid_argument(this->name + " not your turn!");
    }
    this->must_coup();
    if(from.get_status() != 0 || to.get_status() != 0 || from.coins() < 1) {
        throw invalid_argument("no money to transfer");
    }
    from.set_money(-1);
    to.set_money(1);
    this->last_action = "TRANSFER";
    this->game->next_turn();
}

void Ambassador::block(Player &p) {
    if(p.get_status() != 0 || this->game->turn() == p.get_name() || p.role() != "Captain" || p.get_last_action() != "STEAL") {
        throw invalid_argument("invalid block!");
    }
    p.set_money(-2);
    p.get_affected()->set_money(2);
}
