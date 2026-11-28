Here is the Python code for the problem. 

def search_orders(orders, N):
    matching_orders = []

    from datetime import datetime, timedelta
    current_date = datetime.now()

    for order in orders:
        time_difference = current_date - order['date']

        if time_difference.days > N:
            matching_orders.append(order)

    return matching_orders

def main():
    orders = [{'id': 1, 'customer_id': 101, 'product': 'product1', 'date': datetime(2022, 5, 1)},
             {'id': 2, 'customer_id': 102, 'product': 'product2', 'date': datetime(2022, 6, 1)},
             {'id': 3, 'customer_id': 103, 'product': 'product3', 'date': datetime(2022, 7, 1)},
             {'id': 4, 'customer_id': 104, 'product': 'product4', 'date': datetime(2022, 8, 1)}]
    N = 7

    print(search_orders(orders, N))

if __name__ == "__main__":
    main()

This code first imports necessary modules, then defines the `search_orders` function. It takes an orders list and a number of days as inputs, then returns a list of orders that have remained pending for more than the specified number of days.

In the `main` function, it initializes the orders list and the number of days, then calls the `search_orders` function and prints the result.

Please note that in the real-world situation, you would probably use a database system to store the orders and also perform date operations. Also, handling of exceptions and more complex scenarios would be necessary for a real-world application.