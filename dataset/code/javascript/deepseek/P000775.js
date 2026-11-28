function generateBinaryStrings(n) {
    if (n < 1 || n > 20) {
        console.log("Invalid input! Constraints: 1 <= N <= 20");
        return;
    }

    let result = [];
    let current = '';
    backtrack(n, current, result);

    console.log(result.join('\n'));
}

function backtrack(n, current, result) {
    if (current.length == n) {
        result.push(current);
        return;
    }

    if (current.length > 0) {
        // add '0' at the end of current to get binary string of length 'n'
        current += '0';
        backtrack(n, current, result);
        current = current.substring(0, current.length - 1);
    }

    // add '1' at the end of current to get binary string of length 'n'
    current += '1';
    backtrack(n, current, result);
    current = current.substring(0, current.length - 1);
}

generateBinaryStrings(5);
This code generates all binary strings of length N that do not contain two consecutive 1s using backtracking. The code defines two functions: `generateBinaryStrings(n)` and `backtrack(n, current, result)`. The first function is the driver that calls the second function with the initial values of `n`, `current` and `result`. The second function is a recursive function that generates all possible binary strings of a given length, `n`, by adding '0' and '1' to the current string, and then recurses into the next levels of the tree. It uses a helper function to handle the input checking and output printing.