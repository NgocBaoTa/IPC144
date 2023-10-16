/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
    double total = 0;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");

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
    
    printf("Best of luck in all your future endeavours!\n");
    return 0;
}