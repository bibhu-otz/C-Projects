#include <stdio.h>

// Define account structure
struct Account {
    int accountNumber;
    float balance;
};

// Function prototypes
void deposit(struct Account *account, float amount);
void withdraw(struct Account *account, float amount);
void checkBalance(struct Account account);

int main() {
    struct Account account = {12345, 1000.0};
    int choice;
    float amount;

    while(1) {
        printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(&account, amount); break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(&account, amount); break;
            case 3: checkBalance(account); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

void deposit(struct Account *account, float amount) {
    // Implementation to deposit money
}

void withdraw(struct Account *account, float amount) {
    // Implementation to withdraw money
}

void checkBalance(struct Account account) {
    // Implementation to check balance
}
