Here is a JavaScript solution that uses recursion to find all the paths in a maze. The function `findPaths` is recursively called with two parameters: the current coordinates (row and column) and the destination coordinates (row and column).

function findPaths(row, column, rows, cols) {
    if (row == rows && column == cols) {
        console.log(`Path: ${path.join(' -> ')}`);
        return;
    }
    if (row > rows || column > cols) {
        return;
    }
    if (row == rows && column + 1 <= cols) {
        path.push('H');
        findPaths(row, column + 1, rows, cols);
        path.pop();
    }
    if (column == cols && row + 1 <= rows) {
        path.push('V');
        findPaths(row + 1, column, rows, cols);
        path.pop();
    }
    if (row + 1 <= rows && column + 1 <= cols) {
        path.push('D');
        findPaths(row + 1, column + 1, rows, cols);
        path.pop();
    }
}

function solveMaze(rows, cols) {
    path = [];
    findPaths(1, 1, rows, cols);
}

let rows = parseInt(prompt("Enter the number of rows:"));
let cols = parseInt(prompt("Enter the number of columns:"));
solveMaze(rows, cols);

This code will ask for the number of rows and columns, and then print out all the valid paths from the top-left cell to the bottom-right cell. The paths are printed in lexicographical order, and the direction of each move is printed next to it.