Here is a simple Python solution using dictionary to map order IDs to their corresponding details. You can replace the mock data with actual order records from your database or file.

def search_order(order_records, order_id):
    if order_id in order_records:
        return order_records[order_id]
    else:
        return "Order Not Found"

order_records = {
    1: {"id": 1, "customer_name": "John Doe", "product": "Phone", "quantity": 2, "price": 100},
    2: {"id": 2, "customer_name": "Jane Doe", "product": "Laptop", "quantity": 1, "price": 500},
    3: {"id": 3, "customer_name": "Bob Smith", "product": "Tablet", "quantity": 3, "price": 300},
}

def main():
    order_id = int(input("Enter the order ID: "))
    print(search_order(order_records, order_id))

if __name__ == "__main__":
    main()

In this code, the `search_order` function takes in order records and an order ID. It checks if the order ID is in the order records. If it is, it returns the corresponding order details. If the order ID is not in the order records, it returns "Order Not Found".

The `main` function is the entry point of the program, and it gets the order ID from the user. It calls the `search_order` function with the mock order records and the user's input, and then prints the returned order details.