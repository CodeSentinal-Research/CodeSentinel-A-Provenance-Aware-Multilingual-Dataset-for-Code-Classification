// P001158 - Integer Break
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    if (n <= 3) { console.log(n - 1); return; }
    let prod = 1n;
    let num = BigInt(n);
    while (num > 4n) {
        prod *= 3n;
        num -= 3n;
    }
    prod *= num;
    console.log(prod.toString());
}

main();
