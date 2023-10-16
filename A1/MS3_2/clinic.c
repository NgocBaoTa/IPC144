/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>


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
        selection = inputIntRange(0, 2);
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
    int index;
    index = findPatientIndexByPatientNum(0, patient, max);

    if (index == -1) {
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
    value = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(value, patient, max);
    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");

        char validate = ' ';
        printf("Are you sure you want to remove this patient record? (y/n): ");
        validate = inputCharOption("yn");
        if (validate == 'n') {
            printf("Operation aborted.\n\n");
        }
        else if (validate == 'y') {
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
    int j, i = 0, flag = 0;

    displayScheduleTableHeader(&data->appointments->date, 1);
    while (i < data->maxAppointments) {
        flag = 0;
        if (data->appointments[i].patientNumber > 0) {
            for (j = 0; j < data->maxPatient && flag == 0; j++) {
                if (data->patients[j].patientNumber == data->appointments[i].patientNumber) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                    flag = 1;
                }
            }
        }
        i++;
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:

void viewAppointmentSchedule(struct ClinicData* data) {
    struct Date date;
    int year = 0, month = 0, day = 0;
    printf("Year        : ");
    year = inputIntPositive();
    printf("Month (1-12): ");
    month = inputIntRange(1, 12);
    if (year % 4 == 0 && month == 2) {
        printf("Day (1-29)  : ");
        day = inputIntRange(1, 29);
    }
    else if (month == 2) {
        printf("Day (1-28)  : ");
        day = inputIntRange(1, 28);
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
    }
    else {
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
    }

    date.year = year;
    date.month = month;
    date.day = day;
    printf("\n");

    int j, i, flag = 0;

    displayScheduleTableHeader(&date, 0);

    for (i = 0; i < data->maxAppointments; i++) {
        flag = 0;
        if (data->appointments[i].date.day == day && data->appointments[i].date.month == month &&
            data->appointments[i].date.year == year) {
            for (j = 0; j < data->maxPatient && flag == 0; j++) {
                if (data->patients[j].patientNumber == data->appointments[i].patientNumber) {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    flag = 1;
                }
            }

        }
    }

    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:

void addAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatients) {
    int patientNum, year, month, day, hour, min;
    int i, j, flag = 0, index = 0, isExist = -1;
    struct Appointment temp;

    for (i = 0; i < maxAppointments && flag == 0; i++) {
        if (appointments[i].patientNumber < 1) {
            index = i;
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("No available appoitment slot!!!\n\n");
    }
    else {
        printf("Patient Number: ");
        patientNum = inputIntPositive();
        isExist = findPatientIndexByPatientNum(patientNum, patients, maxPatients);
        if (isExist == -1) {
            printf("Please add patient to book appointment!!!\n\n");
        }
        else {
            int pass = 0;
            do {
                flag = 0;
                printf("Year        : ");
                year = inputIntPositive();
                printf("Month (1-12): ");
                month = inputIntRange(1, 12);
                if (year % 4 == 0 && month == 2) {
                    printf("Day (1-29)  : ");
                    day = inputIntRange(1, 29);
                }
                else if (month == 2) {
                    printf("Day (1-28)  : ");
                    day = inputIntRange(1, 28);
                }
                else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
                    month == 10 || month == 12) {
                    printf("Day (1-31)  : ");
                    day = inputIntRange(1, 31);
                }
                else {
                    printf("Day (1-30)  : ");
                    day = inputIntRange(1, 30);
                }
                printf("Hour (0-23)  : ");
                hour = inputIntRange(0, 23);
                printf("Minute (0-59): ");
                min = inputIntRange(0, 59);

                for (i = 0; i < maxAppointments && flag == 0; i++) {
                    if (appointments[i].date.year == year && appointments[i].date.month == month &&
                        appointments[i].date.day == day) {
                        if (appointments[i].patientNumber == patientNum) {
                            printf("ERROR: nN double booking or overlap is allowed\n\n");
                            flag = 1;
                        }
                        if (appointments[i].time.hour == hour && appointments[i].time.min == min) {
                            printf("\n");
                            printf("ERROR: Appointment timeslot is not available!\n\n");
                            flag = 1;
                        }
                    }
                }

                if (flag == 0) {
                    int exit = 0;
                    do {
                        if (hour < START_HOUR || hour > END_HOUR || (hour == END_HOUR && min > END_MIN) ||
                            (hour == START_HOUR && min < START_MIN) || (min % INTERVAL != 0)) {
                            printf("ERROR: Time must be between %02d:%02d and %02d:%02d in %d minute intervals.\n\n",
                                START_HOUR, START_MIN, END_HOUR, END_MIN, INTERVAL);
                            printf("Hour (0-23)  : ");
                            hour = inputIntRange(0, 23);
                            printf("Minute (0-59): ");
                            min = inputIntRange(0, 59);
                        }
                        else {
                            printf("\n*** Appointment scheduled! ***\n\n");
                            appointments[index].patientNumber = patientNum;
                            appointments[index].date.year = year;
                            appointments[index].date.month = month;
                            appointments[index].date.day = day;
                            appointments[index].time.hour = hour;
                            appointments[index].time.min = min;
                            exit = 1;
                            flag = 1;
                            pass = 1;
                        }
                    } while (exit == 0);
                }
            } while (pass == 0);
        }
    }

    if (flag == 1 && isExist != -1) {
        for (i = index; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (appointments[j].date.year > appointments[j + 1].date.year ||
                    (appointments[j].date.year == appointments[j + 1].date.year &&
                        appointments[j].date.month > appointments[j + 1].date.month) ||
                    (appointments[j].date.year == appointments[j + 1].date.year &&
                        appointments[j].date.month == appointments[j + 1].date.month &&
                        appointments[j].date.day > appointments[j + 1].date.day) ||
                    (appointments[j].date.year == appointments[j + 1].date.year &&
                        appointments[j].date.month == appointments[j + 1].date.month &&
                        appointments[j].date.day == appointments[j + 1].date.day &&
                        appointments[j].time.hour > appointments[j + 1].time.hour) ||
                    (appointments[j].date.year == appointments[j + 1].date.year &&
                        appointments[j].date.month == appointments[j + 1].date.month &&
                        appointments[j].date.day == appointments[j + 1].date.day &&
                        appointments[j].time.hour == appointments[j + 1].time.hour &&
                        appointments[j].time.min > appointments[j + 1].time.min))
                {
                    temp = appointments[j];
                    appointments[j] = appointments[j + 1];
                    appointments[j + 1] = temp;
                }
            }
        }
    }
}

// Remove an appointment record from the appointment array
// Todo:

void removeAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatients) {
    int patientNum, year, month, day, index, id;
    int i, flag1 = 0, flag2 = 0;
    printf("Patient Number: ");
    patientNum = inputIntPositive();
    for (i = 0; i < maxAppointments && flag1 == 0; i++) {
        if (appointments[i].patientNumber == patientNum) {
            if (flag2 == 0) {
                printf("Year        : ");
                year = inputIntPositive();
                printf("Month (1-12): ");
                month = inputIntRange(1, 12);
                if (year % 4 == 0 && month == 2) {
                    printf("Day (1-29)  : ");
                    day = inputIntRange(1, 29);
                }
                else if (month == 2) {
                    printf("Day (1-28)  : ");
                    day = inputIntRange(1, 28);
                }
                else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
                    month == 10 || month == 12) {
                    printf("Day (1-31)  : ");
                    day = inputIntRange(1, 31);
                }
                else {
                    printf("Day (1-30)  : ");
                    day = inputIntRange(1, 30);
                }
            }
            if (appointments[i].date.day == day && appointments[i].date.month == month &&
                appointments[i].date.year == year) {
                index = i;
                flag1 = 1;
            }
            else {
                flag2 = 1;
            }
        }
    }

    if (flag1 == 0) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        printf("\n");
        id = findPatientIndexByPatientNum(patientNum, patients, maxPatients);
        printf("Name  : %s\n", patients[id].name);
        printf("Number: %05d\n", patientNum);
        printf("Phone : ");
        displayFormattedPhone(patients[id].phone.number);
        printf(" (%s)\n", patients[id].phone.description);
        printf("Are you sure you want to remove this appointment (y,n): ");

        if (inputCharOption("yn") == 'y') {
            //for (i = index; i < maxAppointments; i++) {
            //    appointments[i] = appointments[i + 1];
            //}
            appointments[index] = (struct Appointment){ 0 };
            printf("\n");
            printf("Appointment record has been removed!\n\n");
        }
        else {
            printf("Operation aborted.\n\n");
        }
    }
}

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
    inputCString(value, 10, 10);
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
    inputCString(patient->name, 0, 15);
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
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        strcpy(phone->number, "");
        break;
    }

    if (selection < 4) {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        printf("\n");
    }
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:

int importPatients(const char* datafile, struct Patient patients[], int max) {
    FILE* fptr = NULL;
    int count = 0;
    fptr = fopen(datafile, "r");
    if (fptr != NULL) {
        while (count < max && fscanf(fptr, "%d|%[^|]|%[^|]|%[^\n]", &patients[count].patientNumber,
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
    FILE* fptr = NULL;
    int count = 0;
    fptr = fopen(datafile, "r");
    if (fptr != NULL) {
        while (count < max&& fscanf(fptr, "%d,%d,%d,%d,%d,%d", &appoints[count].patientNumber,
            &appoints[count].date.year, &appoints[count].date.month, &appoints[count].date.day,
            &appoints[count].time.hour, &appoints[count].time.min) != EOF) {
            count++;
        }

        fclose(fptr);
    }
    else {
        printf("Open File Error!!!\n");
    }

    int i, j;
    struct Appointment temp;

    for (i = count - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (appoints[j].date.year > appoints[j + 1].date.year ||
                (appoints[j].date.year == appoints[j + 1].date.year &&
                    appoints[j].date.month > appoints[j + 1].date.month) ||
                (appoints[j].date.year == appoints[j + 1].date.year &&
                    appoints[j].date.month == appoints[j + 1].date.month &&
                    appoints[j].date.day > appoints[j + 1].date.day) ||
                (appoints[j].date.year == appoints[j + 1].date.year &&
                    appoints[j].date.month == appoints[j + 1].date.month &&
                    appoints[j].date.day == appoints[j + 1].date.day &&
                    appoints[j].time.hour > appoints[j + 1].time.hour) ||
                (appoints[j].date.year == appoints[j + 1].date.year &&
                    appoints[j].date.month == appoints[j + 1].date.month &&
                    appoints[j].date.day == appoints[j + 1].date.day &&
                    appoints[j].time.hour == appoints[j + 1].time.hour &&
                    appoints[j].time.min > appoints[j + 1].time.min))
            {
                temp = appoints[j];
                appoints[j] = appoints[j + 1];
                appoints[j + 1] = temp;
            }
        }
    }

    return count;
}