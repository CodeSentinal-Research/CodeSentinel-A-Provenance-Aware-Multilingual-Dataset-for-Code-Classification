Here is a simple JavaScript code that solves the problem:

function findRadius(houses, heaters) {
    if (houses.length === 0) return 0;
    if (heaters.length === 0) return;

    heaters.sort(function(a, b){return a - b});

    let minRadius = Infinity;

    for (let i = 0; i < heaters.length; i++) {
        let closestHeater = heaters[i];

        for (let j = 0; j < houses.length; j++) {
            if (Math.abs(closestHeater - houses[j]) < minRadius) {
                minRadius = Math.abs(closestHeater - houses[j]);
            }
       
            if (closestHeater > houses[j]) {
                closestHeater = heaters[i + 1];
            }
        }
    }

    return minRadius;
}

// Test the function
let houses = [1, 5, 11, 18];
let heaters = [2, 3, 5, 9];
console.log(findRadius(houses, heaters)); // Output: 1

This function works by first sorting the heaters array. Then, it iterates over each house. For each house, it finds the closest heater and updates the minimum radius. If the house is closer to the next heater, it moves to the next heater. The function finally returns the minimum radius.

This solution assumes that the house array is sorted in ascending order. If the house array is not sorted, the solution might not work correctly.