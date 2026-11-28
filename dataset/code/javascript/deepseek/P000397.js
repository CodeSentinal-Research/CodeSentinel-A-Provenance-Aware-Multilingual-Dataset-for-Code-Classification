function searchOrdersByOrderStatus(orders, orderStatus) {
  // Filter orders based on order status
  let filteredOrders = orders.filter(order => order.status === orderStatus);

  // Return the filtered orders
  return filteredOrders;
}