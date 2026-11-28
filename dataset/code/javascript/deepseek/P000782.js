Here is the code:

// Prefix Sum Array
let prefixSum = [];

function createPrefixSum(arr) {
    prefixSum[0] = arr[0]; // Initialize first sum
    for(let i = 1; i < arr.length; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

function countElementsInRange(n, arr, q, queries) {
    createPrefixSum(arr);

    for(let i = 0; i < q; i++) {
        let [L, R] = queries[i];
        console.log(prefixSum[R] - (L > 0 ? prefixSum[L - 1] : 0));
    }
}

countElementsInRange(6, [1, 2, 3, 4, 5, 6], 2, [[1, 3], [2, 5]]);

In this solution, we create a prefix sum array `prefixSum` and fill it with the prefix sum of the input array. For each query, we calculate the sum of the elements in the range [L, R] using the prefix sum.

In the main function, we call the function `countElementsInRange` with the array `nums`, its length `n`, the number of queries `q`, and the array of queries `queries` as input. We then print the count of elements for each query.

Please note that this code uses JavaScript as the programming language. The code also uses ES6 JavaScript syntax, such as arrow functions and destructuring assignment.