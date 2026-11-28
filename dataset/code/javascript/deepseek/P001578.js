Here is the JavaScript code that will solve the given problem.

function countWindows(N, K, arr) {
    let count = 0;
    for (let i = 0; i < N; i++) {
        let distinctCount = 0;
        let distinctSet = new Set();
        for (let j = i; j < i + K; j++) {
            if (!distinctSet.has(arr[j])) {
                distinctSet.add(arr[j]);
                distinctCount++;
            }
        }
        if (distinctCount === K) {
            count++;
        }
    }
    return count;
}

This function uses a sliding window approach to find the count of all subarrays of size K where every element is distinct. It starts with each element of the array, then checks all possible subarrays of size K starting from this element. If the number of distinct elements in a subarray is equal to K, it increments the count.

The input to this function is an array of integers and an integer K. It uses a Set to keep track of the distinct elements in a subarray. The size of the Set is kept in a variable distinctCount. If the number of distinct elements in a subarray is equal to K, it increments the count.

This function has a time complexity of O(N^2) due to the two nested loops. This is the best we can achieve for this problem.