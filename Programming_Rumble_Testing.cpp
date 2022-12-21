//
// Created by Daniel Kelley on 10/8/2022.
//
#include <iostream>
#include "Attack.h"
#include "Fighter.h"
#include "CDoubleP.h"
#include "C.h"
#include "Python.h"
#include "Java.h"

using namespace std;

bool fighter_test();
bool attack_test();
bool java_test();
bool python_test();
bool c_test();
bool cpp_test();
int main() {
    if (fighter_test()) {
        cout << "Passed all Fighter tests" << endl;
    }

    if (attack_test()) {
        cout << "Passed all Attack tests" << endl;
    }

    if (java_test()) {
        cout << "Passed all Java tests" << endl;
    }

    if (python_test()) {
        cout << "Passed all Python tests" << endl;
    }

    if (c_test()) {
        cout << "Passed all C tests" << endl;
    }

    if (cpp_test()) {
        cout << "Passed all C++ tests" << endl;
    }


    return 0;
}

bool fighter_test() {
    bool passed = true;

    Java warrior;

    warrior.set_hp(50);
    if (warrior.get_hp() != 50) {
        cout << "FAILED: Fighter set_hp" << endl;
        passed = false;
    }

    int hpTest = warrior.get_hp();
    if (hpTest != 50) {
        cout << "FAILED: Fighter get_hp" << endl;
        passed = false;
    }

    warrior.set_accuracy(60);
    if (warrior.get_accuracy() != 60) {
        cout << "FAILED: Fighter set_accuracy" << endl;
        passed = false;
    }

    int accTest = warrior.get_accuracy();
    if (accTest != 60) {
        cout << "FAILED: Fighter get_accuracy" << endl;
        passed = false;
    }

    warrior.feed();
    if (warrior.get_hp() != 30 && warrior.get_attack().get_damage() != 80) {
        cout << "FAILED: Fighter feed" << endl;
        passed = false;
    }

    return passed;
}

bool attack_test() {
    bool passed = true;

    Attack hit;
    if (hit.get_damage() != 0) {
        cout << "FAILED: Attack damage not initialized to 0" << endl;
        passed = false;
    }

    hit.set_damage(50);
    if (hit.get_damage() != 50) {
        cout << "FAILED: Attack set_damage" << endl;
        passed = false;
    }

    int damageTest = hit.get_damage();
    if (damageTest != 50) {
        cout << "FAILED: Attack get_damage" << endl;
        passed = false;
    }

    hit.set_name("Name");
    if (hit.get_name() != "Name") {
        cout << "FAILED: Attack set_name" << endl;
        passed = false;
    }

    string nameTest = hit.get_name();
    if (nameTest != "Name") {
        cout << "FAILED: Attack get_name" << endl;
        passed = false;
    }

    hit.feed(20);
    if (hit.get_damage() != 70) {
        cout << "FAILED: Attack feed" << endl;
    }

    return passed;
}

bool java_test() {
    bool passed;
    Java jav;
    if (jav.get_hp() != 100 && jav.get_accuracy() != 60 && jav.get_attack().get_damage() != 60 && jav.get_attack().get_name() != "Constructor of doom") {
        cout << "FAILED: Java constructor" << endl;
        passed = false;
    }

    jav.special_ability();
    if (jav.get_hp() != 110 && jav.get_accuracy() != 70 && jav.get_attack().get_damage() != 70) {
        cout << "FAILED: Java special ability" << endl;
        passed = false;
    }

    return passed;
}

bool python_test() {
    bool passed = true;
    Python py;
    if (py.get_hp() != 100 && py.get_accuracy() != 65 && py.get_attack().get_damage() != 50 && py.get_attack().get_name() != "Constrict") {
        cout << "FAILED: Python constructor" << endl;
        passed = false;
    }

    py.special_ability();
    if (py.get_hp() != 120 && py.get_accuracy() != 55 && py.get_attack().get_damage() != 40) {
        cout << "FAILED: Python special ability" << endl;
        passed = false;
    }


    return passed;
}

bool c_test() {
    bool passed = true;
    C c;
    if (c.get_hp() != 100 && c.get_attack().get_damage() != 90 && c.get_accuracy() != 30 && c.get_attack().get_name() != "Data erase") {
        cout << "FAILED: C constructor" << endl;
        passed = false;
    }

    c.special_ability();
    if (c.get_hp() != 170 && c.get_accuracy() != 50) {
        cout << "FAILED: C special ability" << endl;
        passed = false;
    }


    return passed;
}

bool cpp_test() {
    bool passed = true;
    CDoubleP cpp;
    if (cpp.get_hp() != 100 && cpp.get_accuracy() != 45 && cpp.get_attack().get_damage() != 75 && cpp.get_shield() != false) {
        cout << "FAILED: C++ constructor" << endl;
        passed = false;
    }

    cpp.special_ability();
    if (cpp.get_shield() != true) {
        cout << "FAILED: C++ constructor" << endl;
        passed = false;
    }


    return passed;
}

