#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234, enteredPin, attempts = 0;
    float balance = 1000.0;
    int choice;
    float amount;

    printf("Welcome to the ATM Machine\n");

    // PIN verification
    while (attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);
        if (enteredPin == pin) {
            break;
        } else {
            printf("Incorrect PIN. Try again.\n");
            attempts++;
        }
    }
    if (attempts == 3) {
        printf("Too many incorrect attempts. Exiting...\n");
        return 0;
    }

    do {
        printf("\nATM Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposited $%.2f. New balance: $%.2f\n", amount, balance);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;
            case 3:
                printf("Enter amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Withdrawn $%.2f. New balance: $%.2f\n", amount, balance);
                } else {
                    printf("Invalid or insufficient funds.\n");
                }
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}