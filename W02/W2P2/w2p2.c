/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Bao Ngoc Ta
Student ID#: 
Email      :
Section    :

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    double smallPrice, mediumPrice, largePrice;
    int patNum, salNum, tomNum;

    double patSubTotal, salSubTotal, tomSubTotal;
    double patTax, salTax, tomTax;
    double patTotal, salTotal, tomTotal;

    double subTotal, tax, total;

    //******************************** SET SHIRT PRICES ******************************** 

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: \$");
    (void) scanf("%lf", &smallPrice);

    printf("Enter the price for a MEDIUM shirt: \$");
    (void) scanf("%lf", &mediumPrice);

    printf("Enter the price for a LARGE shirt: \$");
    (void) scanf("%lf", &largePrice);
    printf("\n");


    //********************************** PRICE LIST ************************************

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL   : \$%.2lf\n", smallPrice);
    printf("MEDIUM  : \$%.2lf\n", mediumPrice);
    printf("LARGE   : \$%.2lf\n", largePrice);
    printf("\n");


    //***************************** INPUT NUM OF BOUGHT SHIRTS **************************

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    (void) scanf("%d", &patNum);
    printf("\n");

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    (void) scanf("%d", &tomNum);
    printf("\n");

    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    (void) scanf("%d", &salNum);
    printf("\n");


    //*************************************** BILL ***************************************

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");

    int a, b;

    //------------- Patty ------------
    patSubTotal = smallPrice * patNum;
    patTax = patSubTotal * TAX;
    patTotal = patSubTotal + patTax;
    
    patTax += 0.005;
    patTax *= 100; 
    a = patTax; 

    patTotal += 0.005;
    patTotal *= 100;
    b = patTotal;
    patTax = (float)a / 100;
    patTotal = (float)b / 100;
    printf("Patty    %c    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf\n", patSize, smallPrice, patNum, patSubTotal, patTax, patTotal);

    //------------- Sally ------------
    
    salSubTotal = mediumPrice * salNum;
    salTax = salSubTotal * TAX;
    salTotal = salSubTotal + salTax;

    salTax += 0.005;
    salTax *= 100;
    a = salTax;

    salTotal += 0.005;
    salTotal *= 100;
    b = salTotal;

    salTax = (float)a / 100;
    salTotal = (float)b / 100;
    printf("Sally    %c    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf\n", salSize, mediumPrice, salNum, salSubTotal, salTax, salTotal);

    //------------- Tommy ------------
    tomSubTotal = largePrice * tomNum;
    tomTax = tomSubTotal * TAX;
    tomTotal = tomSubTotal + tomTax;

    tomTax += 0.005;
    tomTax *= 100;
    a = tomTax;

    tomTotal += 0.005;
    tomTotal *= 100;
    b = tomTotal;

    tomTax = (float)a / 100;
    tomTotal = (float)b / 100;

    printf("Tommy    %c    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf\n", tomSize, largePrice, tomNum, tomSubTotal, tomTax, tomTotal);

    //------------- Total ------------
    printf("-------- ---- ----- --- --------- --------- ---------\n");

    subTotal = patSubTotal + tomSubTotal + salSubTotal;
    tax = patTax + tomTax + salTax;
    total = patTotal + tomTotal + salTotal;
    printf("                         %8.4lf  %8.4lf  %8.4lf", subTotal, tax, total);
    printf("\n\n");
    

    //**************************** SALES REPRESENTED BY COINS *****************************

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    // Excluding tax

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %8.4lf\n", subTotal);

    int coin;
    float left;

    coin = subTotal / 2;
    left = subTotal - coin * 2;
    printf("Toonies  %d    %.4f\n", coin, left);

    coin = left / 1;
    left -= coin;
    printf("Loonies    %d    %.4f\n", coin, left);

    coin = left / 0.25;
    left -= coin * 0.25;
    printf("Quaters    %d    %.4f\n", coin, left);

    coin = left / 0.1;
    left -= coin * 0.1;
    printf("Dimes      %d    %.4f\n", coin, left);

    coin = left / 0.05;
    left -= coin * 0.05;
    printf("Nickels    %d    %.4f\n", coin, left);

    left += 0.00005;
    coin = left / 0.01;
    left -= coin * 0.01; 

    printf("Pennies    %d    %.4f\n\n", coin, left);

    printf("Average cost/shirt: \$%.4lf\n\n", subTotal / (tomNum + salNum + patNum));


    // Including tax

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %8.4lf\n", total);

    coin = total / 2;
    left = total - coin * 2;
    printf("Toonies  %d    %.4f\n", coin, left);

    coin = left / 1;
    left -= coin;
    printf("Loonies    %d    %.4f\n", coin, left);

    coin = left / 0.25;
    left -= coin * 0.25;
    printf("Quaters    %d    %.4f\n", coin, left);

    coin = left / 0.1;
    left -= coin * 0.1;
    printf("Dimes      %d    %.4f\n", coin, left);

    coin = left / 0.05;
    left -= coin * 0.05;
    printf("Nickels    %d    %.4f\n", coin, left);

    left += 0.00005;
    coin = left / 0.01;
    left -= coin * 0.01;
    printf("Pennies    %d    %.4f\n\n", coin, left);

    printf("Average cost/shirt: \$%.4lf\n", total / (tomNum + salNum + patNum));
    return 0;
}