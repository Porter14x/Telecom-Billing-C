// telecom-billing-C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <string.h>

#define STRING_BUFFER 50
#define PHONE_NO_LENGTH 12
#define CUST_ARRAY_LENGTH 100

struct Customer {
    char name[STRING_BUFFER];
    char phoneNo[PHONE_NO_LENGTH];
    float usage;
    float totalBill;
};

struct Customer customers[CUST_ARRAY_LENGTH];

int customerTotal = 0;

void addRecord();
void viewRecords();
void modifyRecord(char phoneNo[]);
void viewPayments(char phoneNo[]);
void searchRecord(char phoneNo[]);
void deleteRecord(char phoneNo[]);
void displayOptions();

int main()
{
    int userChoice;
    char phoneNo[PHONE_NO_LENGTH];

    while (1) {
        displayOptions();
        printf("Please select an option: ");
        scanf_s("%d", &userChoice);

        switch (userChoice) {
        case 1:
            addRecord();
            break;
        case 2:
            viewRecords();
            break;
        case 3:
            printf("Please enter your phone number: ");
            scanf_s("%s", phoneNo, PHONE_NO_LENGTH);
            modifyRecord(phoneNo);
            break;
        case 4:
            printf("Please enter your phone number: ");
            scanf_s("%s", phoneNo, PHONE_NO_LENGTH);
            viewPayments(phoneNo);
            break;
        case 5:
            printf("Please enter your phone number: ");
            scanf_s("%s", phoneNo, PHONE_NO_LENGTH);
            searchRecord(phoneNo);
            break;
        case 6:
            printf("Please enter your phone number: ");
            scanf_s("%s", phoneNo, PHONE_NO_LENGTH);
            deleteRecord(phoneNo);
            break;
        case 7:
            printf("Exiting...\n");
            return 0;
            break;
        default:
            printf("Unrecognised command, please re-enter a correct input\n");
            break;
        }
    }
    
}

void displayOptions() {
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Modify Record\n");
    printf("4. View Payments\n");
    printf("5. Search For Record\n");
    printf("6. Delete Record\n");
    printf("7. Exit\n");
}

void addRecord() {
    if (customerTotal < CUST_ARRAY_LENGTH) {
        printf("Please enter your name: ");
        scanf_s("%s", (customers + customerTotal)->name, STRING_BUFFER);
        printf("Please enter your phone number: ");
        scanf_s("%s", (customers + customerTotal)->phoneNo, PHONE_NO_LENGTH);
        printf("Please enter your phone usage (up to the nearest minute): ");
        scanf_s("%f", &(customers + customerTotal)->usage);
        (customers + customerTotal)->totalBill = ((customers + customerTotal)->usage) * 0.1;
        customerTotal++;

        printf("Record added\n");

    }
    else {
        printf("Records are full\n");
    }
}

void viewRecords() {
    if (customerTotal > 0) {
        printf("----------\n");
        for (int i = 0; i < customerTotal; i++) {
            printf("%d. Name: %s, Phone No: %s, Usage: %f, Total Bill: %f\n",
                (i + 1), customers[i].name, customers[i].phoneNo, customers[i].usage, customers[i].totalBill);
        }
        printf("----------\n");
    }
    else {
        printf("There are no records to view\n");
    }
}

void modifyRecord(char phoneNo[]) {
    for (int i = 0; i < customerTotal; i++) {
        if (strcmp(phoneNo, (customers + i)->phoneNo) == 0) {
            printf("Please enter your new usage (to the nearest minute): ");
            scanf_s("%f", &(customers + i)->usage);
            (customers + i)->totalBill = (customers + i)->usage * 0.1;

            printf("Record modified successfully\n");
            return;
        }
    }
    printf("No record with %s has been found\n", phoneNo);
}

void viewPayments(char phoneNo[]) {
    for (int i = 0; i < customerTotal; i++) {
        if (strcmp(phoneNo, (customers + i)->phoneNo) == 0) {
            printf("Name: %s, Total Bill: %f", (customers + i)->name, (customers + i)->totalBill);
            return;
        }
    }
    printf("No record with %s has been found\n", phoneNo);
}

void searchRecord(char phoneNo[]) {
    for (int i = 0; i < customerTotal; i++) {
        if (strcmp(phoneNo, (customers + i)->phoneNo) == 0) {
            printf("Name: %s, Phone No: %s, Usage: %f, Total Bill: %f\n",
                 customers[i].name, customers[i].phoneNo, customers[i].usage, customers[i].totalBill);
            return;
        }
    }
    printf("No record with %s has been found\n", phoneNo);
}

void deleteRecord(char phoneNo[]) {
    for (int i = 0; i < customerTotal; i++) {
        if (strcmp(phoneNo, (customers + i)->phoneNo) == 0) {
            for (int j = i; j < customerTotal-1; j++) {
                customers[j] = customers[j + 1];
            }
            printf("Record deleted\n");
            customerTotal--;
            return;
        }
    }
    printf("No record with %s has been found\n", phoneNo);
}

