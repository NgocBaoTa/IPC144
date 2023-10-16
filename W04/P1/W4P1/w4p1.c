/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    char type = ' ';
    int num;
    int flag = 0;
    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &type, &num);
        if (type != 'D' && type != 'W' && type != 'F' && type != 'Q') {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
        else if (type == 'Q' && num == 0) {
            flag = 1;
        }
        else if (type == 'Q' && num != 0) {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }
        else if (num < 3 || num > 20) {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }
        else if (type == 'D') {
            printf("DO_WHILE: ");
            int i = 0;
            do {
                printf("D");
                i++;
            } while (i < num);
            printf("\n\n");
        }
        else if (type == 'W') {
            printf("WHILE   : ");
            int k = 0;
            while (k < num) {
                printf("W");
                k++;
            };
            printf("\n\n");
        }
        else if (type == 'F') {
            printf("FOR     : ");
            int j;
            for (j = 0; j < num; j++) {
                printf("F");
            };
            printf("\n\n");
        }
    } while (flag == 0);

    printf("\n");
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n\n");
    return 0;
}