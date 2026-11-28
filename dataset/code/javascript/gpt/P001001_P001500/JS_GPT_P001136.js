// P001136 - Tribonacci Number
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    if (n === 0) { console.log(0); return; }
    if (n === 1 || n === 2) { console.log(1); return; }
    let a = 0n, b = 1n, c = 1n;
    for (let i = 3; i <= n; i++) {
        const next = a + b + c;
        a = b;
        b = c;
        c = next;
    }
    console.log(c.toString());
}

main();
