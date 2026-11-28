// P001269 - Divide Array into Sets of K Consecutive Numbers
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    if (n % k !== 0) { console.log("NO"); return; }
    const nums = [];
    const count = new Map();
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[2 + i], 10);
        nums.push(x);
        count.set(x, (count.get(x) || 0) + 1);
    }
    nums.sort((a, b) => a - b);
    for (const x of nums) {
        const c = count.get(x) || 0;
        if (c > 0) {
            for (let i = 0; i < k; i++) {
                const target = x + i;
                const tc = count.get(target) || 0;
                if (tc < c) { console.log("NO"); return; }
                count.set(target, tc - c);
            }
        }
    }
    console.log("YES");
}

main();
