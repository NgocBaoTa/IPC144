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
#include "w7p2.h"

int main(void)
{
    struct PlayerInfo player;
    struct GameInfo game;

    int nextMove = 0;
    int numOfTreasure = 0;

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
            printf("    Value must be between %d and %d\n", player.lives, game.pathLength * 75 / 100);
        }
    } while (game.moves < player.lives || game.moves > game.pathLength * 75 / 100);
    printf("\n");


    printf("BOMB Placement\n");
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


    printf("TREASURE Placement\n");
    printf("------------------\n");

    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
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
    printf("====================================\n\n");

    int flag = 0;
    do {
        if (nextMove != 0) {
            printf("%*c\n", nextMove + 2, player.symbol);
        }

        int p;
        printf("  ");
        for (p = 0; p < game.pathLength; p++) {
            if (player.history[p] == 0) {
                printf("-");
            }
            else {
                if (game.bombs[p] == 1 && game.treasure[p] == 1) {
                    printf("&");
                }
                else if (game.bombs[p] == 0 && game.treasure[p] == 0) {
                    printf(".");
                }
                else if (game.bombs[p] == 0 && game.treasure[p] == 1) {
                    printf("$");
                }
                else {
                    printf("!");
                }
            }
        }
        printf("\n");

        int h;
        int tempRuler = 1;
        printf("  ");
        for (h = 1; h <= game.pathLength; h++) {
            if (h % 10 == 0) {
                printf("%d", tempRuler);
                tempRuler++;
            }
            else {
                printf("|");
            }
        }
        printf("\n");

        int q;
        tempRuler = 1;
        printf("  ");
        for (q = 0; q < game.pathLength; q++) {
            if (tempRuler <= 9) {
                printf("%d", tempRuler);
                tempRuler++;
            }
            else {
                tempRuler = 0;
                printf("%d", tempRuler);
                tempRuler++;
            }
        }
        printf("\n");

        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, numOfTreasure, game.moves);
        printf("+---------------------------------------------------+\n");

        if (player.lives != 0 && game.moves != 0) {
            do {
                printf("Next Move [1-%d]: ", game.pathLength);
                scanf("%d", &nextMove);
                if (nextMove < 1 || nextMove > game.pathLength) {
                    printf("  Out of Range!!!\n");
                }
                else if (player.history[nextMove - 1] == 0) {
                    game.moves--;
                }
            } while (nextMove < 1 || nextMove > game.pathLength);
            printf("\n");

            if (player.history[nextMove - 1] != 0) {
                printf("===============> Dope! You've been here before!\n\n");
            }
            else {
                player.history[nextMove - 1] = 1;
                if (game.bombs[nextMove - 1] == 1 && game.treasure[nextMove - 1] == 1) {
                    printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                    printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                    numOfTreasure++;
                    player.lives--;
                }
                else if (game.bombs[nextMove - 1] == 0 && game.treasure[nextMove - 1] == 0) {
                    printf("===============> [.] ...Nothing found here... [.]\n\n");
                }
                else if (game.bombs[nextMove - 1] == 0 && game.treasure[nextMove - 1] == 1) {
                    printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                    numOfTreasure++;
                }
                else {
                    printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                    player.lives--;
                }

                if (player.lives == 0) {
                    printf("No more LIVES remaining!\n\n");
                }
                else if (game.moves == 0) {
                    printf("No more MOVES remaining!\n\n");
                }
            }
        }
        else {
            flag = 1;
        }
    } while (player.lives >= 0 && game.moves >= 0 && flag == 0);
    printf("\n");

    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");

    return 0;
}