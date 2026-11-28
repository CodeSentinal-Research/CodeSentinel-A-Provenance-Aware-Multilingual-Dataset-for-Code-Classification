// P001558 - Longest Substring With At Most K Distinct Characters
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    const count = new Map();
    let l = 0, maxLen = 0;
    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        count.set(c, (count.get(c) || 0) + 1);
        while (count.size > k) {
            const leftC = s[l];
            const cnt = count.get(leftC) - 1;
            if (cnt === 0) count.delete(leftC);
            else count.set(leftC, cnt);
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
