Sure, here is a simple solution for the given problem in JavaScript. This code assumes that the input is a JSON object containing vehicle information and a registration number. The function `findVehicle` is used to find the vehicle based on the provided registration number.

function findVehicle(vehicles, registrationNumber) {
    for (let i = 0; i < vehicles.length; i++) {
        if (vehicles[i].registrationNumber === registrationNumber) {
            return vehicles[i];
        }
    }
    return 'Vehicle Not Found';
}

This function iterates over each vehicle in the list of vehicles. If a vehicle's registration number matches the provided registration number, it returns the vehicle details. If no match is found, it returns the string 'Vehicle Not Found'.

The input to this function is a list of vehicle objects where each vehicle object has a `registrationNumber` property.

You can use this function like this:

let vehicles = [
    { regNumber: 'ABC123', make: 'Toyota', model: 'Corolla', color: 'White' },
    { regNumber: 'XYZ987', make: 'Honda', model: 'Civic', color: 'Black' },
    { regNumber: 'LMN654', make: 'Mercedes', model: 'E-Class', color: 'Red' }
];

console.log(findVehicle(vehicles, 'XYZ987'));  // { regNumber: 'XYZ987', make: 'Honda', model: 'Civic', color: 'Black' }
console.log(findVehicle(vehicles, 'DEF234'));  // 'Vehicle Not Found'

Please note that this function is a simple implementation and may not be efficient for large number of vehicles. In real-world applications, you might want to use a database or other data structure for storing and searching the vehicles.