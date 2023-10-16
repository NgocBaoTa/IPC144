/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>

#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

// Return an integer value 
int inputInt(void) {
    int value, flag = 0, check;
    char after;
    do {
        check = scanf("%d%c", &value, &after);
        if (check == 0 || after != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else {
            flag = 1;
        }
    } while (flag == 0);

    return value;
}


// Return a positive integer value 
int inputIntPositive(void) {
    int value, flag = 0;
    do {
        value = inputInt();
        if (value <= 0) {
            printf("ERROR! Value must be > 0: ");
        }
        else {
            flag = 1;
        }
    } while (flag == 0);

    return value;
}


// Return an integer value which is within the permitted range
int inputIntRange(int min, int max) {
    int value, flag = 0;
    do {
        value = inputInt();
        if (value < min || value > max) {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
        }
        else {
            flag = 1;
        }
    } while (flag == 0);

    return value;
}


// Return a single character value that match any of the characters in the received C string argument
char inputCharOption(const char validChars[]) {
    char value[10] = { 0 };
    int flag = 0, flag1 = 0;
    do {
        (void)scanf("%9s", value);
        clearInputBuffer();
        if (strlen(value) > 1) {
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }
        else {
            int i;

            for (i = 0; validChars[i] != '\0' && flag1 == 0; i++) {
                if (validChars[i] == value[0]) {
                    flag1 = 1;
                }
            }

            if (flag1 == 0) {
                printf("ERROR: Character must be one of [%s]: ", validChars);
            }
            else {
                flag = 1;
            }
        }
    } while (flag == 0);

    return value[0];
}


// Return a string (which has number of characters within the specified range) via pointer 
void inputCString(char* stringValue, int min, int max) {
    int flag = 0;
    char value[101] = { '\0' };
    do {
        scanf("%100[^\n]", value);
        clearInputBuffer();
        int length = strlen(value);

        if (min == max) {
            if (length != min) {
                printf("Invalid 10-digit number! Number: ");
            }
            else {
                flag = 1;
            }
        }
        else if (length > max) {
            printf("ERROR: String length must be no more than %d chars: ", max);
        }
        else if (length < min) {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }
        else {
            flag = 1;
        }
    } while (flag == 0);

    strcpy(stringValue, value);
}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////


// Display an array of 10-character digits as a formatted phone number
void displayFormattedPhone(const char *phoneNum) {

    int i, length = 0, flag = 0;
    if (!phoneNum) {
        flag = 1;
    }

    for (i = 0; i < 10 && flag == 0; i++) {
        length++;
        if (phoneNum[i] < '0' || phoneNum[i] > '9' || phoneNum[i] == '\0' ||
            (length == 10 && phoneNum[i + 1] != '\0')) {
            flag = 1;
        }
    }

    if (flag == 0 && length == 10) {
        printf("(%c%c%c)%c%c%c-%c%c%c%c",
            phoneNum[0], phoneNum[1], phoneNum[2], phoneNum[3], phoneNum[4],
            phoneNum[5], phoneNum[6], phoneNum[7], phoneNum[8], phoneNum[9]);
    }
    else {
        printf("(___)___-____");
    }
}