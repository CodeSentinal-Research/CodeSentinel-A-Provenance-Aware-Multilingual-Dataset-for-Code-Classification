// P001017 - Connect Ropes with Minimum Cost
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const ropes = [];
    for (let i = 0; i < n; i++) {
        ropes.push(parseInt(input[1 + i], 10));
    }
    ropes.sort((a, b) => a - b);
    let totalCost = 0;
    while (ropes.length > 1) {
        const first = ropes.shift();
        const second = ropes.shift();
        const sum = first + second;
        totalCost += sum;
        let low = 0, high = ropes.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (ropes[mid] < sum) low = mid + 1;
            else high = mid;
        }
        ropes.splice(low, 0, sum);
    }
    console.log(totalCost);
}

main();
