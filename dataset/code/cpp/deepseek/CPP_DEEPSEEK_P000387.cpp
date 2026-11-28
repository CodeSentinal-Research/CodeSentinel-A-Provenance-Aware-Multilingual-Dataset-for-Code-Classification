#include <iostream>
#include <unordered_map>

struct Transaction {
    int transactionID;
    string details;
};

unordered_map<int, Transaction> transactions;

void addTransaction(int id, Transaction transaction) {
    transactions[id] = transaction;
}

Transaction searchTransaction(int id) {
    if (transactions.find(id) != transactions.end()) {
        return transactions[id];
    }
    return Transaction(); 
}

int main() {
    addTransaction(1, {"Details1", 1});
    addTransaction(2, {"Details2", 2});
    addTransaction(3, {"Details3", 3});

    Transaction foundTransaction = searchTransaction(2);

    if (foundTransaction.transactionID == 0) {
        cout << "Transaction Not Found" << endl;
    } else {
        cout << "Transaction ID: " << foundTransaction.transactionID << ", Details: " << foundTransaction.details << endl;
    }

    return 0;
}