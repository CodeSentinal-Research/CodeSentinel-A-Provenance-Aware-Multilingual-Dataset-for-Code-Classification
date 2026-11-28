Here is the JavaScript code to solve the problem:

function countWays(n) {
    if (n < 0) {
        return 0;
    }
    if (n === 0) {
        return 1;
    }
    return countWays(n - 1) + countWays(n - 2);
}

In this code, we are using a recursive approach where we are calculating the number of ways to climb stairs from `n-1` step and `n-2` step. We keep adding these two ways together to get the total ways.

To use this function, call it with the number of stairs you want to climb as the argument:

console.log(countWays(5)); // 5

This code will work for `n` from 0 to 40, because it uses a basic case and a simple recursion.