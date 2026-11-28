// P001444 - Longest Palindrome by Concatenating Two-Letter Words
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const count = new Map();
    for (let i = 0; i < n; i++) {
        const w = input[1 + i];
        count.set(w, (count.get(w) || 0) + 1);
    }
    let len = 0;
    let hasCenter = false;
    for (const [w, c] of count.entries()) {
        const rev = w[1] + w[0];
        if (w === rev) {
            len += Math.floor(c / 2) * 4;
            if (c % 2 === 1) hasCenter = true;
        } else if (w < rev && count.has(rev)) {
            const pairs = Math.min(c, count.get(rev));
            len += pairs * 4;
        }
    }
    if (hasCenter) len += 2;
    console.log(len);
}

main();
