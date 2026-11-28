Here's a simple JavaScript solution using a map to store flight records. The `getFlightDetails` function will take a flight number as input and return the corresponding flight details.

let flightRecords = new Map();

function addFlight(flightNumber, details) {
  flightRecords.set(flightNumber, details);
}

function getFlightDetails(flightNumber) {
  if (flightRecords.has(flightNumber)) {
    return flightRecords.get(flightNumber);
  } else {
    return "Flight Not Found";
  }
}

In this code, a Map object is used to store flight records. The `addFlight` function adds a flight record by flight number. The `getFlightDetails` function searches for a flight by flight number and returns the corresponding details. If no flight found, it returns "Flight Not Found".

You can use the `addFlight` function to add flight records to the `flightRecords` map. For example, you can add a flight record like `addFlight(1, { flightNumber: 1, details: { destination: 'New York', departure: '06:00', airplane: 'Airbus 320' } })`. Then, you can get the flight details by calling `getFlightDetails(1)`.