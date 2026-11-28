Here is a simple JavaScript code that prints Pascal's triangle:

function printPascalTriangle(n) {
    for (let line = 0; line < n; line++) {
        let C = 1;
        for (let i = 1; i <= line; i++) {
            console.log(C);
            C = Math.floor(C * (line - i) / i);
        }
   .
    .
    }
}

printPascalTriangle(5);

In this code, the function `printPascalTriangle(n)` generates the Pascal's triangle with `n` rows. The outer loop `line` runs from 0 to `n-1` and for each `line`, the inner loop computes and prints each row of Pascal's triangle.

The `C` variable is used to store the value of each cell in Pascal's triangle. The formula for calculating each cell value is `C = C * (line - i) / i` where `i` is the current row index and `line` is the current row number.

You can replace `5` in `printPascalTriangle(5)` with any other positive integer to print Pascal's triangle with that many rows.