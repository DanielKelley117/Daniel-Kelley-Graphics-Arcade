//
// Created by Daniel Kelley on 10/3/2022.
//

#ifndef M1OEP_CDOUBLEP_H
#define M1OEP_CDOUBLEP_H
#include "Fighter.h"

class CDoubleP: public Fighter {
public:
    /**Requires: nothing
     * Effects: hit, accuracy, shield
     * Initializes hit.name, hit.damage, and accuracy to the fields below, and sets shield to false
     */
    CDoubleP();

    //Getter for shield
    bool get_shield();

    //Setter for shield
    void set_shield(bool statement);

    /**Requires: nothing
     * Effects: hp
     * Increases hp by 30
     */
    void special_ability();

    const string ATTACK_NAME = "Vector beam";

    const int ATTACK_STAT = 75;

    const int ACCURACY_STAT = 45;
protected:
    bool shield;
};
#endif //M1OEP_C_H
