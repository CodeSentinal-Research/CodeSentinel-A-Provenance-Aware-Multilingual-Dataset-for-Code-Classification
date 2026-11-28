// P001145 - Longest Bitonic Subsequence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const lis = new Array(n).fill(1);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i] && lis[j] + 1 > lis[i]) lis[i] = lis[j] + 1;
        }
    }
    const lds = new Array(n).fill(1);
    for (let i = n - 1; i >= 0; i--) {
        for (let j = n - 1; j > i; j--) {
            if (nums[j] < nums[i] && lds[j] + 1 > lds[i]) lds[i] = lds[j] + 1;
        }
    }
    let maxBitonic = 0;
    for (let i = 0; i < n; i++) {
        maxBitonic = Math.max(maxBitonic, lis[i] + lds[i] - 1);
    }
    console.log(maxBitonic);
}

main();
