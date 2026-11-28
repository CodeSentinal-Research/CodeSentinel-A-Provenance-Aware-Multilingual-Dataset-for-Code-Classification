Sure, here is a simple JavaScript code snippet that solves the problem:

function maxCircularSubarraySum(arr) {
    let maxSum = arr[0], curMax = arr[0];
    let minSum = arr[0], curMin = arr[0];
    let globalMax = arr[0];

    for(let i = 1; i < arr.length; i++) {
        if(arr[i] > maxSum) {
            maxSum = arr[i];
        }
        if(arr[i] < minSum) {
            minSum = arr[i];
        }
        curMax = Math.max(arr[i], curMax + arr[i]);
        curMin = Math.min(arr[i], curMin + arr[i]);
        globalMax = Math.max(globalMax, curMax);
    }

    if(globalMax < 0) return globalMax;

    return Math.max(globalMax, maxSum + minSum);
}

console.log(maxCircularSubarraySum([1, 2, 3, 4, 5])); // 15
console.log(maxCircularSubarraySum([5, -2, 3, 8, 10, -10, 1])); // 22

In this code, we first initialize maxSum, minSum, curMax, curMin, and globalMax to the first element of the array. We then loop through the array, updating maxSum, minSum, curMax, and curMin based on whether the current element is greater than the maxSum, less than the minSum, or greater than the current max and less than the current min. Finally, we return the maximum of globalMax and maxSum + minSum.