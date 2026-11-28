function searchFlights(flightRecords, destination) {
    return flightRecords.filter(record => record.destination === destination);
}

// Example usage:
const flightRecords = [
    { origin: 'New York', destination: 'London' },
    { origin: 'Paris', destination: 'Berlin' },
    { origin: 'Tokyo', destination: 'Sydney' },
    { origin: 'Berlin', destination: 'Tokyo' },
    { origin: 'New York', destination: 'Beijing' },
];

const destination = 'Berlin';
console.log(searchFlights(flightRecords, destination));