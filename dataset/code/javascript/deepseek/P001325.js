Here is a JavaScript solution using a recursive function to generate all combinations:

function combine(n, k, current = [], result = []) {
    if (current.length === k) {
        result.push(current.slice());
        return;
    }
    for (let i = n; i > 0; i--) {
        current.push(i);
        combine(i - 1, k, current, result);
        current.pop();
    }
    return result;
}

let [n, k] = process.argv.slice(2).map(Number);
if (!(1 <= k && k <= n && n <= 20)) {
    console.log('Invalid input!');
    return;
}

console.log(combine(n, k));

In this solution, we use a recursive function `combine` to generate all combinations. It takes three arguments: `n`, `k` and two optional `current` and `result` arrays. `current` is used to store the current combination being built, and `result` is used to store all combinations that have been found.

The function first checks if the current combination is of length `k`. If so, it adds the combination to `result` and then returns.

If the current combination is not of length `k`, the function iterates over the numbers from `n` down to 1. For each number `i`, it adds `i` to `current` and recursively calls `combine` on `i - 1` and `k`. After the recursive call, it removes `i` from `current`.

Finally, the function returns the `result` array which contains all combinations of `k` numbers from 1 to `n`.

The code reads the input `n` and `k` and checks if they are valid. If not, it prints an error message and returns. Otherwise, it calls the `combine` function with `n` and `k` and logs the result.