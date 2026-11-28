Here is a JavaScript solution using the map function to rotate each row of the matrix by K positions to the right.

function rotateMatrix(rows, cols, k) {
    // Read input and create matrix
    const matrix = [];
    for (let i = 0; i < rows; i++) {
        matrix[i] = readline().split(' ').map(Number);
    }

    // Rotate each row
    for (let i = 0; i < rows; i++) {
        let row = matrix[i];
        let rotated = row.slice(k).concat(row.slice(0, k));
        matrix[i] = rotated;
    }

    // Output matrix
    for (let i = 0; i < rows; i++) {
        console.log(matrix[i].join(' '));
    }
}

function readline() {
    return process.stdin.readline();
}

In this code, we first read the input matrix from the standard input. Each row of the matrix is read as a line, split by space into an array of numbers, and converted into a number array. We then use the slice method to rotate each row by k positions to the right and concat to create the rotated row. The rotated row is then assigned to the corresponding row in the matrix. Finally, we output the matrix by iterating over each row and printing each row.