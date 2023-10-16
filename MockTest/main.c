#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 4
struct Tire {
    char tireSide[3];
    double pressure;
};
struct Vehicle {
    char brand[21];
    char model[21];
    double engineCap;
    struct Tire trs[4];
};

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // do nothing
    }
}

void setTireData(struct Tire tires[]) {
    for (int i = 0; i < 4; i++) {
        printf("Tire %d\n", i + 1);
        printf("\tEnter location : ");
        scanf(" %2s", tires[i].tireSide);
        clearInputBuffer();
        printf("\tEnter pressure : ");
        scanf("%lf", &tires[i].pressure);
        clearInputBuffer();
    }
}

void setData(struct Vehicle* veh) {
    printf("Enter brand: ");
    scanf(" %20[^\n]", veh->brand);
    clearInputBuffer();
    printf("Enter model: ");
    scanf(" %20[^\n]", veh->model);
    clearInputBuffer();
    printf("Enter engine capacity: ");
    scanf("%lf", &veh->engineCap);
    clearInputBuffer();
    setTireData(veh->trs);
}

void displayData(const struct Vehicle* veh) {
    printf("Brand : %s\n", veh->brand);
    printf("Model : %s\n", veh->model);
    printf("Engine capacity : %.2lf\n", veh->engineCap);
    for (int i = 0; i < 4; i++) {
        printf("Tire %s – Pressure: %0.2lf\n", veh->trs[i].tireSide,
            veh->trs[i].pressure);
    }
    printf("\n");
}

void findVehiclesByBrand(const struct Vehicle veh[]) {
    char brand[21];
    printf("Enter the brand : ");
    scanf(" %20[^\n]", brand);
    clearInputBuffer();
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(veh[i].brand, brand) == 0) {
            displayData(&veh[i]);
        }
    }
}

void findVehiclesByEngineCap(const struct Vehicle veh[]) {
    double engineCap;
    printf("Enter the engine capacity : ");
    scanf("%lf", &engineCap);
    clearInputBuffer();
    for (int i = 0; i < SIZE; i++) {
        if (veh[i].engineCap == engineCap) {
            displayData(&veh[i]);
        }
    }
}

void sortVehByEngineCap(struct Vehicle veh[]) {
    struct Vehicle temp;
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (veh[j].engineCap > veh[j + 1].engineCap) {
                temp = veh[j];
                veh[j] = veh[j + 1];
                veh[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        
            displayData(&veh[i]);
        
    }
}

int main() {
    struct Vehicle veh[SIZE] = { {0} };
    for (int i = 0; i < SIZE; i++) {
        printf("Vehicle %d\n", i + 1);
        setData(&veh[i]);
    }
    int selection;
    do {
        printf("MENU : 1. Find Vehicles by Brand\n"
            "2. Find Vehicles by Engine Cap\n"
            "3. Sort Vehicles by Engine Capacity\n"
            "4. Quiz the program\n");
        printf("Selection : ");
        scanf("%d", &selection);
        clearInputBuffer();
        printf("\n");
        switch (selection) {
        case 0:
            break;
        case 1:
            findVehiclesByBrand(veh);
            break;
        case 2:
            findVehiclesByEngineCap(veh);
            break;
        case 3:
            sortVehByEngineCap(veh);
            break;
        default:
            printf("In range 0 - 4\n");
        }
    } while (selection);

    return 0;
}
