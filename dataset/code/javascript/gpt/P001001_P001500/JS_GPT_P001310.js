// P001310 - Minimum Cost of Connecting Sticks
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const sticks = [];
    for (let i = 0; i < n; i++) sticks.push(parseInt(input[1 + i], 10));
    sticks.sort((a, b) => a - b);
    let totalCost = 0;
    while (sticks.length > 1) {
        const first = sticks.shift();
        const second = sticks.shift();
        const sum = first + second;
        totalCost += sum;
        let low = 0, high = sticks.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (sticks[mid] < sum) low = mid + 1;
            else high = mid;
        }
        sticks.splice(low, 0, sum);
    }
    console.log(totalCost);
}

main();
