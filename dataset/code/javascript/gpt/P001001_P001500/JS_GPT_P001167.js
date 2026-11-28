// P001167 - Paint House
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    let r = 0, g = 0, b = 0;
    for (let i = 0; i < n; i++) {
        const costR = parseInt(input[ptr++], 10);
        const costG = parseInt(input[ptr++], 10);
        const costB = parseInt(input[ptr++], 10);
        const newR = costR + Math.min(g, b);
        const newG = costG + Math.min(r, b);
        const newB = costB + Math.min(r, g);
        r = newR; g = newG; b = newB;
    }
    console.log(Math.min(r, g, b));
}

main();
