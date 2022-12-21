//
// Created by Daniel Kelley on 10/2/2022.
//

#include "Attack.h"

Attack::Attack() {
    damage = 0;
}

void Attack::set_damage(int destruction) {
    damage = destruction;
}

void Attack::set_name(string nick_name) {
    name = nick_name;
}

int Attack::get_damage() {
    return damage;
}

string Attack::get_name() {
    return name;
}

void Attack::feed(int amount) {
    damage += amount;
}


