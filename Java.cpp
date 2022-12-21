//
// Created by Daniel Kelley on 10/3/2022.
//
#include "Java.h"

Java::Java(): Fighter() {
    hit.set_name(ATTACK_NAME);
    hit.set_damage(ATTACK_STAT);
    accuracy = ACCURACY_STAT;
}

void Java::special_ability() {
    hit.set_damage(hit.get_damage() + 10);
    accuracy = accuracy + 10;
    hp = hp + 10;
}

