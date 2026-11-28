// P001577 - Count Strictly Increasing Windows
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const minutes = parseInt(input[1], 10);
    let ptr = 2;
    const customers = [];
    for (let i = 0; i < n; i++) customers.push(parseInt(input[ptr++], 10));
    const grumpy = [];
    for (let i = 0; i < n; i++) grumpy.push(parseInt(input[ptr++], 10));

    let baseSatisfied = 0;
    for (let i = 0; i < n; i++) {
        if (grumpy[i] === 0) baseSatisfied += customers[i];
    }
    let extra = 0;
    for (let i = 0; i < minutes; i++) {
        if (grumpy[i] === 1) extra += customers[i];
    }
    let maxExtra = extra;
    for (let i = minutes; i < n; i++) {
        if (grumpy[i] === 1) extra += customers[i];
        if (grumpy[i - minutes] === 1) extra -= customers[i - minutes];
        maxExtra = Math.max(maxExtra, extra);
    }
    console.log(baseSatisfied + maxExtra);
}

main();
