// P001228 - Dice Throw Problem
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    let n = parseInt(input, 10);
    let ans = 0;
    while (n > 0) {
        ans ^= n;
        n >>= 1;
    }
    console.log(ans);
}

main();
