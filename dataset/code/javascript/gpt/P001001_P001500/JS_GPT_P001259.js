// P001259 - Minimum Swaps to Balance Brackets
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let count = 0, maxClose = 0;
    for (const c of s) {
        if (c === "[") count++;
        else count--;
        if (count < 0) maxClose = Math.max(maxClose, -count);
    }
    console.log(Math.ceil(maxClose / 2));
}

main();
