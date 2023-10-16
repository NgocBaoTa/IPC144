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


// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}


// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void) {
    int value, flag = 0, check;
    char after;
    do {
        check = scanf("%d%c", &value, &after);
        if (check == 0) {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (after != "\n") {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else {
            flag = 1;
        }
    } while (flag == 0);

    return value;
}