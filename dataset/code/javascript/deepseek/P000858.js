Here is the JavaScript code to solve the problem:

function findPosition(n) {
    if (n === 0) {
        return 'Invalid input. N must be a non-zero integer.';
    }

    let pos = 0;
    while (n) {
        n >>= 1;
        pos++;
    }

    return pos;
}

console.log(findPosition(5)); // Outputs: 2

In this code, we are using bitwise operators to solve the problem. The '>>=' operator is a shorthand for 'n = n >> 1'. We shift the bits of 'n' one place to the right and then count the number of times we shift the bits. The position of the set bit is the count of the shifts. The position starts from 1, not 0 as in some programming languages.