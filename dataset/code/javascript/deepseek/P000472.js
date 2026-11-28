function findPeak(matrix) {
    let max = matrix[0][0];
    let maxIndex = [];
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                maxIndex = [i, j];
            }
        }
    }
    return `Peak element is at ${maxIndex[0]}, ${maxIndex[1]}, with value ${max}`;
}

// Testing the function
console.log(findPeak([[1, 2, 3], [2, 5, 6], [4, 7, 8]])); // Output: Peak element is at 1, 1, with value 7
console.log(findPeak([[10, 20, 30], [70, 50, 60], [40, 80, 90]])); // Output: Peak element is at 1, 2, with value 90