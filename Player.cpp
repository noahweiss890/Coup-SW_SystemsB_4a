#include "Player.hpp"

Player::Player(Game g, string player_name) {
    this->game = g;
    this->name = player_name;
    this->money = 0;
    this->last_action = "NONE";
    this->status = 0;
    g.add_player(player_name);
    // g.add_player(*this);
}

void Player::income() {
    if(this->game.turn() != this->name) {
        throw invalid_argument("not your turn!");
    }
    this->money++;
    this->last_action = "INCOME";
    this->game.next_turn();
}

void Player::foreign_aid() {
    if(this->game.turn() != this->name) {
        throw invalid_argument("not your turn!");
    }
    this->money += 2;
    this->last_action = "FOREIGN AID";
    this->game.next_turn();
}

void Player::coup(Player p) {
    if(this->game.turn() != this->name) {
        throw invalid_argument("not your turn!");
    }
    if(this->money < 7) {
        throw invalid_argument("not enough coins");
    }
    this->last_action = "COUP";
    this->game.next_turn();
}

int Player::coins() {
    return this->money;
}

string Player::get_name() {
    return this->name;
}

int Player::get_status() {
    return this->status;
}