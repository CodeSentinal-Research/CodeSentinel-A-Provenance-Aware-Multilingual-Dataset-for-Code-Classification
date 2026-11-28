Here is a JavaScript solution that uses a HashMap to track the frequency of the XOR of the numbers in the array. We then iterate through the array and count the pairs that satisfy the condition.

function countPairsWithXORK(N, K, nums) {
    let freq = new Map();
    let count = 0;

    for (let num of nums) {
        if (freq.has(num ^ K)) {
            count += freq.get(num ^ K);
        }
        if (freq.has(num)) {
            freq.set(num, freq.get(num) + 1);
        } else {
            freq.set(num, 1);
        }
    }

    return count;
}

To use the function, you would call it like this:

let nums = [1, 3, 2, 4];
console.log(countPairsWithXORK(4, 2, nums));

This code assumes that the input is valid, i.e., `N` is an integer between 1 and 2×10^5, and all elements in `nums` are integers between 0 and 10^9. It also assumes that `nums` is an array of at least one integer.