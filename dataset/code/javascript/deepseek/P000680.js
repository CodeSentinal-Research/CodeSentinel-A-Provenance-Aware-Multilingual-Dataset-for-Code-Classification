Here is the JavaScript solution for the problem:

function printNumbers(n) {
    if (n < 1) {
        return;
    }
    console.log(n);
    printNumbers(n - 1);
}

This function will print the numbers from `n` to 1 using recursion. The base case for the recursion is when `n` is less than 1. When `n` reaches 0, the function stops the recursion.