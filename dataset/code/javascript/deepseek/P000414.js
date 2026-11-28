Sure, here is a JavaScript solution for the problem.

function searchAvailableFlights(flights, budget) {
    return flights.filter(flight => flight.price <= budget);
}

This function uses the `filter` method of JavaScript arrays to create a new array with all the flights whose price is not greater than the budget. The `filter` method creates a new array with all elements that pass the test implemented by the provided function. In this case, the test is whether the flight's price is not greater than the budget.

This function would be called with a flights array and a budget as arguments, like so:

let flights = [
    { destination: 'New York', price: 1500 },
    { destination: 'San Francisco', price: 1000 },
    { destination: 'Los Angeles', price: 2000 },
    // more flights...
];
let budget = 2000;

let availableFlights = searchAvailableFlights(flights, budget);

console.log(availableFlights);

This would output:

[
    { destination: 'New York', price: 1500 },
    { destination: 'Los Angeles', price: 2000 },
]

This output represents the available flights whose price does not exceed the given budget.