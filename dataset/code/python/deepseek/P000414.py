Sure, here's a Python solution using dictionary and list data structures. This code will search for available flights whose ticket price does not exceed the specified budget.

def search_available_flights(flight_records, budget):
    matching_flights = []

    for flight in flight_records:
        if flight['price'] <= budget:
            matching_flights.append(flight)

    return matching_flights

flight_records = [
    {'destination': 'New York', 'price': 150},
    {'destination': 'London', 'price': 200},
    {'destination': 'Tokyo', 'price': 100},
    {'destination': 'Sydney', 'price': 250},
    {'destination': 'Berlin', 'price': 120},
]
budget = 130
print(search_available_flights(flight_records, budget))

In this code, we first initialize an empty list to store the matching flights. We then iterate over the list of flight records. For each flight, we check if its price does not exceed the budget. If it does, we add it to our list of matching flights. Finally, we return the list of matching flights.

The test code creates a list of flight records and a budget, and then calls the `search_available_flights` function with these parameters. The function returns the list of matching flights.