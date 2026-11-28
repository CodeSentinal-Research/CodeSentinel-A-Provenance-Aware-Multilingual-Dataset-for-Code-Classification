// P001253 - Minimum Absolute Difference Pairs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const target = [];
    for (let i = 0; i < n; i++) target.push(parseInt(input[1 + i], 10));
    let ans = target[0];
    for (let i = 1; i < n; i++) {
        if (target[i] > target[i - 1]) ans += (target[i] - target[i - 1]);
    }
    console.log(ans);
}

main();
