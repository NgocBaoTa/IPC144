/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :
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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)

void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int cnt = 0, i;
    if (fmt == FMT_TABLE) {
        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            cnt++;
        }
    }
    if (cnt == 0) {
        printf("*** No records found ***\n");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)

void searchPatientData(const struct Patient patient[], int max) {
    int selection;
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &selection);
        printf("\n");
        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (selection);
}


// Add a new patient record to the patient array
// (Copy your code from MS#2)

void addPatient(struct Patient patient[], int max) {
    int flag = 0, index, i;
    for (i = 0; i < max && flag == 0; i++) {
        if (patient[i].patientNumber == 0) {
            flag = 1;
            index = i;
        }
    }

    if (flag == 0) {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)

void editPatient(struct Patient patient[], int max) {
    int value;
    printf("Enter the patient number: ");
    value = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(value, patient, max);
    if (index == -1) {
        printf("ERROR: Patient record not found!\n");
    }
    else {
        menuPatientEdit(&patient[index]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)

void removePatient(struct Patient patient[], int max) {
    int value;
    printf("Enter the patient number: ");
    //scanf("%d", &value);
    value = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(value, patient, max);
    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");

        char validate;
        printf("Are you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &validate);
        clearInputBuffer();
        if (validate == 'n' || validate == 'N') {
            printf("Operation aborted.\n\n");
        }
        else if (validate == 'y' || validate == 'Y') {
            strcpy(patient[index].name, "");
            patient[index].patientNumber = 0;
            strcpy(patient[index].phone.number, "");
            strcpy(patient[index].phone.description, "");
            printf("Patient record has been removed!\n\n");
        }
    }
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:

void viewAllAppointments(struct ClinicData* data) {
    int i;
    displayScheduleTableHeader(data->appointments.date, 1);
    for (i = 0; i < data->maxAppointments; i++) {
        displayScheduleData(data->patients, data->appointments, 1);
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:


// Add an appointment record to the appointment array
// Todo:


// Remove an appointment record from the appointment array
// Todo:


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)

void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int value;
    printf("Search by patient number: ");
    value = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(value, patient, max);
    if (index == -1) {
        printf("*** No records found ***\n\n");
    }
    else {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)

void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int cnt = 0, i;
    char value[PHONE_LEN + 1];
    printf("Search by phone number: ");
    scanf("%s", value);
    clearInputBuffer();
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (strcmp(value, patient[i].phone.number) == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            cnt++;
        }
    }

    if (cnt == 0) {
        printf("\n");
        printf("*** No records found ***\n");
    }

    printf("\n");
}

// Get the next highest patient number
// (Copy your code from MS#2)

int nextPatientNumber(const struct Patient patient[], int max) {
    int maxNumber = 0, i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > maxNumber) {
            maxNumber = patient[i].patientNumber;
        }
    }
    maxNumber += 1;
    return maxNumber;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }
    return -1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)

void inputPatient(struct Patient* patient) {
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    scanf("%[^\n]", patient->name);
    printf("\n");
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)

void inputPhoneData(struct Phone* phone) {
    int selection;
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n2. Home\n3. Work\n4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    printf("\n");
    switch (selection) {
    case 1:
        strcpy(phone->description, "CELL");
        printf("Contact: CELL\n");
        printf("Number : ");
        scanf("%10s", phone->number);
        printf("\n");
        clearInputBuffer();
        break;
    case 2:
        strcpy(phone->description, "HOME");
        printf("Contact: HOME\n");
        printf("Number : ");
        scanf("%10s", phone->number);
        printf("\n");
        clearInputBuffer();
        break;
    case 3:
        strcpy(phone->description, "WORK");
        printf("Contact: WORK\n");
        printf("Number : ");
        scanf("%10s", phone->number);
        printf("\n");
        clearInputBuffer();
        break;
    case 4:
        strcpy(phone->description, "TBD");
        strcpy(phone->number, "");
        break;
    }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:

int importPatients(const char* datafile, struct Patient patients[], int max) {
    FILE* fptr;
    int count = 0;
    fopen("patientData.txt", "r");
    if (fptr != NULL) {
        while (count < max && fscanf(fptr, "%d|%[^|]|%[^|]|%[^\n]", patients[count].patientNumber,
            patients[count].name, patients[count].phone.description, patients[count].phone.number) != EOF) {
            count++;
        }
        fclose(fptr);
    }
    else {
        printf("Open File Error!!!\n");
    }
    return count;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:

int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    FILE* fptr;
    int count = 0;
    fopen("appointmentData.txt", "r");
    if (fptr != NULL) {
        while (count < max && fscanf(fptr, "%d,%d,%d,%d,%d,%d", appoints[count].patient.patientNumber,
            appoints[count].date.year, appoints[count].date.month, appoints[count].date.day, 
            appoints[count].time.hour, appoints[count].time.min) != EOF) {
            count++;
        }
        fclose(fptr);
    }
    else {
        printf("Open File Error!!!\n");
    }
    return count;
}