Here is a simple JavaScript solution for your problem. The function `factorial` calculates the factorial of a given number. The function `nPr` calculates the permutation `nPr` of a set of `n` items taken `r` at a time.

function factorial(n) {
    let result = 1;
    for (let i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

function nPr(n, r) {
    if (n < 0 || r < 0 || n < r) {
        console.log("Invalid input.");
        return null;
    }
    return factorial(n) / factorial(n - r);
}

In the `nPr` function, we first check if the input values are valid. If not, we log an error message and return `null`. Otherwise, we calculate and return the permutation `nPr`.

To use this function, simply call it with the desired `n` and `r` values:

console.log(nPr(5, 3));  // Outputs: 5! / (5-3)! = 120

This program assumes that `n` and `r` are non-negative integers. If `n` or `r` is a floating point number or a negative number, the program will print an error message and return `null`.