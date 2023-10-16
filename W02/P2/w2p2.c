/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
#include <math.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    double smallPrice, mediumPrice, largePrice;
    int patNum, salNum, tomNum;

    double patSubTotal, salSubTotal, tomSubTotal;
    double patTax, salTax, tomTax;
    double patTotal, salTotal, tomTotal;

    double subTotal, taxes, total;

    //******************************** SET SHIRT PRICES ******************************** 

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    (void)scanf("%lf", &smallPrice);

    printf("Enter the price for a MEDIUM shirt: $");
    (void)scanf("%lf", &mediumPrice);

    printf("Enter the price for a LARGE shirt: $");
    (void)scanf("%lf", &largePrice);
    printf("\n");

    //********************************** PRICE LIST ************************************

    printf("Shirt Store Price List\n");
    printf("======================\n");

    printf("SMALL  : $%.2lf\n", smallPrice);
    printf("MEDIUM : $%.2lf\n", mediumPrice);
    printf("LARGE  : $%.2lf\n\n", largePrice);


    //***************************** INPUT NUM OF BOUGHT SHIRTS **************************

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    (void)scanf("%d", &patNum);
    printf("\n");

    printf("Tommyy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    (void)scanf("%d", &tomNum);
    printf("\n");

    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    (void)scanf("%d", &salNum);
    printf("\n");


    //*************************************** BILL ***************************************

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");

    int subE, taxE, totalE;

    //------------- Patty ------------

    patSubTotal = smallPrice * patNum;
    patTax = patSubTotal * TAX;
    patTotal = patSubTotal + patTax;

    subE = (patSubTotal + 0.005) * 100;
    taxE = (patTax + 0.005) * 100;
    totalE = (patTotal + 0.005) * 100;

    patSubTotal = subE / 100.0;
    patTax = taxE / 100.0;
    patTotal = totalE / 100.0;

    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallPrice, patNum, patSubTotal, patTax, patTotal);


    //------------- Sally ------------

    salSubTotal = mediumPrice * salNum;
    salTax = salSubTotal * TAX;
    salTotal = salSubTotal + salTax;

    subE = (salSubTotal + 0.005) * 100;
    taxE = (salTax + 0.005) * 100;
    totalE = (salTotal + 0.005) * 100;

    salSubTotal = subE / 100.0;
    salTax = taxE / 100.0;
    salTotal = totalE / 100.0;

    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumPrice, salNum, salSubTotal, salTax, salTotal);


    //------------- Tommy ------------

    tomSubTotal = largePrice * tomNum;
    tomTax = tomSubTotal * TAX;
    tomTotal = tomSubTotal + tomTax;

    subE = (tomSubTotal + 0.005) * 100;
    taxE = (tomTax + 0.005) * 100;
    totalE = (tomTotal + 0.005) * 100;

    tomSubTotal = subE / 100.0;
    tomTax = taxE / 100.0;
    tomTotal = totalE / 100.0;

    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largePrice, tomNum, tomSubTotal, tomTax, tomTotal);

    //------------- Total ------------

    printf("-------- ---- ----- --- --------- --------- ---------\n");

    subTotal = patSubTotal + tomSubTotal + salSubTotal;
    taxes = patTax + tomTax + salTax;
    total = patTotal + tomTotal + salTotal;

    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotal, taxes, total);


    //**************************** SALES REPRESENTED BY COINS *****************************

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    int coin, leftOver, costMod;

    // Excluding tax

    printf("Sale EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subTotal);

    costMod = subTotal * 100;
    coin = costMod / 200;
    leftOver = costMod % 200;
    printf("Toonies %4d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 100;
    leftOver -= coin * 100;
    printf("Loonies %4d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 25;
    leftOver -= coin * 25;
    printf("Quarters %3d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 10;
    leftOver -= coin * 10;
    printf("Dimes %6d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 5;
    leftOver -= coin * 5;
    printf("Nickels %4d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 1;
    leftOver -= coin * 1;
    printf("Pennies %4d %9.4lf\n\n", coin, leftOver / 100.0);

    printf("Average cost/shirt: $%.4lf\n\n", subTotal / (tomNum + salNum + patNum));


    // Including tax

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", total);

    costMod = subTotal * 100;
    coin = costMod / 200;
    leftOver = costMod % 200;
    printf("Toonies %4d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 100;
    leftOver -= coin * 100;
    printf("Loonies %4d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 25;
    leftOver -= coin * 25;
    printf("Quarters %3d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 10;
    leftOver -= coin * 10;
    printf("Dimes %6d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 5;
    leftOver -= coin * 5;
    printf("Nickels %4d %9.4lf\n", coin, leftOver / 100.0);

    coin = leftOver / 1;
    leftOver -= coin * 1;
    printf("Pennies %4d %9.4lf\n\n", coin, leftOver / 100.0);

    printf("Average cost/shirt: $%.4lf\n\n", total / (tomNum + salNum + patNum));

    return 0;
}