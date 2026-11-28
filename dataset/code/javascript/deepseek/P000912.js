Here is the JavaScript code for the problem:

function getRow(rowIndex) {
    if (rowIndex < 0 || rowIndex > 33) {
        throw new Error('Invalid rowIndex');
    }
    
    var pascal = [[1]];
    
    for (var i = 1; i <= rowIndex; i++) {
        var lastRow = pascal[i - 1];
        var nextRow = [];
        
        for (var j = 0; j <= lastRow.length; j++) {
            if (j == 0 || j == lastRow.length) {
                nextRow[j] = 1;
            } else {
                nextRow[j] = lastRow[j - 1] + lastRow[j];
            }
        }
        
        pascal[i] = nextRow;
    }
    
    return pascal[rowIndex];
}

This function uses Pascal's Triangle concept to get the rowIndex-th row. It begins with a 1-element row, then iteratively adds new elements to generate the next row. It throws an error if rowIndex is not within the valid range.

You can call this function with a rowIndex like this:

console.log(getRow(5));  // prints [1, 4, 6, 4, 1]