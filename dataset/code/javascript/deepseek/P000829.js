function shipWithinDays(weights, days) {
    let min = Math.max(...weights), max = weights.reduce((a, b) => a + b);

    while (min < max) {
        let mid = Math.floor((min + max) / 2);
        if (check(mid, weights, days)) min = mid + 1;
        else max = mid;
    }

    return min;
}

function check(mid, weights, days) {
    let currentDays = 1, currentWeight = 0;
    for (let weight of weights) {
        if (currentWeight + weight > mid) {
            currentDays++;
            currentWeight = 0;
        }
        currentWeight += weight;
    }
    return currentDays <= days;
}
This JavaScript code defines a function `shipWithinDays` that calculates the minimum capacity of a ship that can ship all packages within given number of days. This function uses binary search to optimize the capacity.

The function `check` is a helper function that determines whether we can ship all packages within the given days with the current capacity. It calculates the number of days needed to ship the next package and updates the current package weight after each shipment. If the current package weight surpasses the capacity, we ship the next package in the next day.

The binary search starts from the maximum weight (the maximum possible weight of a package) and ends at the sum of all weights (the total capacity of the ship). In each iteration of the binary search, it calculates the mid point and checks whether we can ship all packages within the given days with the current capacity. If we can, we try to increase the capacity. Otherwise, we decrease the capacity. The function `shipWithinDays` then returns the current capacity when it is confirmed to be the minimum capacity.