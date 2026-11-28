const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

const matrix = [];

readline.question('Enter the number of rows (between 1 and 50): ', rows => {
    for(let i = 0; i < rows; i++) {
        matrix.push(readline.question('Enter a row (separated by spaces): ').split(' ').map(Number));
    }

    function commonElements(a, b) {
        let result = [];
        for(let i = 0; i < a.length; i++) {
            if(b.includes(a[i])) {
                result.push(a[i]);
            }
        }
        return result;
    }

    console.log(commonElements(matrix[0], matrix[1]));
    readline.close();
});
This JavaScript program takes a matrix as input from the user. The matrix is a 2D array, where each row is a separate array. The program then uses a function to find all common elements in the rows of the matrix.

It first reads the number of rows and then reads each row. Each row is converted to a number array and added to the `matrix` array.

Then, it defines a function `commonElements(a, b)` that takes two arrays as parameters and returns a new array that contains the common elements of the two input arrays. It then finds and logs the common elements of the first two rows of the matrix to the console.

The function `includes()` is used to check if an element from the first row is present in the second row.

The program uses `readline` to get the input from the user, and `console.log` to print the output.