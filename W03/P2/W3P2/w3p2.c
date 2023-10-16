/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char type1, type2, type3;
    int weight1, weight2, weight3;
    char cream1, cream2, cream3;

    char userType;
    char userCream;
    int userNum;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    /* ************************************COFFEE INFORMATION********************************************* */

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type1);
    printf("Bag weight (g): ");
    scanf(" %d", &weight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type2);
    printf("Bag weight (g): ");
    scanf(" %d", &weight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &type3);
    printf("Bag weight (g): ");
    scanf(" %d", &weight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("\n");


    printf("---+------------------------+---------------+-------+\n");
    printf("   |     Coffee             |   Packaged    | Best  |\n");
    printf("   |      Type              |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) |  Lbs   | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", type1 == 'l' || type1 == 'L', type1 == 'm' || type1 == 'M', type1 == 'r' || type1 == 'R', weight1, weight1 / GRAMS_IN_LBS, cream1 == 'y' || cream1 == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", type2 == 'l' || type2 == 'L', type2 == 'm' || type2 == 'M', type2 == 'r' || type2 == 'R', weight2, weight2 / GRAMS_IN_LBS, cream2 == 'y' || cream1 == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", type3 == 'l' || type3 == 'L', type3 == 'm' || type3 == 'M', type3 == 'r' || type3 == 'R', weight3, weight3 / GRAMS_IN_LBS, cream3 == 'y' || cream1 == 'Y');

    printf("\n");


    /* ****************************************CUSTOMER PREFERENCE******************************************/

    printf("Enter how you like your coffee and the coffe maker equipment you use...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich: ");
    scanf(" %c", &userType);
    printf("Do you like your coffee with cream ([Y]es, [N]o: ");
    scanf(" %c", &userCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &userNum);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", userType == type1 || userType == type1 + 32 || userType == type1 - 32, (userNum <= 4 && userNum >= 1 && weight1 == 250) || (userNum <= 9 && userNum >= 5 && weight1 == 500) || (userNum >= 10 && weight1 == 1000), userCream == cream1 || userCream == cream1 + 32 || userCream == cream1 - 32);
    printf(" 2|       %d         |      %d      |   %d   |\n", userType == type2 || userType == type2 + 32 || userType == type2 - 32, (userNum <= 4 && userNum >= 1 && weight2 == 250) || (userNum <= 9 && userNum >= 5 && weight2 == 500) || (userNum >= 10 && weight2 == 1000), userCream == cream2 || userCream == cream2 + 32 || userCream == cream2 - 32);
    printf(" 3|       %d         |      %d      |   %d   |\n", userType == type3 || userType == type3 + 32 || userType == type3 - 32, (userNum <= 4 && userNum >= 1 && weight3 == 250) || (userNum <= 9 && userNum >= 5 && weight3 == 500) || (userNum >= 10 && weight3 == 1000), userCream == cream3 || userCream == cream3 + 32 || userCream == cream3 - 32);
   

    printf("\n");


    printf("Enter how you like your coffee and the coffe maker equipment you use...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich: ");
    scanf(" %c", &userType);
    printf("Do you like your coffee with cream ([Y]es, [N]o: ");
    scanf(" %c", &userCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &userNum);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", userType == type1 || userType == type1 + 32 || userType == type1 - 32, (userNum <= 4 && userNum >= 1 && weight1 == 250) || (userNum <= 9 && userNum >= 5 && weight1 == 500) || (userNum >= 10 && weight1 == 1000), userCream == cream1 || userCream == cream1 + 32 || userCream == cream1 - 32);
    printf(" 2|       %d         |      %d      |   %d   |\n", userType == type2 || userType == type2 + 32 || userType == type2 - 32, (userNum <= 4 && userNum >= 1 && weight2 == 250) || (userNum <= 9 && userNum >= 5 && weight2 == 500) || (userNum >= 10 && weight2 == 1000), userCream == cream2 || userCream == cream2 + 32 || userCream == cream2 - 32);
    printf(" 3|       %d         |      %d      |   %d   |\n", userType == type3 || userType == type3 + 32 || userType == type3 - 32, (userNum <= 4 && userNum >= 1 && weight3 == 250) || (userNum <= 9 && userNum >= 5 && weight3 == 500) || (userNum >= 10 && weight3 == 1000), userCream == cream3 || userCream == cream3 + 32 || userCream == cream3 - 32);
    
    printf("\n");
    printf("Hope you found a product that suits your likes!\n");
    
    return 0;
}


