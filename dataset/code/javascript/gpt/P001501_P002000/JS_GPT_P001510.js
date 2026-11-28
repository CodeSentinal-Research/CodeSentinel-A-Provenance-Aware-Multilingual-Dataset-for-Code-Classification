// P001510 - Longest Repeating Character Replacement
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    const count = new Array(26).fill(0);
    let maxCount = 0, l = 0, maxLen = 0;
    for (let r = 0; r < s.length; r++) {
        const idx = s.charCodeAt(r) - 65;
        count[idx]++;
        maxCount = Math.max(maxCount, count[idx]);
        while ((r - l + 1) - maxCount > k) {
            count[s.charCodeAt(l) - 65]--;
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    console.log(maxLen);
}

main();
