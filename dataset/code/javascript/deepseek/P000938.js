Here is the JavaScript code for the sparse matrix multiplication problem:

function sparseMatrixMultiply(matrixA, matrixB) {
    let productMatrix = [];
    let aRowIndex = 0;
    let bColIndex = 0;
  
    for (let i = 0; i < matrixA.length; i++) {
        let aRow = matrixA[i];
        let bCol = matrixB[bColIndex];

        productMatrix[i] = new Array(bCol.length);

        for (let j = 0; j < bCol.length; j++) {
            if (aRow[aRowIndex] === 0 || bCol[j] === 0) {
                productMatrix[i][j] = 0;
            } else {
                productMatrix[i][j] = aRow[aRowIndex] * bCol[j];
                aRowIndex++;
            }
        }
        aRowIndex = 0;
        bColIndex++;
    }
  
    return productMatrix;
}

This function first creates a new 2D array with the dimensions of the product matrix. Then it iterates over each row in the first matrix (matrix A). For each row, it iterates over each element in the second matrix (matrix B). If the corresponding elements in both matrices are non-zero, it multiplies them and stores the result in the corresponding cell in the product matrix. If either matrix element is zero, it sets the corresponding cell in the product matrix to zero.