Sure, here is a simple JavaScript solution that fulfills the problem's constraints.

function maxTastiness(n, prices, k) {
    // Sort the prices array
    prices.sort((a, b) => a - b);

    // Initialize maximum tastiness
    let maxTastiness = 0;

    // Iterate over the prices array
    for (let i = 0; i < n - 1; i++) {
        // Calculate the difference between current price and next price
        const difference = prices[i + 1] - prices[i];

        // If the difference is greater than the current maximum, update the maximum
        if (difference > maxTastiness) {
            maxTastiness = difference;
        }
    }

    // Return the maximum tastiness
    return maxTastiness;
}

This function first sorts the prices array in ascending order. It then calculates the difference between the current price and the next price for each candy, and updates the maximum tastiness if the difference is greater. It does this for all candies, and finally returns the maximum tastiness.

The input to this function is the number of candies `n`, an array of prices `prices`, and the number of candies to choose `k`. This function does not handle any input errors, so you need to make sure to provide valid input.