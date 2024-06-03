#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phoneBook[contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", phoneBook[contactCount].phone);

    contactCount++;
    printf("Contact added successfully!\n");
}

void searchContact() {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Contact found: %s - %s\n", phoneBook[i].name, phoneBook[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void displayMenu() {
    printf("-----------------------\n");
    printf("Phone Book Menu:\n");
    printf("-----------------------\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Exit\n");
    printf("-----------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                printf("Exiting the phone book.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
