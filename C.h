//
// Created by Daniel Kelley on 10/3/2022.
//

#ifndef M1OEP_C_H
#define M1OEP_C_H
#include "Fighter.h"
class C: public Fighter {
public:

    /**Requires: nothing
     * Effects: hit, accuracy
     * Initializes accuracy, hit.damage, and hit.name to the fields below.
     */
    C();

    /**Requires: nothing
     * Effects: accuracy, hp
     * Increases accuracy by 20 and decreases hp by 30
     */
    void special_ability() override;

    const string ATTACK_NAME = "Data erase";

    const int ACCURACY_STAT = 30;

    const int ATTACK_STAT = 90;

};

#endif //M1OEP_C_H
