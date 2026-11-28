Here is a JavaScript solution for the given problem:

process.stdin.setEncoding('ascii');

process.stdin.on('data', function(data) {
    var N = parseInt(data.toString().trim());
    var matrix = [];
    for (var i = 0; i < N; i++) {
        matrix[i] = process.stdin.readLine().split(' ').map(Number);
    }
    var det = calculateDeterminant(matrix);
    console.log(det);
    process.exit();
});

function calculateDeterminant(matrix) {
    if (matrix.length === 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        var det = 0;
        for (var i = 0; i < matrix.length; i++) {
            var subMatrix = [];
            for (var j = 1; j < matrix.length; j++) {
                var row = [];
                for (var k = 0; k < matrix.length; k++) {
                    if (k !== i) {
                        row.push(matrix[j][k]);
                    }
                }
                subMatrix.push(row);
            }
            det += (i % 2 === 0 ? 1 : -1) * matrix[0][i] * calculateDeterminant(subMatrix);
        }
        return det;
    }
}

This code uses a recursive approach to calculate the determinant of a 2x2 matrix. The determinant of a matrix is calculated by the formula: det(A) = a11h1h2 - a12h1h1 - a12h2h1 + a22h1h1 - a22h2h1 - a21h2h1.

The code reads the size of the matrix N from the standard input. Then it reads N lines of the matrix from the standard input. It then calculates the determinant of the matrix and prints the result on the standard output.