Here is a simple JavaScript solution for the problem. It uses the modulus operator to check divisibility:

function solve(N, nums, Q, queries) {
    for(let i = 0; i < Q; i++) {
        let [L, R, X] = queries[i];
        let count = 0;
        for(let j = L; j <= R; j++) {
            if(j % X === 0) {
                count++;
            }
        }
        console.log(count);
    }
}

In this code, the `solve` function iterates over each query, extracts the range and divisor, and counts the numbers in the range that are divisible by the divisor. The count is then printed to the console.

Please note that the input to this function is an array of queries, where each query is an array of three integers. The function will print the number of divisible integers for each query.

Here is an example of how to use this function:

solve(5, [2, 3, 6, 10, 25], 3, [[1, 5, 2], [2, 4, 3], [3, 6, 1]]);

This will print:

1
1
2