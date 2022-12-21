//
// Created by Daniel Kelley on 9/9/2022.
//
#include <iostream>
#include <string>
#include "Games.h"
#include "Python.h"
#include "Java.h"
#include "C.h"
#include "CDoubleP.h"

using namespace std;

int program_fight();

int get_int_from_user();
int main() {

    //The finiteAutomata object is initialized
    finiteAutomata fun;
    string name;
    //string closer = "cd ../";
    string weirdChessCompile = "javac WeirdChess.java Pawn.java Rook.java Knight.java Bishop.java Queen.java";
    string weirdChessCommand = "java WeirdChess.java";

    //The user is welcomed to the arcade, and variables are initialized.
    cout << "Welcome to Daniel Kelley's Arcade!" << endl;
    cout << "What is your name?" << endl;
    getline(cin, name);
    cout << "Welcome " << name << "!" << endl;
    string choice = "";
    int points = 0;
    //As long as the user doesn't quit, they're kept in the game.
    while ((choice != "q") && (choice != "Q")) {
        cout << "Here is our game selection: Automata, Programming Rumble, Four Corners, Graphics Corner" << endl;
        cout << "You currently have " << points << " points." << endl;
        cout << "Enter the name of the game you would like to play (or q if you want to quit): " << endl;
        getline(cin, choice);
        //User input is validated
        while ((choice != "automata") && (choice != "Automata") && (choice != "q") && (choice != "Q") && choice != "Programming Rumble" && choice != "programming rumble" && choice != "Programming rumble" && choice != "Four corners" && choice != "Four Corners" && choice != "four corners" && choice != "Graphics Corner" && choice != "Graphics corner" && choice != "graphics corner") {
            cout << "Invalid input. Please enter the name of one of the games above, or q to quit: " << endl;
            getline(cin, choice);
        }

        if ((choice == "Automata") || (choice == "automata")) {
            fun.game();
            points += fun.getPoints();
        }

        if (choice == "Programming Rumble" || choice == "programming rumble" || choice == "Programming rumble") {
            points += program_fight();
        }

        if (choice == "Four Corners" || choice == "Four corners" || choice == "four corners") {
            cout << "Here are the rules for Four Corners:" << endl;
            cout << "Play this game in a group of whatever size you want." << endl;
            cout << "You need to be in a room with four corners, and there are 10 rounds." << endl;
            cout << "Designate each corner numbers 1-4." << endl;
            cout << "Each round you will have a certain amount of time to either go to anew corner, or stay at your current one." << endl;
            cout << "At the end of each round, the computer will randomly choose a corner, and everyone in the corner will be eliminated." << endl;
            cout <<"How many seconds do you want each round to last for?" << endl;
            string seconds;
            getline(cin, seconds);
            string fourCornersCommand = "py ../FourCorners.py " + seconds;
            system( fourCornersCommand.c_str());
            points += 200;
        }


        if (choice == "Graphics Corner" || choice == "Graphics corner" || choice == "graphics corner") {

            string cloudCommand = " graphics.exe";
            system(cloudCommand.c_str());


            cout << "How many points did you get?" << endl;
             points += get_int_from_user();



        }

    }

    cout << "What file would you like to save your points to?" << endl;
    string save;
    getline(cin, save);
    string here = "../";
    here += save;
    ofstream record;
    record.open(here);
    record << name << endl << points << " Points";
    record.close();



    return 0;
}

int program_fight() {

    //Characters are initialized
    int points;
    Python py;
    CDoubleP cpp;
    Java jav;
    C c;
    unique_ptr<Fighter> player;
    unique_ptr<Fighter> comp;
    py.set_hp(Fighter::STARTING_HP);
    cpp.set_hp(Fighter::STARTING_HP);
    jav.set_hp(Fighter::STARTING_HP);
    c.set_hp(Fighter::STARTING_HP);

    //The user is welcomed to the game and introduced to the characters
    cout << "Welcome to Programming Rumble!" << endl;

    cout << "Here are the characters and their stats: " << endl;

    cout << "Python:" << endl << "Attack: " << py.get_attack().get_damage() << " Accuracy: " << py.get_accuracy() << endl;
    cout << "Java:" << endl << "Attack: " << jav.get_attack().get_damage() << " Accuracy: " << jav.get_accuracy() << endl;
    cout << "C:" << endl << "Attack: " << c.get_attack().get_damage() << " Accuracy: " << c.get_accuracy() << endl;
    cout << "C++:" << endl << "Attack: " << cpp.get_attack().get_damage() << " Accuracy: " << cpp.get_accuracy() << endl;

    //The user chooses their character
    cout << "Choose your character: ";
    string choice;
    getline(cin, choice);
    while (choice != "Python" && choice != "python" && choice != "java" && choice != "Java" && choice != "c" && choice != "C" && choice != "C++" && choice != "c++") {
        cout << endl << "That is not a character. Choose your character: ";
        getline(cin, choice);
    }

    if (choice == "python" || choice == "Python") {
        player = make_unique<Python>(py);
    }
    if (choice == "java" || choice == "Java") {
        player = make_unique<Java>(jav);
    }
    if (choice == "C" || choice == "c") {
        player = make_unique<C>(c);
    }
    if (choice == "C++" || choice == "c++") {
        player = make_unique<CDoubleP>(cpp);
    }

    //The user chooses their opponent
    cout << "Who do you want your opponent to be: ";
    string decision;
    getline(cin, decision);
    while (decision != "Python" && decision != "python" && decision != "java" && decision != "Java" && decision != "c" && decision != "C" && decision != "C++" && decision != "c++") {
        cout << endl << "That is not a character. Choose a character: ";
        getline(cin, decision);
    }

    if (decision == "python" || decision == "Python") {
        comp = make_unique<Python>(py);
    }
    if (decision == "java" || decision == "Java") {
        comp = make_unique<Java>(jav);
    }
    if (decision == "C" || decision == "c") {
        comp = make_unique<C>(c);
    }
    if (decision == "C++" || decision == "c++") {
        comp = make_unique<CDoubleP>(cpp);
    }

    string action;
    int player_attack;
    int comp_attack;
    int player_acc;
    int comp_acc;
    bool special = true;
    //This loop is where the fight begins
    cout << "Let the fight begin!!" << endl;
    while (player->get_hp() > 0 && comp->get_hp() > 0) {
        cout << "You have " << player->get_hp() << " hp." << endl;
        cout << "Your opponent has " << comp->get_hp() << " hp." << endl;
        cout << "What would you like to do (attack, feed, special ability): " << endl;
        getline(cin, action);

        //Input validation for before the special ability is used
        while (action != "Attack" && action != "attack" && action != "feed" && action != "Feed" && action != "special ability" && action != "Special ability" && action != "Special Ability" && special) {
            cout << "That is not a valid option. What would you like to do (attack, feed, special ability): " << endl;
            getline(cin, action);
        }

        //Input validation for after the special ability is used
        while (action != "Attack" && action != "attack" && action != "feed" && action != "Feed" && !special) {
            if (action == "Special Ability" || action == "special ability" || action == "Special ability") {
                cout << "You can only use your special ability once! ";
            }
            cout << "That is not a valid option. What would you like to do (attack, feed, special ability): " << endl;
            getline(cin, action);
        }


        //User attacks
        if (action == "attack" || action == "Attack") {
            player_acc = rand() % 100;
            if (player_acc < player->get_accuracy()) {
                cout << "You used " << player->get_attack().get_name() << endl;
                comp->set_hp(comp->get_hp() - (rand() % player->get_attack().get_damage() + (player->get_attack().get_damage() - 40)));
                if (comp->get_hp() > 0) {
                    cout << "Your opponent now has " << comp->get_hp() << " hp." << endl;
                }

            }
            else {
                cout << "Your attack missed!" << endl;
            }
        }

        //User uses special ability
        if ((action == "special ability" || action == "Special Ability" || action == "Special ability")) {
            player->special_ability();
            cout << "You used your special ability. You now have " << player->get_hp() << " hp, " << player->get_accuracy() << " accuracy, and " << player->get_attack().get_damage() << " attack." << endl;
            special = false;
        }


        //User feeds
        if (action == "feed" || action == "Feed") {
            player->feed();
            cout << "You now have " << player->get_hp() << " hp, and " << player->get_attack().get_damage() << " attack." << endl;
        }

        //Computer attacks
        comp_acc = rand() % 100;
        if ((comp_acc < comp->get_accuracy() && comp->get_accuracy() > 0) && (!cpp.get_shield())) {
            cout << "Your opponent used " << comp->get_attack().get_name() << endl;
            player->set_hp(player->get_hp() - (rand() % comp->get_attack().get_damage() + (comp->get_attack().get_damage() - 40)));
        }
        else {
            cout << "Your opponent missed their attack!" << endl;
        }


    }

    //Results are displayed to the user
    if (player->get_hp() > 0 && comp->get_hp() <= 0) {
        cout << "You win! You have " << player->get_hp() << " hp, your opponent has 0 hp." << endl;
        cout << "You get 700 points!" << endl;
        return 700;
    }

    if (player->get_hp() <= 0 && comp->get_hp() > 0) {
        cout << "You lose. You have 0 hp, your opponent has " << comp->get_hp() << " hp." << endl;
        cout << "You get 0 points." << endl;
        return 0;
    }

    if (player->get_hp() <= 0 && comp->get_hp() <= 0) {
        cout << "It's a tie! You both have 0 hp." << endl;
        cout << "You get 400 points!" << endl;
        return 400;
    }


    return 0;

}

int get_int_from_user() {
    int num;
    stringstream ss;
    int i;
    bool isNum = false;
    string info;
    cout << "Enter an integer: ";
    while (!(isNum) || info == "") {
        getline(cin, info);
        cout << endl;
        i = 0;


        if (info != "") {
            isNum = true;
        }
        while (((i < info.length()) && isNum)) {
            if (!(isdigit(info[i]))) {
                isNum = false;
            }
            ++i;
        }
        if (!(isNum)) {
            cout << "Invalid Input. Enter an integer: " << endl;
            info = "";
        }
    }

    ss << info;
    ss >> num;



    return num;
}
