// P001396 - Rabbits in Forest
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const count = new Map();
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[1 + i], 10);
        count.set(val, (count.get(val) || 0) + 1);
    }
    let total = 0;
    for (const [ans, c] of count.entries()) {
        const groupSize = ans + 1;
        const groups = Math.ceil(c / groupSize);
        total += groups * groupSize;
    }
    console.log(total);
}

main();
