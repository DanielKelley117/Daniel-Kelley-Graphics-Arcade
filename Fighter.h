//
// Created by Daniel Kelley on 10/2/2022.
//

#ifndef M1OEP_FIGHTER_H
#define M1OEP_FIGHTER_H
#include "Attack.h"

class Fighter {
public:
    /** Requires: nothing
     * Effects: nothing
     * Sets hp to STARTING_HP
     */
    Fighter();

    /**Requires: int life
     * Effects: hp
     * Sets hp to life
     * @param life
     */
    void set_hp(int life);

    /**Requires int target
     * Effects: accuracy
     * Sets accuracy to target
     * @param target
     */
    void set_accuracy(int target);

    /**Requires: nothing
     * Effects: nothing
     * Returns hp
     * @return
     */
    int get_hp();

    /**Requires: nothing
     * Effects: nothing
     * Returns accuracy
     * @return
     */
    int get_accuracy();

    /**Requires: nothing
     * Effects: hp, hit
     * Calls the hit feed method and subtracts 20 from hp
     */
    void feed();

    //Pure virtual method to be overridden
    virtual void special_ability() = 0;

    /**Requires: nothing
     * Effects: nothing
     * Returns hit
     * @return
     */
    Attack get_attack();

    const static int STARTING_HP = 100;

protected:
    Attack hit;
    int accuracy;
    int hp;

};

#endif //M1OEP_FIGHTER_H
