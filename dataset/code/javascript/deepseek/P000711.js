Here is the JavaScript code for the problem:

function combinations(n, k, nums = [], curr = 1) {
    if (nums.length === k) {
        console.log(nums.join(' '));
        return;
    }
    if (curr > n - k + nums.length + 1) {
        return;
    }
    nums.push(curr);
    combinations(n, k, nums, curr + 1);
    nums.pop();
    combinations(n, k, nums, curr + 1);
}

This code defines a function `combinations` which generates all combinations of `k` numbers from 1 to `n`. It takes four parameters: the current number `curr`, the current combination `nums`, and the current depth `depth`.

The function first checks if the current combination is complete (i.e., if the `nums` array has `k` elements). If it is, it logs the current combination and returns.

If the current combination is not complete, the function will add the current number to the `nums` array and then call itself recursively with the next number (`curr + 1`).

After the recursive call, the function pops the last number from the `nums` array to backtrack. Then it calls itself recursively with the next number (`curr + 1`).

This way, the function will generate all combinations of `k` numbers from 1 to `n` and print them in lexicographical order.