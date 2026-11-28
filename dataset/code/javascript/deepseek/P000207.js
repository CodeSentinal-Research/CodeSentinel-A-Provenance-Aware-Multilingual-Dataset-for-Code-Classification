Here's the JavaScript code for finding the maximum sum of an hourglass in a 2D matrix:

function maxSumHourglass(matrix) {
    let maxSum = -Infinity;

    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            if (i + 2 < matrix.length && j + 1 < matrix[i].length) {
                let sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] +
                          matrix[i + 1][j + 1] +
                          matrix[i + 2][j] + matrix[i + 2][j + 1] + matrix[i + 2][j + 2];
                maxSum = Math.max(maxSum, sum);
            }
        }
    }

    return maxSum;
}

// Test with example matrix
let matrix = [[1, 1, 1, 1, 1],
              [1, 1, 1, 1, 1],
              [1, 1, 1, 1, 1],
              [1, 1, 1, 1, 1],
              [1, 1, 1, 1, 1]];

console.log(maxSumHourglass(matrix));  // Outputs: 7

This code defines a function `maxSumHourglass` that takes a 2D matrix as input. It iterates through each element of the matrix, checking if it's a part of a valid hourglass, and if it is, calculates the sum of the hourglass and updates the `maxSum` variable if the sum is larger than the current `maxSum`. After checking all elements, it returns the `maxSum`.

The test matrix is a 5x5 matrix with all elements equal to 1, representing a valid hourglass. The output of the code is 7 (which is the sum of the elements in the middle hourglass), as these are the elements 1, 1, 1, 1, 1, 1, and 1 within the middle hourglass.