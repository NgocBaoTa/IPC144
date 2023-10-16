/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Bao Ngoc Ta        
Student ID#: 116038225
Email      : bta@myseneca.ca
Section    : E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int id1 = 111, id2 = 222, id3 = 111;
    const double price1 = 111.49, price2 = 222.99, price3 = 334.49;
    const char taxed1 = 'Y', taxed2 = 'N', taxed3 = 'N';
    double avgPrice;

    /* ******************PRODUCT INFORMATION****************** */

    printf("Product Information\n");
    printf("===================\n");


    printf("Product-1 (ID:%d)\n", id1);
    printf("  Taxed: %c\n", taxed1);
    printf("  Price: $%.4lf\n\n", price1);

    printf("Product-2 (ID:%d)\n", id2);
    printf("  Taxed: %c\n", taxed2);
    printf("  Price: $%.4lf\n\n", price2);

    printf("Product-3 (ID:%d)\n", id3);
    printf("  Taxed: %c\n", taxed3);
    printf("  Price: $%.4lf\n\n", price3);

    avgPrice = (price1 + price2 + price3) / 3;
    printf("The average of all prices is: $%.4lf\n\n", avgPrice);
     

    /* **************RELATIONAL and LOGICAL EXPRESSIONS************** */

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE: is represented by any integer value other than 0\n\n");


    /* ************************DATA ANALYSIS************************ */

    printf("Some Data Analysis...\n");
    printf("=====================\n");

    printf("1. Is product 1 taxable? -> %d\n\n", taxed1 == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (taxed2 == 'N' && taxed3 == 'N'));
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, price3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", price3 > (price1 + price2));
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? -> %d (price difference: $%.2lf)\n\n", price1 >= (price3 - price2), price3 - price2);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", price2 >= avgPrice);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", id1 != id2 && id1 != id3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", id2 != id1 && id2 != id3);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", id3 != id2 && id3 != id1);

    return 0;
}