def search_transaction(transactions, transaction_id):
    for transaction in transactions:
        if transaction['id'] == transaction_id:
            return transaction
    return None

def main():
    transactions = [
        {'id': 1, 'amount': 100, 'type': 'debit'},
        {'id': 2, 'amount': 200, 'type': 'credit'},
        {'id': 3, 'amount': 300, 'type': 'debit'},
        {'id': 4, 'amount': 400, 'type': 'credit'}
    ]

    transaction_id = int(input("Enter transaction ID: "))
    result = search_transaction(transactions, transaction_id)

    if result:
        print('Transaction Found:', result)
    else:
        print('Transaction Not Found')

if __name__ == '__main__':
    main()