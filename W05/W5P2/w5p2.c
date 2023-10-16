/*/////////////////////////////////////////////////////////////////////////
                        Workshop - #5 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email 	   : bta@myseneca.ca
Section    : E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int year, month, day = 1;
    double morningVal = 0, eveningVal = 0, morningTotal = 0, eveningTotal = 0;

    printf("General Well-being Log\n");
    printf("======================\n");

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year > MAX_YEAR || year < MIN_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        };

        if (month > DEC || month < JAN) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
    } while (year > MAX_YEAR || year < MIN_YEAR || month > DEC || month < JAN);

    printf("\n");
    printf("*** Log date set! ***\n\n");

    for (; day <= LOG_DAYS; day++) {
        switch (month)
        {
        case 1:
            printf("Log starting date: %d-JAN-%02d\n", year, day);
            break;
        case 2:
            printf("Log starting date: %d-FEB-%02d\n", year, day);
            break;
        case 3:
            printf("Log starting date: %d-MAR-%02d\n", year, day);
            break;
        case 4:
            printf("Log starting date: %d-APR-%02d\n", year, day);
            break;
        case 5:
            printf("Log starting date: %d-MAY-%02d\n", year, day);
            break;
        case 6:
            printf("Log starting date: %d-JUN-%02d\n", year, day);
            break;
        case 7:
            printf("Log starting date: %d-JUL-%02d\n", year, day);
            break;
        case 8:
            printf("Log starting date: %d-AUG-%02d\n", year, day);
            break;
        case 9:
            printf("Log starting date: %d-SEP-%02d\n", year, day);
            break;
        case 10:
            printf("Log starting date: %d-OCT-%02d\n", year, day);
            break;
        case 11:
            printf("Log starting date: %d-NOV-%02d\n", year, day);
            break;
        case 12:
            printf("Log starting date: %d-DEC-%02d\n", year, day);
            break;
        default:
            printf("???");
        };

        do {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningVal);
            if (morningVal < 0.0 || morningVal > 5.0) {
                printf("  	ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else {
                morningTotal += morningVal;
            }
        } while (morningVal < 0.0 || morningVal > 5.0);

        do {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningVal);
            if (eveningVal < 0.0 || eveningVal > 5.0) {
                printf("  	ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            else {
                eveningTotal += eveningVal;
            }
        } while (eveningVal < 0.0 || eveningVal > 5.0);

        printf("\n");
        //day++;
    }

    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating:%7.3lf\n", morningTotal);
    printf("Evening total rating:%7.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating:%7.3lf\n\n", morningTotal + eveningTotal);

    printf("Average morning rating:%5.1lf\n", morningTotal / LOG_DAYS);
    printf("Average evening rating:%5.1lf\n", eveningTotal / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:%5.1lf\n\n", (morningTotal / LOG_DAYS + eveningTotal / LOG_DAYS) / 2);

    return 0;
}
