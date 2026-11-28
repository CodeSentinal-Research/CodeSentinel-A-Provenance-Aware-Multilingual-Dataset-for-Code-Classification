// P001389 - Longest Subarray with Equal Number of 0s and 1s
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const arr = [];
    for (let i = 0; i < n; i++) arr.push(parseInt(input[1 + i], 10));
    const map = new Map();
    map.set(0, -1);
    let sum = 0, maxLen = 0;
    for (let i = 0; i < n; i++) {
        sum += (arr[i] === 0 ? -1 : 1);
        if (map.has(sum)) {
            maxLen = Math.max(maxLen, i - map.get(sum));
        } else {
            map.set(sum, i);
        }
    }
    console.log(maxLen);
}

main();
