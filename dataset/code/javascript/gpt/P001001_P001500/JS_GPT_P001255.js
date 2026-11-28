// P001255 - Minimum Additions to Make Parentheses Valid
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const freq = new Map();
    for (const c of s) freq.set(c, (freq.get(c) || 0) + 1);
    const used = new Set();
    let deletions = 0;
    for (let count of freq.values()) {
        while (count > 0 && used.has(count)) {
            count--;
            deletions++;
        }
        if (count > 0) used.add(count);
    }
    console.log(deletions);
}

main();
