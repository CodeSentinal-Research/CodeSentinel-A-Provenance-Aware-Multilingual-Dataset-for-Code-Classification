Here is the JavaScript code for the problem:

function searchTransaction(transactions, id) {
    for (let i = 0; i < transactions.length; i++) {
        if (transactions[i].id === id) {
            return transactions[i];
        }
    }
    return 'Transaction Not Found';
}

// Testing the function
const transactions = [
    { id: 1, amount: 500, type: 'debit' },
    { id: 2, amount: 1000, type: 'credit' },
    { id: 3, amount: 2000, type: 'debit' },
    { id: 4, amount: 5000, type: 'credit' }
];

console.log(searchTransaction(transactions, 2)); // Outputs: { id: 2, amount: 1000, type: 'credit' }
console.log(searchTransaction(transactions, 5)); // Outputs: 'Transaction Not Found'
In this code, the `searchTransaction` function iterates over the `transactions` array, and checks each transaction's `id` against the provided `id`. If a match is found, it returns the transaction details. If no match is found after checking all transactions, it returns 'Transaction Not Found'.