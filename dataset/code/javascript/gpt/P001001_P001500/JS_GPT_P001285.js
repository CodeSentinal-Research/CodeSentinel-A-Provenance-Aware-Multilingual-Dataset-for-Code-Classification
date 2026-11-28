// P001285 - Broken Calculator
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    let start = parseInt(input[0], 10);
    let target = parseInt(input[1], 10);
    let ops = 0;
    while (target > start) {
        if (target % 2 === 0) target /= 2;
        else target += 1;
        ops++;
    }
    console.log(ops + (start - target));
}

main();
