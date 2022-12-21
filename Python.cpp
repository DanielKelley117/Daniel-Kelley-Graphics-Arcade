//
// Created by Daniel Kelley on 10/3/2022.
//

#include "Python.h"


Python::Python(){
    hit.set_name(ATTACK_NAME);
    hit.set_damage(ATTACK_STAT);
    accuracy = ACCURACY_STAT;
}

void Python::special_ability() {
    hit.set_damage(ATTACK_STAT - 10);
    accuracy = ACCURACY_STAT - 10;
    hp = hp + 20;
}

