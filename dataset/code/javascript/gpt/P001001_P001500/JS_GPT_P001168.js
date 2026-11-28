// P001168 - Paint Fence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    if (n === 0) { console.log(0); return; }
    if (n === 1) { console.log(k); return; }
    let same = BigInt(k);
    let diff = BigInt(k) * BigInt(k - 1);
    for (let i = 3; i <= n; i++) {
        const prevDiff = diff;
        diff = (same + diff) * BigInt(k - 1);
        same = prevDiff;
    }
    console.log((same + diff).toString());
}

main();
