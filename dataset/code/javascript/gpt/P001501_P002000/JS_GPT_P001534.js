// P001534 - Longest Substring With At Most Two Distinct Characters
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const count = new Map();
    let l = 0, maxLen = 0;
    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        count.set(c, (count.get(c) || 0) + 1);
        while (count.size > 2) {
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
