#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 100

int main()
{
    char username[50];
    char password[50];
    char name[MAX_STUDENTS][50];
    char trade[MAX_STUDENTS][50];
    char id1[MAX_STUDENTS][50];
    int numStudents = 0;

    // Register NFC card
    printf("Student card registration\n");

    // Register all students
    while (numStudents < MAX_STUDENTS) {
        printf("Student %d\n", numStudents + 1);
        printf("Name: ");
        scanf("%s", name[numStudents]);
        printf("Student ID: ");
        scanf("%s", id1[numStudents]);
        printf("Trade: ");
        scanf("%s", trade[numStudents]);

        numStudents++;

        char choice;
        printf("Do you want to register another student? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // set username and password
    char correctUsername[] = "admin";
    char correctPassword[] = "admin123";

    printf("\nWelcome to the Login Page\n\n");

    // input login info
    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    // Check if the entered username and password match
    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        printf("Login successful!\n");

        // Student tap NFC card
    int card_number;
    while (1) {
        printf("\nPlease tap your card (1-%d) or enter 0 to exit: ", numStudents);


        if (scanf("%d", &card_number) != 1) {

            printf("Invalid input. Please enter a valid card number.\n");


            while (getchar() != '\n');

            continue;  // Ask the same question again
        }

        if (card_number == 0) {
            break;
        } else if (card_number >= 1 && card_number <= numStudents) {
            printf("Name: %s\n", name[card_number - 1]);
            printf("Student ID: %s\n", id1[card_number - 1]);
            printf("Trade: %s\n", trade[card_number - 1]);
        } else {
            printf("Invalid card. Please try again.\n");
        }
    }
    } else {
        printf("Login failed. Please check your credentials.\n");
    }

    return 0;
}
