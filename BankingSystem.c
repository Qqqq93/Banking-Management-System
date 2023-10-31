#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account information
struct Account {
    int accountNumber;
    char name[50];
    double balance;
};

// Function to create a new account
void createAccount(struct Account accounts[], int *numAccounts) {
    if (*numAccounts < 100) {
        struct Account newAccount;
        newAccount.accountNumber = *numAccounts + 1;

        printf("Enter account holder's name: ");
        scanf("%s", newAccount.name);

        printf("Enter initial balance: ");
        scanf("%lf", &newAccount.balance);

        accounts[*numAccounts] = newAccount;
        (*numAccounts)++;
        printf("Account created successfully.\n");
    } else {
        printf("Maximum account limit reached.\n");
    }
}

// Function to deposit money
void deposit(struct Account accounts[], int numAccounts, int accountNumber, double amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to withdraw money
void withdraw(struct Account accounts[], int numAccounts, int accountNumber, double amount) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2lf\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to check account balance
void checkBalance(struct Account accounts[], int numAccounts, int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    struct Account accounts[100];
    int numAccounts = 0;

    int choice;
    do {
        printf("\nBanking Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                {
                    int accountNumber;
                    double amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter amount to deposit: ");
                    scanf("%lf", &amount);
                    deposit(accounts, numAccounts, accountNumber, amount);
                }
                break;
            case 3:
                {
                    int accountNumber;
                    double amount;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    printf("Enter amount to withdraw: ");
                    scanf("%lf", &amount);
                    withdraw(accounts, numAccounts, accountNumber, amount);
                }
                break;
            case 4:
                {
                    int accountNumber;
                    printf("Enter account number: ");
                    scanf("%d", &accountNumber);
                    checkBalance(accounts, numAccounts, accountNumber);
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
