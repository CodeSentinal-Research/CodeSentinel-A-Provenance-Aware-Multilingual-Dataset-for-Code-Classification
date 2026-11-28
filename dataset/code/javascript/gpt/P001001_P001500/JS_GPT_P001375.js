// P001375 - Valid Anagram
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const t = input[1];
    if (s.length !== t.length) {
        console.log("NO");
        return;
    }
    const count = new Map();
    for (const c of s) count.set(c, (count.get(c) || 0) + 1);
    for (const c of t) {
        if (!count.has(c) || count.get(c) === 0) {
            console.log("NO");
            return;
        }
        count.set(c, count.get(c) - 1);
    }
    console.log("YES");
}

main();
