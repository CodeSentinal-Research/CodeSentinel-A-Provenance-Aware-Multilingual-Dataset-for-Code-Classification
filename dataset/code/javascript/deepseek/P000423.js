Here's the JavaScript code that can solve the problem:

function searchOrders(records, N) {
    const pendingOrders = records.filter(record => record.status === 'pending' && record.daysPending > N);
    return pendingOrders;
}

This function takes an array of order records and an integer N as inputs. The function uses the `filter` method to create a new array with all orders that are in the 'pending' state and have remained pending for more than N days. It then returns this array of matching orders.

You would use this function by passing an array of order records and an integer N as inputs. For example:

const records = [
    { id: 1, customerId: 'customer1', orderId: 'order1', status: 'pending', daysPending: 5 },
    { id: 2, customerId: 'customer2', orderId: 'order2', status: 'completed', daysPending: 2 },
    // more records...
];

const N = 3;

const pendingOrders = searchOrders(records, N);

console.log(pendingOrders);

In the above example, the function `searchOrders` is called with `records` as the input and `N` as the second argument. The function will return all orders with a `daysPending` value greater than `N`.

The `console.log(pendingOrders);` line will print all matching orders to the console.