Sure, here is a simple JavaScript solution that implements the Range Sum Query problem:

// Input the array size and the number of queries
var N = parseInt(readline());
var arr = readline().split(' ').map(Number);
var Q = parseInt(readline());

// Initialize prefix sum array
var prefixSum = new Array(N + 1).fill(0);
for(var i = 0; i < N; i++) {
    prefixSum[i + 1] = prefixSum[i] + arr[i];
}

for(var i = 0; i < Q; i++) {
    var L = parseInt(readline());
    var R = parseInt(readline());
    console.log(prefixSum[R + 1] - prefixSum[L]);
}

This code reads the array size and array values from the standard input, calculates the prefix sum for the array, and then for each query, it calculates and prints the sum of elements from index L to R (inclusive).

Please note that you need to implement the `readline` function based on your environment, such as `readlineSync` in Node.js, or `prompt` in the browser console.