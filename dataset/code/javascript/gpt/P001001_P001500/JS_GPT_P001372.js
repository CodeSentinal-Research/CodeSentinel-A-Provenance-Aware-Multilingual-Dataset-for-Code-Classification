// P001372 - Contains Duplicate
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const seen = new Set();
    for (let i = 0; i < n; i++) {
        const x = input[1 + i];
        if (seen.has(x)) {
            console.log("YES");
            return;
        }
        seen.add(x);
    }
    console.log("NO");
}

main();
