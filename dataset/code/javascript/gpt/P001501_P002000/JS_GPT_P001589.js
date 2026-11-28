// P001589 - Longest Well-Performing Interval
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const hours = [];
    for (let i = 0; i < n; i++) hours.push(parseInt(input[1 + i], 10));
    let score = 0, maxLen = 0;
    const seen = new Map();
    for (let i = 0; i < n; i++) {
        score += (hours[i] > 8) ? 1 : -1;
        if (score > 0) {
            maxLen = i + 1;
        } else {
            if (!seen.has(score)) seen.set(score, i);
            if (seen.has(score - 1)) {
                maxLen = Math.max(maxLen, i - seen.get(score - 1));
            }
        }
    }
    console.log(maxLen);
}

main();
