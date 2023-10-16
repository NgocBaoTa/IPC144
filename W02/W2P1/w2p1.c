/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Bao Ngoc Ta
Student ID#: 116038225
Email      : bta@myseneca.ca
Section    : E

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double smallPrice, mediumPrice, largePrice;
    int numOfShirt; 
    double subTotal;
    double taxes;
    double total;
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: \$");
    scanf("%lf", &smallPrice);
    printf("Enter the price for a MEDIUM shirt: \$");
    scanf("%lf", &mediumPrice); 
    printf("Enter the price for a LARGE shirt: \$");
    scanf("%lf", &largePrice);
    printf("\n");
    
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL   : \$%.2lf\n", smallPrice);
    printf("MEDIUM  : \$%.2lf\n", mediumPrice);
    printf("LARGE   : \$%.2lf\n", largePrice);
    printf("\n");

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numOfShirt);
    printf("\n");

    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numOfShirt);
    subTotal = smallPrice * numOfShirt;
    printf("Sub-total: \$%8.4lf\n", subTotal);
    taxes = subTotal * TAX;
    printf("Taxes    : \$%8.4lf\n", taxes);
    total = subTotal + taxes;
    printf("Total    : \$%8.4lf\n", total);

    return 0;
}