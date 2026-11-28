// P001381 - Longest Consecutive Sequence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const set = new Set();
    for (let i = 0; i < n; i++) set.add(parseInt(input[1 + i], 10));
    let maxLen = 0;
    for (const x of set) {
        if (!set.has(x - 1)) {
            let curr = x, len = 1;
            while (set.has(curr + 1)) {
                curr++;
                len++;
            }
            if (len > maxLen) maxLen = len;
        }
    }
    console.log(maxLen);
}

main();
