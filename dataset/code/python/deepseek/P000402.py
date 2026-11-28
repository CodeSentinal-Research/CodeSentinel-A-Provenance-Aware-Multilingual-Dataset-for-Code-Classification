Here's a simple Python code using lists to store flight records and a function to search for flights by destination.

def search_flights(flight_records, destination):
    matching_flights = [record for record in flight_records if record[1] == destination]
    return matching_flights

def main():
    flight_records = [["New York", "Paris"], ["London", "Tokyo"], ["San Francisco", "Beijing"]]
    destination = input("Enter the destination to search for: ")
    matching_flights = search_flights(flight_records, destination)
    for flight in matching_flights:
        print(flight)

if __name__ == "__main__":
    main()

This code defines a `search_flights` function that takes a list of flight records and a destination, and returns a list of flight records that match the destination. The `main` function gets the destination from the user, calls the `search_flights` function with the flight records and the destination, and prints the matching flight records.

Please note that in a real-world situation, you would likely use a database or a more complex data structure to store flight records. This is just a simple demonstration of how you might set up this program.