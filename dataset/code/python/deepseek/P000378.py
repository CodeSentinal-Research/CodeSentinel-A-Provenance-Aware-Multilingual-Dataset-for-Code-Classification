Here is the Python code:

def search_flight(flights, flight_number):
    for flight in flights:
        if flight[0] == flight_number:
            return flight
    return "Flight Not Found"

def main():
    flights = [(1, "Departure", "Airport A"), (2, "Arrival", "Airport B")]
    flight_number = int(input("Enter the flight number: "))
    result = search_flight(flights, flight_number)
    if isinstance(result, tuple):
        print("Flight Number: ", result[0])
        print("Type: ", result[1])
        print("Location: ", result[2])
    else:
        print(result)

if __name__ == "__main__":
    main()

In this code, the `search_flight` function loops through the given list of flights and checks if the flight number matches the input flight number. If a match is found, it returns the flight details. If no match is found after checking all flights, it returns the string "Flight Not Found".

The `main` function is the entry point of the program. It first takes the flight number as input, then calls the `search_flight` function with the list of flights and the input flight number. If the result is a tuple (i.e., a match was found), it prints the flight number, type, and location. If the result is not a tuple (i.e., "Flight Not Found"), it prints the result.