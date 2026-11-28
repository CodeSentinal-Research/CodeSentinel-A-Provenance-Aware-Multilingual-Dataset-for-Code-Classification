Here is a JavaScript solution for the problem:

function numTrees(n) {
    let cache = [0, 1, 2]; // base cases
    
    for (let i = 3; i <= n; i++) {
        cache[i] = 0;
        for (let j = 1; j <= i; j++) {
            cache[i] += cache[j - 1] * cache[i - j];
        }
    }
    
    return cache[n];
}

console.log(numTrees(4));

This function uses a dynamic programming approach to calculate the number of unique Binary Search Trees that can be formed using values from 1 to N. The cache array stores the results for subproblems, so if the result for a given N is already calculated, it is simply returned.

This function takes O(N^2) time, and O(N) space, because in the worst case, each function call and subproblem size grow quadratically with N.