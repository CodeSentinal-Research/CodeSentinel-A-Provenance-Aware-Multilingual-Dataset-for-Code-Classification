Sure, here is the JavaScript code for the problem:

function optimalSearchTreeCost(n, keys, freq) {
    if (n === 1) {
        return freq[0];
    }

    let minCost = Number.MAX_VALUE;
    for (let i = 0; i < n; i++) {
        let cost = freq[i];
        let leftCost = optimalSearchTreeCost(i, keys, freq);
        let rightCost = optimalSearchTreeCost(n - i - 1, keys, freq);
        if (leftCost + rightCost + cost < minCost) {
            minCost = leftCost + rightCost + cost;
        }
    }

    return minCost;
}

console.log(optimalSearchTreeCost(5, [1, 3, 5, 7, 9], [1, 2, 3, 4, 5]));
This code defines a function `optimalSearchTreeCost` that takes as input the number of keys `n`, an array of keys `keys`, and an array of frequencies `freq`. It calculates the minimum search cost for a Binary Search Tree that contains all the keys by iterating over all possible split points and calculating the cost for each split. If the current minimum cost is greater than the cost for the current split, it updates the minimum cost. The function finally returns the minimum cost.

You can test the function with the given input.