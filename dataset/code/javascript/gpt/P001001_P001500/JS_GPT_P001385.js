// P001385 - Find All Missing Numbers
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const present = new Set();
    for (let i = 0; i < n; i++) present.add(parseInt(input[1 + i], 10));
    const missing = [];
    for (let i = 1; i <= n; i++) {
        if (!present.has(i)) missing.push(i);
    }
    console.log(missing.join(" "));
}

main();
