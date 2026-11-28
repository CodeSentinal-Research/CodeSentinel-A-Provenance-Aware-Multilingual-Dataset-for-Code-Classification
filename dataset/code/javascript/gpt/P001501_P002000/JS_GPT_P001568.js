// P001568 - Longest Subarray of Ones After Deleting One Element
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const map = new Map();
    map.set(0, -1);
    let sum = 0, maxLen = 0;
    for (let i = 0; i < n; i++) {
        sum += nums[i];
        const rem = ((sum % k) + k) % k;
        if (map.has(rem)) {
            maxLen = Math.max(maxLen, i - map.get(rem));
        } else {
            map.set(rem, i);
        }
    }
    console.log(maxLen);
}

main();
