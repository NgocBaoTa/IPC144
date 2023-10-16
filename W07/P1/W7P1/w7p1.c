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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "w7p1.h"

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.lives);
        if (player.lives < 1 || player.lives > MAX_LIVES) {
            printf("     Must be between 1 and %d!\n", MAX_LIVES);
        }
    } while (player.lives < 1 || player.lives > MAX_LIVES);

    int i;
    for (i = 0; i < MAX_PATH_LENGTH; i++) {
        player.history[i] = 0;
    }

    printf("Player configuration set-up is complete\n\n");


    printf("GAME Configuration\n");
    printf("------------------\n");

    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);

        if (game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH || game.pathLength % MULTIPLE != 0) {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    } while (game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH || game.pathLength % MULTIPLE != 0);
    
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.moves);
        if (game.moves < player.lives || game.moves > game.pathLength * 75 / 100) {
            printf("     Value must be between %d and %d\n", player.lives, game.pathLength * 75 / 100);
        }
    } while (game.moves < player.lives || game.moves > game.pathLength * 75 / 100);
    printf("\n");


    printf("BOMB placement\n");
    printf("--------------\n");

    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    int j;
    int tempBomb = 0;
    for (j = 0; j < (game.pathLength / MULTIPLE); j++) {
        printf("   Positions [%2d-%2d]: ", tempBomb + 1, tempBomb + MULTIPLE);
        int k;
        for (k = 0; k < MULTIPLE; k++) {
            scanf("%d", &game.bombs[tempBomb]);
            tempBomb++;
        }
    }
    printf("BOMB placement set\n\n");


    printf("TREASURE placement\n");
    printf("------------------\n");

    printf("Enter the treasure positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    int m;
    int tempTreasure = 0;
    for (m = 0; m < (game.pathLength / MULTIPLE); m++) {
        printf("   Positions [%2d-%2d]: ", tempTreasure + 1, tempTreasure + MULTIPLE);
        int k;
        for (k = 0; k < MULTIPLE; k++) {
            scanf("%d", &game.treasure[tempTreasure]);
            tempTreasure++;
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    int k;
    for (k = 0; k < game.pathLength; k++) {
        printf("%d", game.bombs[k]);
    }
    printf("\n");
    printf("   Treasure   : ");
    int n;
    for (n = 0; n < game.pathLength; n++) {
        printf("%d", game.treasure[n]);
    }
    printf("\n\n");


    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    return 0;
}