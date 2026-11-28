// P001237 - Non-overlapping Intervals
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const gas = [];
    for (let i = 0; i < n; i++) gas.push(parseInt(input[ptr++], 10));
    const cost = [];
    for (let i = 0; i < n; i++) cost.push(parseInt(input[ptr++], 10));
    let totalTank = 0, currTank = 0, start = 0;
    for (let i = 0; i < n; i++) {
        const net = gas[i] - cost[i];
        totalTank += net;
        currTank += net;
        if (currTank < 0) {
            start = i + 1;
            currTank = 0;
        }
    }
    console.log(totalTank >= 0 ? start : -1);
}

main();
