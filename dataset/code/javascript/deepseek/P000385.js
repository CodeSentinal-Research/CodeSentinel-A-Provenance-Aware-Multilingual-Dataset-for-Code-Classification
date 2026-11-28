Sure, here is the JavaScript code that solves the problem. This code assumes that you have an array of order records (each record is an object with fields 'orderId' and 'orderDetails') and a function 'findOrderById' that takes in an order ID and returns the order details or "Order Not Found".

function findOrderById(orders, orderId) {
    for(let i = 0; i < orders.length; i++) {
        if(orders[i].orderId === orderId) {
            return orders[i].orderDetails;
        }
    }
    return "Order Not Found";
}

In this code, we loop through the orders array and check if the current order's ID matches the provided order ID. If it does, we return the order details. If no match is found after checking all orders, we return "Order Not Found".