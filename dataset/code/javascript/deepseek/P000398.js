function searchByManufacturer(vehicles, manufacturer) {
    return vehicles.filter(vehicle => vehicle.manufacturer.toLowerCase() === manufacturer.toLowerCase());
}

// Usage
let vehicles = [
    { model: 'Ford', manufacturer: 'Ford' },
    { model: 'Honda', manufacturer: 'Toyota' },
    { model: 'Tesla', manufacturer: 'Tesla' },
    { model: 'Chevrolet', manufacturer: 'Chevrolet' },
];

let result = searchByManufacturer(vehicles, 'Tesla');
console.log(result);

This code defines a function `searchByManufacturer` that takes an array of vehicle objects and a manufacturer name as parameters. It returns a new array with all vehicles that have the specified manufacturer. The `toLowerCase` method is used to ensure the search is case-insensitive.

In the usage part, we create an array of vehicle objects, then call `searchByManufacturer` with the `vehicles` array and the name 'Tesla' as parameters. The result is logged to the console.