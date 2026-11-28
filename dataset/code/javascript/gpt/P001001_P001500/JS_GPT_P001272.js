// P001272 - Jump Game VI
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const dp = new Array(n).fill(0);
    dp[0] = nums[0];
    const deque = [0];
    for (let i = 1; i < n; i++) {
        while (deque.length > 0 && deque[0] < i - k) deque.shift();
        dp[i] = dp[deque[0]] + nums[i];
        while (deque.length > 0 && dp[deque[deque.length - 1]] <= dp[i]) deque.pop();
        deque.push(i);
    }
    console.log(dp[n - 1]);
}

main();
