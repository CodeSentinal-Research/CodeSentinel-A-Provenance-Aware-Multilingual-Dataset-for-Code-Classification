Here is the JavaScript code to solve the problem:

function searchInMatrix(N, M, matrix, target) {
    if (!matrix || !matrix.length || matrix[0].length !== M) {
        return false;
    }

    for (let row of matrix) {
        if (row[0] > target) {
            for (let element of row) {
                if (element === target) {
                    return true;
                }
            }
        } else {
            for (let i = 0; i < row.length; i++) {
                if (row[i] === target) {
                    return true;
                }
            }
        }
    }

    return false;
}

This function takes in the dimensions of the matrix, the matrix itself, and the target value. It first checks if the matrix is valid. If it's not, it returns false. Then it iterates over each row in the matrix. If a row's first element is greater than the target, it iterates over all elements in that row. If the target is found, it returns true. If the row's first element is not greater than the target, it iterates over all elements in that row. If the target is found, it returns true. If no target is found in the matrix, it returns false.