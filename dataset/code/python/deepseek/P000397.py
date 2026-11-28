Sure, I've written the Python code for you. The code reads the order records from the input file and then retrieves all the orders with the specified status.

def search_orders_by_status(order_records, status):
    matching_orders = [order for order in order_records if order['status'] == status]
    return matching_orders

def main():
    order_records = []
    status = input("Enter the order status: ")
    n = int(input("Enter the number of orders: "))

    for _ in range(n):
        order = {'order_id': input("Enter the order ID: "),
                 'customer_id': input("Enter the customer ID: "),
                 'status': input("Enter the order status: "),
                 'items': input("Enter the items: "),
                 'total_amount': float(input("Enter the total amount: "))}
        order_records.append(order)

    matching_orders = search_orders_by_status(order_records, status)

    print("Matching orders: ")
    for order in matching_orders:
        print(order)

if __name__ == "__main__":
    main()

In this code, the `search_orders_by_status` function takes a list of order records and a status as input and returns all the orders with the specified status. The `main` function is the entry point of the program. It reads the order records from the user, and then calls the `search_orders_by_status` function to find all orders with the specified status.