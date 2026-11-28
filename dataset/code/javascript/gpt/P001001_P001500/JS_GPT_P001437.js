// P001437 - Check If N and Its Double Exist
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const seen = new Set();
    let exists = false;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[1 + i], 10);
        if (seen.has(x * 2) || (x % 2 === 0 && seen.has(x / 2))) {
            exists = true;
        }
        seen.add(x);
    }
    console.log(exists ? "YES" : "NO");
}

main();
