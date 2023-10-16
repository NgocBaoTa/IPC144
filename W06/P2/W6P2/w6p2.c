/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
#define MAX_ITEM 10

int main(void)
{
    const double MAX = 400000.00;
    const double MIN = 500.00;
    const double minValueItem = 100.00;

    double costArr[MAX_ITEM];
    int priorityArr[MAX_ITEM];
    char financeArr[MAX_ITEM];

    double netIncome;
    int numOfItem;
    double itemCost;
    int itemPriority;
    char itemFinance;
    
    int month, year;
    int selection;
    double total = 0;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < MIN) {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN);
        }
        else if (netIncome > MAX) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX);
        }

    } while (netIncome < MIN || netIncome > MAX);
    printf("\n");

    do {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numOfItem);
        if (numOfItem < 1 || numOfItem > MAX_ITEM) {
            printf("ERROR: List is restricted to between 1 and %d items.\n\n", MAX_ITEM);
        }
    } while (numOfItem < 1 || numOfItem > MAX_ITEM);
    printf("\n");

    int i;
    for (i = 0; i < numOfItem; i++) {
        printf("Item-%d Details:\n", i + 1);
        do {
            printf("   Item cost: $");
            scanf("%lf", &itemCost);
            if (itemCost < minValueItem) {
                printf("      ERROR: Cost must be at least $%.2lf\n", minValueItem);
            }
        } while (itemCost < minValueItem);
        costArr[i] = itemCost;

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority);
            if (itemPriority < 1 || itemPriority > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (itemPriority < 1 || itemPriority > 3);
        priorityArr[i] = itemPriority;

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinance);
            if (itemFinance != 'n' && itemFinance != 'y') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (itemFinance != 'n' && itemFinance != 'y');
        financeArr[i] = itemFinance;
        printf("\n");
    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    int j;
    for (j = 0; j < numOfItem; j++) {
        printf("%3d %6d %8c %14.2lf\n", j + 1, priorityArr[j], financeArr[j], costArr[j]);
    }
    printf("---- -------- -------- -----------\n");
    int k;
    for (k = 0; k < numOfItem; k++) {
        total += costArr[k];
    }
    printf("                      $%11.2lf\n\n", total);



    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");
        if (selection > 2 || selection < 0) {
            printf("ERROR: Invalid menu selection.\n\n");
        }

        if (selection == 1) {
            int flag = 0;
            double temp;
            year = (total / netIncome) / 12;
            temp = total / netIncome;
            month = total / netIncome - year * 12;
            if (year * 12 + month < temp) {
                month++;
            };

            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", total);
            printf("Forecast: %d years, %d months\n", year, month);
            int n;
            for (n = 0; n < numOfItem && flag == 0; n++) {
                if (financeArr[n] == 'y') {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                    flag = 1;
                }
            }
            printf("====================================================\n\n");
        }
        else if (selection == 2) {
            int priority;
            double temp;
            double totalPrio = 0;
            int flag = 0;
            do {
                printf("What priority do you want to filter by? [1-3]: ");
                scanf("%d", &priority);
                if (priority < 1 || priority > 3) {
                    printf("      ERROR: Value must be between 1 and 3\n");
                }
            } while (priority < 1 || priority > 3);

            int m;
            for (m = 0; m < numOfItem; m++) {
                if (priorityArr[m] == priority) {
                    totalPrio += costArr[m];

                    if (financeArr[m] == 'y') {
                        flag = 1;
                    }
                }
            }
            year = (totalPrio / netIncome) / 12;
            temp = totalPrio / netIncome;
            month = totalPrio / netIncome - year * 12;
            if (year * 12 + month < temp) {
                month++;
            };
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priority);
            printf("Amount:   $%.2lf\n", totalPrio);
            printf("Forecast: %d years, %d months\n", year, month);
            if (flag == 1) {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n\n");
        }

    } while (selection != 0);
    printf("\n");
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
