//
// Created by Daniel Kelley on 10/3/2022.
//

#include "CDoubleP.h"

CDoubleP::CDoubleP() {
    hit.set_name(ATTACK_NAME);
    hit.set_damage(ATTACK_STAT);
    set_accuracy(ACCURACY_STAT);
    shield = false;
}

bool CDoubleP::get_shield() {
    return shield;
}

void CDoubleP::set_shield(bool statement) {
    shield = statement;
}

void CDoubleP::special_ability() {
    hp += 30;
}



