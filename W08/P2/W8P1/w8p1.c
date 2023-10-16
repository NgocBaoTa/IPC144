/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #8 (P1)
Full Name  : Bao Ngoc ta
Student ID#: 116038225
Email      : bta@myseneca.ca    
Section    : E
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS


// System Libraries

#include <stdio.h>

// User Libraries

#include "w8p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)



int getIntPositive(int* intValuePtr) {
    int input;
    do {
        scanf("%d", &input);
        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            if (intValuePtr != NULL) {
                *intValuePtr = input;
            }
            //result = input;
        }
    } while (input <= 0);

    return input;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* doubleValuePtr) {
    double input;
    do {
        scanf("%lf", &input);
        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else {
            if (doubleValuePtr != NULL) {
                *doubleValuePtr = input;
            }
            //result = input;
        }
    } while (input <= 0);

    return input;
}


// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int numOfProduct) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", numOfProduct);
    printf("NOTE: A 'serving' is %dg\n\n", SUGGESTED_SERVING_GRAMS);
}

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int proSequenceNum) {
    struct CatFoodInfo info;
    printf("Cat Food Product #%d\n", proSequenceNum);
    printf("--------------------\n");
    printf("SKU           : ");
    getIntPositive(&info.sku);
    printf("PRICE         : $");
    getDoublePositive(&info.price);
    printf("WEIGHT (LBS)  : ");
    getDoublePositive(&info.weight);
    printf("CALORIES/SERV.: ");
    getIntPositive(&info.calories);
    printf("\n");

    return info;
}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight) {
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
}

// 7. Logic entry point

void start(void) {
    struct CatFoodInfo info[MAX_PRODUCT];

    openingMessage(MAX_PRODUCT);

    int i;
    for (i = 0; i < MAX_PRODUCT; i++) {
        info[i] = getCatFoodInfo(i + 1);
    }

    displayCatFoodHeader();

    int j;
    for (j = 0; j < MAX_PRODUCT; j++) {
        displayCatFoodData(info[j].sku, &info[j].price, info[j].calories, &info[j].weight);
    }
}