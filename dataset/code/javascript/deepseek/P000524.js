Here's a basic implementation of the problem using JavaScript. This code assumes that the input will always be valid.

function tallestTower(n, maxHeights) {
    maxHeights.sort((a, b) => b - a);
    let maxSum = 0;

    for (let i = 0; i < n; i++) {
        if (i === 0) {
            maxSum += maxHeights[i];
        } else {
            maxSum += maxHeights[i] * (i + 1);
        }
    }

    return maxSum;
}

This function starts by sorting the `maxHeights` array in descending order. Then it iterates over the `maxHeights` array, adding the current max height to the sum. If this tower is not the first one, it multiplies the current height by the index plus one, since it can't be taller than the max height of the next tower. The sum of all tower heights is the maximum possible sum of tower heights.

Please note that this solution assumes that the maximum possible height is the maximum of the given `maxHeights`. In a real-world scenario, you would also need to take into account the minimum possible height, and the possibility that a tower can be taller than its maximum height.