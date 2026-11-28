// P001401 - Maximum Size Subarray Sum Equals K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const map = new Map();
    map.set(0, -1);
    let prefix = 0, maxLen = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[2 + i], 10);
        prefix += val;
        if (map.has(prefix - k)) {
            maxLen = Math.max(maxLen, i - map.get(prefix - k));
        }
        if (!map.has(prefix)) {
            map.set(prefix, i);
        }
    }
    console.log(maxLen);
}

main();
