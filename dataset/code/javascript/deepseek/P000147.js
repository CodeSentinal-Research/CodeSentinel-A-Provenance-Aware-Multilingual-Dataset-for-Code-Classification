Sure, here's a simple JavaScript solution for the problem.

process.stdin.setEncoding('utf8');
process.stdin.on('data', function(data) {
    var n = parseInt(data.trim());
    var matrix = [];
    for (var i = 0; i < n; i++) {
        matrix.push(readLine().split(' ').map(Number));
    }
    printDiagonalElements(matrix);
});

function readLine() {
    return process.stdin.readLine();
}

function printDiagonalElements(matrix) {
    var mainDiagonal = [], antiDiagonal = [];
    for (var i = 0; i < matrix.length; i++) {
        mainDiagonal.push(matrix[i][i]);
        antiDiagonal.push(matrix[i][matrix.length - i - 1]);
    }
    console.log(mainDiagonal.join(' '));
    console.log(antiDiagonal.join(' '));
}

In this code, we first read the size of the matrix from the standard input. We then read the matrix from the standard input. The `printDiagonalElements` function is where the main logic of the program is. It loops through each row of the matrix and adds the element at the same position as the diagonal (main diagonal) and at the same position as the anti-diagonal (anti-diagonal) to their respective arrays. Finally, it prints the arrays.