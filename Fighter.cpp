//
// Created by Daniel Kelley on 10/2/2022.
//
#include "Fighter.h"


Fighter::Fighter() {
    hp = STARTING_HP;
}

void Fighter::set_hp(int life) {
    hp = life;
    if (life < 0) {
        hp = 0;
    }
}

void Fighter::set_accuracy(int target) {
    accuracy = target;
}

int Fighter::get_hp() {
    return hp;
}

int Fighter::get_accuracy() {
    return accuracy;
}

void Fighter::feed() {
    hit.feed(20);
    set_hp(get_hp() - 20);
}

Attack Fighter::get_attack() {
    return hit;
}

