// P001593 - Shortest Prefix With Sum Greater Than X
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const x = BigInt(input[1]);
    let cur = 0n;
    for (let i = 0; i < n; i++) {
        cur += BigInt(input[2 + i]);
        if (cur > x) {
            console.log(i + 1);
            return;
        }
    }
    console.log(-1);
}

main();
