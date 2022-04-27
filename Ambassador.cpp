#include "Ambassador.hpp"

using namespace coup;

void Ambassador::transfer(Player from, Player to) {
    if(from.get_status() != 0 || to.get_status() != 0 || from.coins() < 1) {
        throw invalid_argument("no money to transfer");
    }
    from.set_money(from.coins() - 1);
    to.set_money(to.coins() + 1);
}

string Ambassador::role() {
    return "Ambassador";
}

void Ambassador::block(Player p) {

}
