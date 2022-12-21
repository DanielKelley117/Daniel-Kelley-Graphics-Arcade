//
// Created by Daniel Kelley on 10/2/2022.
//

#ifndef M1OEP_PYTHON_H
#define M1OEP_PYTHON_H
#include "Fighter.h"



class Python : public Fighter {
public:
    /**Requires: nothing
     * Effects: hit, accuracy,
     * Sets the damage and name fields of hit to the const name and stat field, and accuracy to the accuracy stat
     */
    Python();

    /**Requires: nothing
     * Effects: accuracy, hp, hit
     * Decreases the damage of hit and accuracy by 10 and increases hp by 20
     */
    void special_ability() override;

    const string ATTACK_NAME = "Constrict";

    const int ACCURACY_STAT = 65;

    const int ATTACK_STAT = 50;

};

#endif //M1OEP_PYTHON_H
