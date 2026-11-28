// P001456 - Repeated DNA Sequences
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s || s.length < 10) return;
    const seen = new Set();
    const repeated = new Set();
    for (let i = 0; i <= s.length - 10; i++) {
        const sub = s.substring(i, i + 10);
        if (seen.has(sub)) {
            repeated.add(sub);
        } else {
            seen.add(sub);
        }
    }
    const res = Array.from(repeated).sort();
    for (const seq of res) console.log(seq);
}

main();
