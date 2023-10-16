/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Bao Ngoc Ta    
Student ID#: 116038225
Email      : bta@myseneca.ca    
Section    : E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int apple = 0, orange = 0, pear = 0, tomato = 0, cabbage = 0;
    int picked;
    int temp;
    do {
        printf("Grocery Shopping\n");
        printf("================\n");
        do {
            printf("How many APPLES do you need? : ");
            scanf(" %d", &apple);
            if (apple < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apple < 0);
        printf("\n");

        do {
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &orange);
            if (orange < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (orange < 0);
        printf("\n");

        do {
            printf("How many PEARS do you need? : ");
            scanf(" %d", &pear);
            if (pear < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pear < 0);
        printf("\n");

        do {
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &tomato);
            if (tomato < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tomato < 0);
        printf("\n");

        do {
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &cabbage);
            if (cabbage < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabbage < 0);
        printf("\n");

        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

       
            while (apple > 0) {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d", &temp);
                if (temp <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (temp > apple) {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apple);
                }
                else if (temp < apple) {
                    apple -= temp;
                    if (apple > 0) {
                        printf("Looks like we still need some APPLES...\n");
                    }
                }
                else if (temp == apple) {
                    apple = 0;
                    printf("Great, that's the apples done!\n\n");
                }
            };
            
        
            while (orange > 0) {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &temp);
                if (temp <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (temp > orange) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", orange);
                }
                else if (temp < orange) {
                    orange -= temp;
                    if (orange > 0) {
                        printf("Looks like we still need some ORANGES...\n");
                    }
                }
                else if (temp == orange) {
                    orange = 0;
                    printf("Great, that's the oranges done!\n\n");
                }
            };


            while (pear > 0) {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &temp);
                if (temp <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (temp > pear) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pear);
                }
                else if (temp < pear) {
                    pear -= temp;
                    if (pear > 0) {
                        printf("Looks like we still need some PEARS...\n");
                    }
                }
                else if (temp == pear) {
                    pear = 0;
                    printf("Great, that's the pears done!\n\n");
                }
            };


            while (tomato > 0) {
                printf("Pick some TOMATOS... how many did you pick? : ");
                scanf("%d", &temp);
                if (temp <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (temp > tomato) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomato);
                }
                else if (temp < tomato) {
                    tomato -= temp;
                    if (tomato > 0) {
                        printf("Looks like we still need some TOMATOES...\n");
                    }
                }
                else if (temp == tomato) {
                    tomato = 0;
                    printf("Great, that's the tomatos done!\n\n");
                }
            };


            while (cabbage > 0) {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &temp);
                if (temp <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (temp > cabbage) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbage);
                }
                else if (temp < cabbage) {
                    cabbage -= temp;
                    if (cabbage > 0) {
                        printf("Looks like we still need some CABBAGES...\n");
                    }
                }
                else if (temp == cabbage) {
                    printf("Great, that's the cabbages done!\n\n");
                    cabbage = 0;
                }
            };

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &picked);
        printf("\n");
    } while (picked != 0);

    printf("Your tasks are done for today - enjoy your free time!");
    printf("\n");
    return 0;
}
