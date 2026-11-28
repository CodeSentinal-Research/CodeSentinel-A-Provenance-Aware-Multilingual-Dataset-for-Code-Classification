// P001362 - Can Partition into K Palindromes
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const s = input[0];
    const k = parseInt(input[1], 10);
    if (s.length < k) { console.log("NO"); return; }
    const freq = new Map();
    for (const c of s) freq.set(c, (freq.get(c) || 0) + 1);
    let odd = 0;
    for (const count of freq.values()) {
        if (count % 2 !== 0) odd++;
    }
    console.log(odd <= k ? "YES" : "NO");
}

main();
