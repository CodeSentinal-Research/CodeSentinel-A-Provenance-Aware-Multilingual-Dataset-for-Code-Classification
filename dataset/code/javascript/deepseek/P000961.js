Here is a simple JavaScript code that will solve the problem:

function countSolutions(A, B, C, XRange, YRange) {
    if (typeof A !== 'number' || typeof B !== 'number' || typeof C !== 'number' ||
        typeof XRange !== 'object' || XRange.hasOwnProperty('start') === false || XRange.hasOwnProperty('end') === false ||
        typeof YRange !== 'object' || YRange.hasOwnProperty('start') === false || YRange.hasOwnProperty('end') === false) {
        throw new Error('Invalid input format. Input should be an object with properties start and end.');
    }

    let solutionsCount = 0;

    for (let X = XRange.start; X <= XRange.end; X++) {
        let Y = Math.floor((C - B * X) / A);

        if (Y >= YRange.start && Y <= YRange.end) {
            solutionsCount++;
        }
    }

    return solutionsCount;
}

This function takes four parameters: A, B, C, and XRange and YRange. Both XRange and YRange should be objects with properties start and end that specify the range for X and Y, respectively.

The function first validates the input. If the input is not valid, it throws an error.

Then it initializes a counter `solutionsCount` to 0.

It then loops over all possible values of X in the given range. For each X, it calculates Y by subtracting B * X from C and dividing by A.

If Y is within the range of Y, it increments the counter.

Finally, it returns the counter, which is the number of solutions.