// P001183 - Frog Jump
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const stones = [];
    for (let i = 0; i < n; i++) stones.push(parseInt(input[1 + i], 10));
    const dp = new Map();
    for (const s of stones) dp.set(s, new Set());
    dp.get(0).add(0);
    for (const s of stones) {
        for (const k of dp.get(s)) {
            for (const step of [k - 1, k, k + 1]) {
                if (step > 0 && dp.has(s + step)) {
                    dp.get(s + step).add(step);
                }
            }
        }
    }
    console.log(dp.get(stones[n - 1]).size > 0 ? "YES" : "NO");
}

main();
