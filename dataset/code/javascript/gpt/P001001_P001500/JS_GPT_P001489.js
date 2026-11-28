// P001489 - Number of Subsequences That Satisfy the Given Sum Condition
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const target = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    nums.sort((a, b) => a - b);
    const MOD = 1000000007;
    const power = new Array(n).fill(1);
    for (let i = 1; i < n; i++) {
        power[i] = (power[i - 1] * 2) % MOD;
    }
    let l = 0, r = n - 1, ans = 0;
    while (l <= r) {
        if (nums[l] + nums[r] <= target) {
            ans = (ans + power[r - l]) % MOD;
            l++;
        } else {
            r--;
        }
    }
    console.log(ans);
}

main();
