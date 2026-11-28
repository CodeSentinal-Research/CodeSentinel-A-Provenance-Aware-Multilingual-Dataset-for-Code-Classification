// P001438 - Divide Array Into Equal Pairs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const count = new Map();
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[1 + i], 10);
        count.set(x, (count.get(x) || 0) + 1);
    }
    for (const c of count.values()) {
        if (c % 2 !== 0) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
