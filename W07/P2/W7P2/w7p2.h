
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Section    : E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#pragma once
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MULTIPLE 5
#define MAX_LIVES 10

struct PlayerInfo {
    char symbol;
    int lives;
    int treasures;
    int history[MAX_PATH_LENGTH];
};

struct GameInfo {
    int pathLength;
    int moves;
    int bombs[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
};