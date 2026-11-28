// P001533 - Longest Substring With Exactly K Distinct Characters
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    let maxLen = -1;
    for (let i = 0; i < s.length; i++) {
        const set = new Set();
        for (let j = i; j < s.length; j++) {
            set.add(s[j]);
            if (set.size === k) {
                maxLen = Math.max(maxLen, j - i + 1);
            } else if (set.size > k) {
                break;
            }
        }
    }
    console.log(maxLen);
}

main();
