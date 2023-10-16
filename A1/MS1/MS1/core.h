#pragma once
#pragma once
/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  :
Student ID#:
Email      :
Section    :
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// Return an integer value 
int inputInt(void);

// Return a positive integer value 
int inputIntPositive(void);

// Return an integer value which is within the permitted range
int inputIntRange(int min, int max);

// Return a single character value that match any of the characters in the received C string argument
char inputCharOption(const char validChars[]);

// Return a string (which has number of characters within the specified range) via pointer 
void inputCString(char* string, int min, int max);

// Display an array of 10-character digits as a formatted phone number
void displayFormattedPhone(const char* phoneNum);
