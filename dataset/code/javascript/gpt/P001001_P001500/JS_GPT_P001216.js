// P001216 - Minimum Cost Tree From Leaf Values
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const words = [];
    for (let i = 0; i < n; i++) words.push(input[1 + i]);
    words.sort((a, b) => a.length - b.length);
    const dp = new Map();
    let maxChain = 1;
    for (const w of words) {
        let best = 1;
        for (let i = 0; i < w.length; i++) {
            const prev = w.slice(0, i) + w.slice(i + 1);
            if (dp.has(prev)) {
                best = Math.max(best, dp.get(prev) + 1);
            }
        }
        dp.set(w, best);
        maxChain = Math.max(maxChain, best);
    }
    console.log(maxChain);
}

main();
