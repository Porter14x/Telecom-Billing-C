Telecom Billing system in C, project from GeeksForGeeks: https://www.geeksforgeeks.org/telecom-billing-system-in-c/

System holds an array of struct Customer (customers[]) where this struct holds char name[], char phoneNo[], float usage and float totalBill. The first 3 values are inputted in addRecords() and totalBill is calculated by
usage * 0.1. The size of customers[] is tracked by customerTotal which increments/deincrements whenever additon/delection occurs. The max size of customers[] has been set to 100.

addRecord():
Checks if the customers[] has space for a new record and then asks for the user to input theur name, phone no and usage and the totalBill is calculated; a confirmation message is displayed once done. 
If there is no space in customers[] (customerTotal==100) a message is displayed.

viewRecords():
prints out all records in customers[], if it's empty then a message is displayed.

modifyRecord(char phoneNo[]):
Matches the passed to phoneNo to the one present in customers[] and allows the user to input a new usage value, if the phoneNo is not matched a message is displayed.

viewPayments(char phoneNo[]):
Matches the passed to phoneNo to the one present in customers[] and displays the matched name and totalBill, if the phoneNo is not matched a message is displayed.

searchRecord(char phoneNo[]):
Matches the passed to phoneNo to the one present in customers[] and displays the full record, if the phoneNo is not matched a message is displayed.

deleteRecord(char phoneNo[]):
Matches the passed to phoneNo to the one present in customers[] and removes the full record from the array, if the phoneNo is not matched a message is displayed

void displayOptions():
Displays the options a user can input from 1-7.
