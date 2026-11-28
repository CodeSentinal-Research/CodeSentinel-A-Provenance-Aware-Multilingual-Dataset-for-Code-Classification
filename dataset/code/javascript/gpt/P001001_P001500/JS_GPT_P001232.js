// P001232 - Activity Selection
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let cap = parseFloat(input[1]);
    let ptr = 2;
    const items = [];
    for (let i = 0; i < n; i++) {
        const val = parseFloat(input[ptr++]);
        const wt = parseFloat(input[ptr++]);
        items.push({ val, wt, ratio: val / wt });
    }
    items.sort((a, b) => b.ratio - a.ratio);
    let totalVal = 0.0;
    for (const item of items) {
        if (cap <= 0) break;
        if (item.wt <= cap) {
            totalVal += item.val;
            cap -= item.wt;
        } else {
            totalVal += item.ratio * cap;
            cap = 0;
        }
    }
    console.log(totalVal.toFixed(2));
}

main();
