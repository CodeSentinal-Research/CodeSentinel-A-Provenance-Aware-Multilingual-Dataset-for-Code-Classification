// P001387 - Check Array Equality
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const count = new Map();
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[ptr++], 10);
        count.set(x, (count.get(x) || 0) + 1);
    }
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[ptr++], 10);
        if (!count.has(x) || count.get(x) === 0) {
            console.log("NO");
            return;
        }
        count.set(x, count.get(x) - 1);
    }
    console.log("YES");
}

main();
