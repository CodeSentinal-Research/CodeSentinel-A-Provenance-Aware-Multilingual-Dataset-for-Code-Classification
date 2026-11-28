// P001374 - Happy Number
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    let n = parseInt(input, 10);
    const seen = new Set();
    while (n !== 1 && !seen.has(n)) {
        seen.add(n);
        let sum = 0;
        while (n > 0) {
            const d = n % 10;
            sum += d * d;
            n = Math.floor(n / 10);
        }
        n = sum;
    }
    console.log(n === 1 ? "YES" : "NO");
}

main();
