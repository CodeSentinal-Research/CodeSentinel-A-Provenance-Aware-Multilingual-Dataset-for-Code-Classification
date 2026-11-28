Here is a JavaScript solution using prefix sum and hash map:

function numSubmatrixSumTarget(N, M, grid, target) {
    let count = 0;
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            for (let p = i; p < N; p++) {
                for (let q = j; q < M; q++) {
                    let sum = 0;
                    for (let i = p; i >= i - P; i--) {
                        for (let j = q; j >= j - Q; j--) {
                            sum += grid[i][j];
                        }
                    }
                    if (sum === target) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

This solution is using the four nested loops to generate all possible submatrices and check if the sum of the elements in the submatrix equals to the target. If yes, it increments the counter.

Please note that this solution is highly inefficient for large inputs due to the time complexity. 

The space complexity of this solution is also high because it uses an additional 2D array (`sums`) to store the prefix sum.

The time complexity of this solution is also high because it generates all possible submatrices and checks each one, which is O(N^4).

To make the solution efficient, we can use a two-dimensional prefix sum (or a map) to store the prefix sum from top left to (i, j) and then we can directly find the number of prefix sums that equals to target minus the value at (i, j).

Here is the optimized version of the above solution:

function numSubmatrixSumTarget(N, M, grid, target) {
    let count = 0;
    let map = new Map();
    map.set(0, [{row: 0, col: 0, sum: grid[0][0]}]);
    
    for(let i = 1; i < N; i++) {
        grid[i][0] += grid[i - 1][0];
    }

    for(let j = 1; j < M; j++) {
        grid[0][j] += grid[0][j - 1];
    }

    for(let i = 0; i < N; i++) {
        for(let j = 0; j < M; j++) {
            for(let p: any = i; p <= N - 1; p++) {
                for(let q: any = j; q <= M - 1; q++) {
                    let sum = map.get(p - i + 1).reduce((prev, curr) => prev + curr.sum, 0);
                    sum -= map.get(p - i + 1)[q - j];
                    sum += grid[p][q];
                    if(sum === target) count++;
                }
            }
        }
    }
    return count;
}

This solution is much more efficient as it only uses a constant amount of space. The time complexity is still O(N^4) but the space complexity is greatly reduced to O(N^2) due to the usage of a map.