// P001263 - Two City Scheduling
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n2 = parseInt(input[0], 10);
    let ptr = 1;
    const costs = [];
    for (let i = 0; i < n2; i++) {
        costs.push([parseInt(input[ptr++], 10), parseInt(input[ptr++], 10)]);
    }
    costs.sort((a, b) => (a[0] - a[1]) - (b[0] - b[1]));
    let total = 0;
    const n = n2 / 2;
    for (let i = 0; i < n; i++) total += costs[i][0];
    for (let i = n; i < n2; i++) total += costs[i][1];
    console.log(total);
}

main();
