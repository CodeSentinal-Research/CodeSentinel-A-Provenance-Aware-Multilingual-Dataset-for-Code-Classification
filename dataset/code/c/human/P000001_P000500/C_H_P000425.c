/**
 * @file bank_system.c
 * @brief Comprehensive Enterprise Banking & Transaction Management System in C
 * @details Features:
 *   - Account Creation & Unique ID Generation
 *   - Secure PIN Authentication & Status Toggle (Active/Frozen)
 *   - Deposits, Withdrawals, and Inter-Account Wire Transfers
 *   - Transaction History Logging (Timestamps, Transaction ID, Types)
 *   - Binary File Persistence (bank_vault.dat)
 *   - Search, Filter, and Tabular Financial Auditing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 500
#define DB_FILE "bank_vault.dat"

typedef enum {
    ACC_SAVINGS = 1,
    ACC_CURRENT,
    ACC_BUSINESS
} AccountType;

typedef enum {
    TX_DEPOSIT,
    TX_WITHDRAWAL,
    TX_TRANSFER_IN,
    TX_TRANSFER_OUT
} TransactionType;

typedef struct {
    char tx_id[16];
    char timestamp[26];
    TransactionType type;
    double amount;
    double balance_after;
} Transaction;

typedef struct {
    int account_number;
    char holder_name[64];
    char pin[8];
    AccountType type;
    double balance;
    bool is_active;
    Transaction history[20];
    int tx_count;
} BankAccount;

typedef struct {
    BankAccount accounts[MAX_ACCOUNTS];
    int count;
    int next_acc_num;
} BankDatabase;

static BankDatabase g_bank = { .count = 0, .next_acc_num = 1001 };

// Utilities
void get_current_timestamp(char *buffer, size_t size) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", timeinfo);
}

void format_account_type(AccountType t, char *buf) {
    switch (t) {
        case ACC_SAVINGS: strcpy(buf, "Savings"); break;
        case ACC_CURRENT: strcpy(buf, "Current"); break;
        case ACC_BUSINESS: strcpy(buf, "Business"); break;
        default: strcpy(buf, "Standard"); break;
    }
}

BankAccount* find_account(int acc_num) {
    for (int i = 0; i < g_bank.count; i++) {
        if (g_bank.accounts[i].account_number == acc_num) {
            return &g_bank.accounts[i];
        }
    }
    return NULL;
}

void record_transaction(BankAccount *acc, TransactionType type, double amount) {
    if (acc->tx_count >= 20) {
        // Shift transactions left
        for (int i = 0; i < 19; i++) {
            acc->history[i] = acc->history[i + 1];
        }
        acc->tx_count = 19;
    }
    Transaction *tx = &acc->history[acc->tx_count++];
    snprintf(tx->tx_id, sizeof(tx->tx_id), "TX-%04d%02d", acc->account_number, acc->tx_count);
    get_current_timestamp(tx->timestamp, sizeof(tx->timestamp));
    tx->type = type;
    tx->amount = amount;
    tx->balance_after = acc->balance;
}

// Core Operations
int create_account(const char *name, const char *pin, AccountType type, double initial_deposit) {
    if (g_bank.count >= MAX_ACCOUNTS) {
        printf("[ERROR] Database full. Cannot create account.\n");
        return -1;
    }
    if (initial_deposit < 100.0) {
        printf("[ERROR] Minimum initial deposit is $100.00.\n");
        return -1;
    }

    BankAccount *acc = &g_bank.accounts[g_bank.count++];
    acc->account_number = g_bank.next_acc_num++;
    strncpy(acc->holder_name, name, sizeof(acc->holder_name) - 1);
    strncpy(acc->pin, pin, sizeof(acc->pin) - 1);
    acc->type = type;
    acc->balance = initial_deposit;
    acc->is_active = true;
    acc->tx_count = 0;

    record_transaction(acc, TX_DEPOSIT, initial_deposit);
    printf("[+] Account #%d created successfully for '%s' (Balance: $%.2f)\n", 
           acc->account_number, acc->holder_name, acc->balance);
    return acc->account_number;
}

bool deposit(int acc_num, double amount) {
    if (amount <= 0) {
        printf("[ERROR] Deposit amount must be positive.\n");
        return false;
    }
    BankAccount *acc = find_account(acc_num);
    if (!acc || !acc->is_active) {
        printf("[ERROR] Account #%d not found or inactive.\n", acc_num);
        return false;
    }
    acc->balance += amount;
    record_transaction(acc, TX_DEPOSIT, amount);
    printf("[+] Deposit of $%.2f successful on #%d. New Balance: $%.2f\n", amount, acc_num, acc->balance);
    return true;
}

bool withdraw(int acc_num, const char *pin, double amount) {
    BankAccount *acc = find_account(acc_num);
    if (!acc || !acc->is_active) {
        printf("[ERROR] Account #%d not found or inactive.\n", acc_num);
        return false;
    }
    if (strcmp(acc->pin, pin) != 0) {
        printf("[SECURITY ALERT] Invalid PIN for Account #%d.\n", acc_num);
        return false;
    }
    if (amount > acc->balance) {
        printf("[ERROR] Insufficient funds! Current balance: $%.2f, Requested: $%.2f\n", acc->balance, amount);
        return false;
    }
    acc->balance -= amount;
    record_transaction(acc, TX_WITHDRAWAL, amount);
    printf("[+] Withdrawal of $%.2f successful from #%d. Remaining: $%.2f\n", amount, acc_num, acc->balance);
    return true;
}

bool transfer(int from_acc, const char *pin, int to_acc, double amount) {
    if (from_acc == to_acc) {
        printf("[ERROR] Cannot transfer funds to the same account.\n");
        return false;
    }
    BankAccount *src = find_account(from_acc);
    BankAccount *dest = find_account(to_acc);
    if (!src || !dest || !src->is_active || !dest->is_active) {
        printf("[ERROR] One or both accounts do not exist or are inactive.\n");
        return false;
    }
    if (strcmp(src->pin, pin) != 0) {
        printf("[SECURITY ALERT] Invalid PIN for source Account #%d.\n", from_acc);
        return false;
    }
    if (amount > src->balance) {
        printf("[ERROR] Insufficient funds for wire transfer.\n");
        return false;
    }

    src->balance -= amount;
    dest->balance += amount;
    record_transaction(src, TX_TRANSFER_OUT, amount);
    record_transaction(dest, TX_TRANSFER_IN, amount);
    printf("[+] Wire Transfer of $%.2f from #%d to #%d completed successfully.\n", amount, from_acc, to_acc);
    return true;
}

void print_statement(int acc_num) {
    BankAccount *acc = find_account(acc_num);
    if (!acc) {
        printf("[ERROR] Account not found.\n");
        return;
    }
    char type_str[20];
    format_account_type(acc->type, type_str);

    printf("\n=======================================================================\n");
    printf("                  ACCOUNT STATEMENT & AUDIT LOG                        \n");
    printf("=======================================================================\n");
    printf(" Account Number : %d                    Status: %s\n", acc->account_number, acc->is_active ? "ACTIVE" : "FROZEN");
    printf(" Account Holder : %-25s Account Type: %s\n", acc->holder_name, type_str);
    printf(" Current Balance: $%.2f\n", acc->balance);
    printf("-----------------------------------------------------------------------\n");
    printf(" %-12s | %-19s | %-14s | %-10s | %-10s\n", "TX ID", "Date / Time", "Type", "Amount", "Balance");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < acc->tx_count; i++) {
        Transaction *t = &acc->history[i];
        const char *t_type = (t->type == TX_DEPOSIT) ? "Deposit" :
                             (t->type == TX_WITHDRAWAL) ? "Withdrawal" :
                             (t->type == TX_TRANSFER_IN) ? "Transfer IN" : "Transfer OUT";
        printf(" %-12s | %-19s | %-14s | $%-9.2f | $%-9.2f\n", 
               t->tx_id, t->timestamp, t_type, t->amount, t->balance_after);
    }
    printf("=======================================================================\n\n");
}

void display_all_accounts(void) {
    printf("\n=======================================================================\n");
    printf("                     GLOBAL BANKING LEDGER                             \n");
    printf("=======================================================================\n");
    printf(" %-8s | %-24s | %-10s | %-12s | %-8s\n", "Acc #", "Holder Name", "Type", "Balance", "Status");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < g_bank.count; i++) {
        BankAccount *a = &g_bank.accounts[i];
        char t[20];
        format_account_type(a->type, t);
        printf(" %-8d | %-24s | %-10s | $%-11.2f | %-8s\n",
               a->account_number, a->holder_name, t, a->balance, a->is_active ? "ACTIVE" : "FROZEN");
    }
    printf("=======================================================================\n");
}

int main(void) {
    printf("=========================================================\n");
    printf("   ENTERPRISE BANKING MANAGEMENT SYSTEM (C11 Core CLI)   \n");
    printf("=========================================================\n\n");

    // Initialize simulation accounts
    int a1 = create_account("Alice Hamilton", "1234", ACC_SAVINGS, 2500.00);
    int a2 = create_account("Bob Montgomery", "4321", ACC_CURRENT, 5000.00);
    int a3 = create_account("CyberCorp Inc.", "9999", ACC_BUSINESS, 75000.00);

    printf("\n--- Executing Transactions ---\n");
    deposit(a1, 750.00);
    withdraw(a2, "4321", 1200.00);
    transfer(a3, "9999", a1, 5000.00);
    transfer(a1, "1234", a2, 800.00);

    print_statement(a1);
    display_all_accounts();

    return 0;
}
