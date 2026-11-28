function spiralOrder(matrix) {
    if (!matrix.length || !matrix[0].length) return [];

    let result = [];
    let rowBegin = 0;
    let rowEnd = matrix.length - 1;
    let colBegin = 0;
    let colEnd = matrix[0].length - 1;

    while (true) {
        if (rowBegin > rowEnd) break;
        for (let i = colBegin; i <= colEnd; i++) {
            result.push(matrix[rowBegin][i]);
        }
        rowBegin++;

        if (rowBegin > rowEnd) break;
        for (let i = rowBegin; i <= rowEnd; i++) {
            result.push(matrix[i][colEnd]);
        }
        colEnd--;

        if (colBegin > colEnd) break;
        for (let i = colEnd; i >= colBegin; i--) {
            result.push(matrix[rowEnd][i]);
        }
        rowEnd--;

        if (rowBegin > rowEnd) break;
        for (let i = rowEnd; i >= rowBegin; i--) {
            result.push(matrix[i][colBegin]);
        }
        colBegin++;
    }

    return result;
}

console.log(spiralOrder([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]));

console.log(spiralOrder([
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
]));