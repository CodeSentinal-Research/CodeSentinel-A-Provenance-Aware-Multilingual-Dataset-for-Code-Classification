// P001527 - Minimum Positive Sum Subarray
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    for (let i = 0; i < n; i++) {
        if (nums[i] > 0) {
            console.log(1);
            return;
        }
    }
    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
    for (let len = 2; len <= n; len++) {
        for (let i = 0; i + len <= n; i++) {
            if (prefix[i + len] - prefix[i] > 0) {
                console.log(len);
                return;
            }
        }
    }
    console.log(-1);
}

main();
