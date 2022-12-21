//
// Created by Daniel Kelley on 10/3/2022.
//

#ifndef M1OEP_JAVA_H
#define M1OEP_JAVA_H
#include "Fighter.h"

class Java: public Fighter {
public:

    /**Requires: nothing
     * Effects: hit, accuracy
     * Sets the damage and name fields of hit to the const fields below, and changes the accuracy stat to the const field below.
     */
    Java();

    /**Requires: nothing
     * Effects: hit, accuracy, hp
     * Increases hit.damage, accuracy, and hp by 10
     */
    void special_ability() override;

    const string ATTACK_NAME = "Constructor of doom";

    const int ATTACK_STAT = 60;

    const int ACCURACY_STAT = 60;
};

#endif //M1OEP_JAVA_H
