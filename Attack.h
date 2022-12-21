//
// Created by Daniel Kelley on 10/2/2022.
//

#ifndef M1OEP_ATTACK_H
#define M1OEP_ATTACK_H
#include <string>
using std::string;

class Attack {
private:
    string name;
    int damage;
public:
    /**Requires: nothing
     * Effects: damage
     * Sets damage to 0
     */
    Attack();

    /** Requires: int destruction
     * Effects: damage
     * Sets damage to desctruction
     * @param destruction
     */
    void set_damage(int destruction);

    /**Requires: string nick_name
     * Effects: name
     * Sets name to nick_name
     * @param nick_name
     */
    void set_name(string nick_name);

    /** Requires: nothing
     * Effects: nothing
     * Returns damage
     * @return
     */
    int get_damage();

    /** Requires: nothing
     * Effects: nothing
     * Returns name
     * @return
     */
    string get_name();

    /**Requires: int amount
     * Effects: damage
     * Increases damage by amount
     * @param amount
     */
    void feed(int amount);





};

#endif //M1OEP_ATTACK_H
