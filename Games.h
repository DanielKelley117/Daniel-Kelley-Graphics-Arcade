//
// Created by Daniel Kelley on 9/9/2022.
//

#ifndef M1OEP_DKELLEY3_GAMES_H
#define M1OEP_DKELLEY3_GAMES_H
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using std::string, std::vector;
class finiteAutomata {
private:
    //Fields are initialized. There are 2 enumerated typed for stages and directions of the DFA, and a vector of stages.
    enum stage{start, regular1, regular2, accept};
    enum direction{right, self};
    stage stage0;
    stage stage1;
    stage stage2;
    stage stage3;
    stage status;
    direction stage0Go;
    direction stage1Go;
    direction stage2Go;
    direction stage3Go;
    vector<stage> layout;
    int points;
    /*I did not have time to write this method.
     * It would have a void return type and no parameters
     * This method would be accessed through a cheat code, and would allow the user to make their own DFA
     */
    void creatorDFA();

public:
    /*The finiteAutomata constructor
     * No parameters
     * Initializes all fields, except for status
     */
    finiteAutomata();

    /*Makes a DFA for the game. Can make 2 DFAs based on the value of num
     * Paramaters: int num
     * Returns: void
     */
    void makeDFA(int num);

    /*Moves the user to the next state depending on whether input is a 0 or a 1
     * Paramaters: string input
     * Returns: true if the player is at stage 3, false if not
     */
    bool switchState(string input);

    /*This method takes in user input and validates whether or not it's 1 or 0
     * Paramaters: none
     * Returns: A string of the validated user input
     */
    string inputValidation();

    /*This method contains the code that runs the entire game.
     * It has user interaction, and uses all of the above methods.
     * points and status are initialized and kept track of here
     * Parameters: none
     * Returns: void
     */
    void game();

    /*This is a getter for points
     * Parameters: none
     * Returns: the int field points
     */
    int getPoints() const;




};

#endif //M1OEP_DKELLEY3_GAMES_H
