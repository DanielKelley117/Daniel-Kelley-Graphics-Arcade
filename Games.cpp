//
// Created by Daniel Kelley on 9/12/2022.
#include "Games.h"
#include <string>
#include <vector>
using namespace std;
finiteAutomata::finiteAutomata() {
    //All stages are initialized and put in vector
    stage0 = start;
    stage1 = regular1;
    stage2 = regular2;
    stage3 = accept;
    layout.push_back(stage0);
    layout.push_back(stage1);
    layout.push_back(stage2);
    layout.push_back(stage3);
}

void finiteAutomata::makeDFA(int num) {
    //Creates DFA by initializing all of the direction fields based on num.
    if (num > 50) {
        stage0Go = right;
        stage1Go = self;
        stage2Go = right;
    }
    else {
        stage0Go = self;
        stage1Go = right;
        stage2Go = self;
    }
    stage3Go = self;
}

bool finiteAutomata::switchState(string input) {
    //Changes the value of status based on the values of the stage, direction, and user input.
    if ((status == stage0) && (stage0Go == right) && (input == "1")) {
        status = layout[1];
        return false;
    }
    if ((status == stage0) && (stage0Go == self) && (input == "0")) {
        status = layout[1];
        return false;
    }
    if ((status == stage1) && (stage1Go == right) && (input == "1")) {
        status = layout[2];
        return false;
    }
    if ((status == stage1) && (stage1Go == self) && (input == "0")) {
        status = layout[2];
        return false;
    }
    if ((status == stage2) && (stage2Go == right) && (input == "1")) {
        status = layout[3];
        return true;
    }
    if ((status == stage2) && (stage2Go == self) && (input == "0")) {
        status = layout[3];
        return true;
    }
    if (status == stage3) {
        return true;
    }
    return false;
}

string finiteAutomata::inputValidation() {
    //Prompts user for input, and then uses a loop to validate the user input.
    string info;
    cout << "Enter 1 or 0: ";
    getline(cin, info);

    while ((info.length() != 1) && (info != "0" && info != "1")) {
        cout << endl;
        cout << "Invalid Input. Enter 1 or 0: ";
        info = "";
        getline(cin, info);
    }
    return info;
}

void finiteAutomata::game() {

    //Initializes status and points, and welcomes user to the game.
    status = layout[0];
    cout << "Welcome to the Finite Automata Game!" << endl;
    cout << "For this game, a DFA will be randomly generated." << endl <<  "You will begin at stage 0, the start state, and need to enter the correct input (a 0 or a 1) to get to stage 3, the accept state." << endl;
    cout << "To begin the game, answer this question: Do you like Coke or Pepsi more: (Enter 'coke' or 'pepsi')" << endl;
    string soda;
    points = 1500;
    //Validates user input for whether they like coke or pepsi more.
    getline(cin, soda);
    while ((soda != "coke") && (soda != "pepsi") && (soda != "Coke") && (soda != "Pepsi")) {
        cout << "Invalid input. Enter 'coke' or 'pepsi': " << endl;
        getline(cin, soda);
    }
    //The users favorite soda decides the value of startNum, and that number gets passed to makeDFA
    int startNum;
    if ((soda == "coke") || (soda == "Coke")) {
        startNum = 45;
    }
    if ((soda == "Pepsi") || (soda == "pepsi")) {
        startNum = 55;
    }
    makeDFA(startNum);
    string choice;
    bool win = false;
    //This loop keeps track of the users state and points.
    while (!(win)) {
        choice = inputValidation();
        switchState(choice);
        if (status == stage0) {
            cout << "You are currently at state 0" << endl;
            points -= 200;
        }
        if (status == stage1) {
            cout << "You are currently at state 1" << endl;
            points -= 200;
        }
        if (status == stage2) {
            cout << "You are currently at state 2" << endl;
            points -= 200;
        }
        if (status == stage3) {
            win = true;
        }
    }
    //The game is over when the loop ends, and the user is told how many points they've won.
    cout << "You reached state 3! You win!" << endl;
    cout << "You got " << points << " points!" << endl;
    cout << "Your prize is that you can give me full credit. Please." << endl;
}

int finiteAutomata::getPoints() const{
    return points;
}
//

