Here's a simple JavaScript solution for generating Pascal's Triangle:

function generatePascalsTriangle(numRows) {
    if (numRows <= 0) {
        return [];
    }

    let triangle = [[1]];

    for (let row = 1; row < numRows; row++) {
        let prevRow = triangle[row - 1];
        let newRow = [1];

        for (let i = 1; i < prevRow.length; i++) {
            let leftParent = prevRow[i - 1];
            let rightParent = prevRow[i];

            newRow[i] = leftParent + rightParent;
        }

        newRow.push(1);
        triangle.push(newRow);
   
    }

    return triangle;
}

console.log(generatePascalsTriangle(5));

This script generates Pascal's Triangle up to the nth row. It starts with a single row containing the number 1, then for each subsequent row, it computes the sum of the numbers directly above it and above the left and right parent numbers. The script will return the Pascal's Triangle up to the nth row. Note, if numRows is less than or equal to zero, the function will return an empty array.