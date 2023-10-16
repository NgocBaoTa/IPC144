/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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

// User-Defined Libraries

#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* pounds, double* resultKg) {
    double result = 0;

    if (resultKg != NULL) {
        *resultKg = *pounds / LBS_TO_KG;
    }
    result = *pounds / LBS_TO_KG;

    return result;
}


// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* pounds, int* resultGram) {
    double resultKg;
    double result = 0;
    resultKg = convertLbsKg(pounds, NULL);

    if (resultGram != NULL) {
        *resultGram = resultKg * 1000;
    }
    result = resultKg * 1000;

    return result;
}

// 10. convert lbs: kg and g

void convertLbs(const double* pounds, double* resultKg, int* resultGram) {
    *resultKg = convertLbsKg(pounds, NULL);
    *resultGram = convertLbsG(pounds, NULL);
}

// 11. calculate: servings based on gPerServ

double calculateServings(const int servingSizeG, const int totalGrams, double* numOfServings) {
    double resultServings;
    if (numOfServings != NULL) {
        *numOfServings = (double)totalGrams / (double)servingSizeG;
    }

    resultServings = (double)totalGrams / (double)servingSizeG;

    return resultServings;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double* price, const double* numOfServings, double* costPerServing) {
    double resultCost;
    if (costPerServing != NULL) {
        *costPerServing = *price / *numOfServings;
    }

    resultCost = *price / *numOfServings;
  
    return resultCost;
}


// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, const double* numOfCalories, double* costPerCalorie) {
    double resultCost;
    if (costPerCalorie != NULL) {
        *costPerCalorie = *price / *numOfCalories;
    }

    resultCost = *price / *numOfCalories;

    return resultCost;
}

// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo info) {
    struct ReportData data;
    data.sku = info.sku;
    data.price = info.price;
    data.calories = info.calories;
    data.weightLbs = info.weight;
    data.weightKg = convertLbsKg(&data.weightLbs, NULL);
    data.weightGram = convertLbsG(&data.weightLbs, NULL);
    data.totalServings = calculateServings(SUGGESTED_SERVING_GRAMS, data.weightGram, NULL);
    data.costPerServing = calculateCostPerServing(&data.price, &data.totalServings, NULL);
    double totalOfCalories = data.calories * data.totalServings;
    data.costCalories = calculateCostPerCal(&data.price, &totalOfCalories, NULL);

    return data;
}

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SUGGESTED_SERVING_GRAMS );
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(const struct ReportData data, const int cheapestProductSku) {
        if (data.sku != cheapestProductSku) {
            printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf\n", data.sku, data.price,
                data.weightLbs, data.weightKg, data.weightGram, data.calories, data.totalServings,
                data.costPerServing, data.costCalories);
        }
        else {
            printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf ***\n", data.sku, data.price,
                data.weightLbs, data.weightKg, data.weightGram, data.calories, data.totalServings,
                data.costPerServing, data.costCalories);
        }
}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const struct CatFoodInfo infoCheapest) {
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%.2lf\n\n", infoCheapest.sku, infoCheapest.price);
    printf("Happy shopping!\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void) {
    int i;
    struct CatFoodInfo info[MAX_PRODUCT];
    struct ReportData data[MAX_PRODUCT];

    openingMessage(MAX_PRODUCT);

    for (i = 0; i < MAX_PRODUCT; i++) {
        info[i] = getCatFoodInfo(i + 1);
    }

    displayCatFoodHeader();

    for (i = 0; i < MAX_PRODUCT; i++) {
        displayCatFoodData(info[i].sku, &info[i].price, info[i].calories, &info[i].weight);
        data[i] = calculateReportData(info[i]);
    }
    printf("\n");

    int cheapestProductSku = 0;
    int cheapestProduct = 0;
    for (i = 0; i < MAX_PRODUCT; i++) {
        if (data[i].costPerServing < data[cheapestProduct].costPerServing) {
            cheapestProductSku = data[i].sku;
            cheapestProduct = i;
        }
    }

    displayReportHeader();
    for (i = 0; i < MAX_PRODUCT; i++) {
        displayReportData(data[i], cheapestProductSku);
    }
    printf("\n");

    displayFinalAnalysis(info[cheapestProduct]);
}