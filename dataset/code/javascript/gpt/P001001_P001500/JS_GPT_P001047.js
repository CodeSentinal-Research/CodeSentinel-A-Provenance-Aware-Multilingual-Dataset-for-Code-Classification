// P001047 - Sum of All Heap Elements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let sum = 0n;
    for (let i = 0; i < n; i++) {
        sum += BigInt(input[1 + i]);
    }
    console.log(sum.toString());
}

main();
