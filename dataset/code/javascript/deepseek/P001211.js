function canPartitionKSubsets(arr, k) {
    let sum = arr.reduce((a, b) => a + b, 0);
    if (sum % k !== 0) return false; // not divisible by k
    sum /= k;
    let visited = new Array(arr.length).fill(false);
    let cache = new Map();

    function dfs(start, currSum, k) {
        if (k === 0) return true;
        if (currSum === sum && k !== 1) return false;
        let cacheKey = [start, currSum].join(",");
        if (cache.has(cacheKey)) return cache.get(cacheKey);
        for (let i = start; i < arr.length; i++) {
            if (!visited[i] && (currSum + arr[i] <= sum)) {
                visited[i] = true;
                if (dfs(i + 1, (currSum + arr[i]) % sum, k)) {
                    cache.set(cacheKey, true);
                    return true;
                }
                visited[i] = false;
            }
        }
        cache.set(cacheKey, false);
        return false;
    }
    return dfs(0, 0, k);
}

// Usage:
let arr = [1, 2, 3, 4];
let k = 3;
console.log(canPartitionKSubsets(arr, k));
This JavaScript function `canPartitionKSubsets` takes an array `arr` and an integer `k` as input, and returns true if it's possible to partition `arr` into exactly `k` non-empty subsets whose sums are all equal, and false otherwise.

The function uses a depth-first search (DFS) strategy to try all possible partitions. It uses a visited array `visited` to mark the elements that have been processed. The `cache` Map is used to store the results of previous computations to avoid redundant computations.

In the DFS function, it iterates through all the elements in the array. If the current element has not been visited, it checks if the current sum plus the current element can be achieved by the remaining elements (those that haven't been visited yet). If it can, it marks the current element as visited and recursively calls the DFS function on the next subset. If the current sum plus the current element can't be achieved by the remaining elements, it marks the current element as unvisited and continues the search.

The `dfs` function returns true if it finds a partition where the sum of each partition is equal to the target sum (`sum`). If it reaches the end of the array without finding a partition, it returns false.