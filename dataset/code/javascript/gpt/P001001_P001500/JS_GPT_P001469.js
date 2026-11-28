// P001469 - Merge Sorted Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const a = parseInt(input[1], 10);
    const b = parseInt(input[2], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[3 + i], 10));
    const map = new Map();
    map.set(0, -1);
    let diff = 0, maxLen = 0;
    for (let i = 0; i < n; i++) {
        if (nums[i] === a) diff++;
        else if (nums[i] === b) diff--;
        if (map.has(diff)) {
            maxLen = Math.max(maxLen, i - map.get(diff));
        } else {
            map.set(diff, i);
        }
    }
    console.log(maxLen);
}

main();
