Here is a simple implementation of the factorial problem in JavaScript:

function factorial(n) {
    if (n === 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Test the function
console.log(factorial(5)); // Output: 120

In this code, the `factorial` function computes the factorial of a given number `n`. The base case for the recursion is when `n` is 0, at which point the function returns 1. For all other inputs, the function calls itself with the argument `n - 1`, then multiplies the result by `n` to get the factorial of `n`.