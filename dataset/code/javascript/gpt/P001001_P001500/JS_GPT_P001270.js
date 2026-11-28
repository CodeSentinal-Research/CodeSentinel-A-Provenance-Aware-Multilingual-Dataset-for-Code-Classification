// P001270 - Minimum Operations to Reduce Array to Zero
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const unique = new Set();
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[1 + i], 10);
        if (val > 0) unique.add(val);
    }
    console.log(unique.size);
}

main();
