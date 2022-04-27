#include "Player.hpp"

Player::Player(Game g, string player_name) {
    this->game = g;
    this->name = player_name;
    this->money = 0;
    this->last_action = "NONE";
    this->affected = NULL;
    this->status = 0;
    g.add_player(player_name);
}

void Player::income() {
    if(this->game.turn() != this->name) {
        throw invalid_argument("not your turn!");
    }
    this->must_coup();
    this->money++;
    this->last_action = "INCOME";
    this->affected = NULL;
    this->game.next_turn();
}

void Player::foreign_aid() {
    if(this->game.turn() != this->name) {
        throw invalid_argument("not your turn!");
    }
    this->must_coup();
    this->money += 2;
    this->last_action = "FOREIGN AID";
    this->affected = NULL;
    this->game.next_turn();
}

void Player::coup(Player p) {
    if(this->game.turn() != this->name) {
        throw invalid_argument("not your turn!");
    }
    if(p.status != 0) {
        throw invalid_argument("illegal coup!");
    }
    if(this->money < 7) {
        throw invalid_argument("not enough coins");
    }
    this->money -= 7;
    p.set_status(1);
    this->game.change_status(p.name, 1);
    this->last_action = "COUP";
    this->affected = NULL;
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

void Player::set_status(int s) {
    this->status = s;
} 

string Player::get_last_action() {
    return this->last_action;
}

void Player::set_money(int m) {
    this->money += m;
}

void Player::must_coup() {
    if(this->money >= 10) {
        throw invalid_argument("player has 10+ coins and must coup!");
    }
}

Player* Player::get_affected() {
    return this->affected;
}
