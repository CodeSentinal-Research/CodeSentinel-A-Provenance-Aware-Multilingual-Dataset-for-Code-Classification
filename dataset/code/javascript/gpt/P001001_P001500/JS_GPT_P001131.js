// P001131 - Fibonacci Number
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    if (n <= 0) { console.log(0); return; }
    if (n === 1) { console.log(1); return; }
    let a = 0n, b = 1n;
    for (let i = 2; i <= n; i++) {
        const c = a + b;
        a = b;
        b = c;
    }
    console.log(b.toString());
}

main();
