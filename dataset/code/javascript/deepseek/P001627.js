Here's a simple JavaScript solution for your problem:

function countPrefixes(N, K, arr) {
    var count = 0;
    var remainder = 1;
    var prefixSum = 0;
    
    for(var i=0; i<N; i++) {
        prefixSum += arr[i];
        if (prefixSum % K === 0) count++;
        if (remainder !== K && (prefixSum % K === 0 || prefixSum > K)) {
            count += Math.floor(prefixSum / K) - (remainder === K ? 1 : 0);
            remainder = prefixSum % K === 0 ? K : prefixSum % K;
        }
    }
    
    return count;
}

console.log(countPrefixes(5, 2, [1, 2, 3, 2, 1]));

This JavaScript function `countPrefixes(N, K, arr)` counts how many prefixes of array `arr` have a sum divisible by `K`. It iterates over the array and keeps track of the prefix sum modulo `K`. If the prefix sum is divisible by `K`, it increments the count. If the remainder of the prefix sum is not `K` and the prefix sum or the remainder is greater than `K`, it calculates the number of times the prefix sum is divided by `K` and subtracts the remainder. Finally, it updates the remainder to the modulo of the prefix sum and the divisor, if the modulus is not `K`, otherwise it sets the remainder to `K`.