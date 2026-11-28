// P001373 - Contains Duplicate II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const last = new Map();
    for (let i = 0; i < n; i++) {
        const x = input[2 + i];
        if (last.has(x) && i - last.get(x) <= k) {
            console.log("YES");
            return;
        }
        last.set(x, i);
    }
    console.log("NO");
}

main();
