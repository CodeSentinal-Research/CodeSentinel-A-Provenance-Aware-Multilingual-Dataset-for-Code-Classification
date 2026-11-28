// P001306 - Optimal File Merge Pattern
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const files = [];
    for (let i = 0; i < n; i++) files.push(parseInt(input[1 + i], 10));
    files.sort((a, b) => a - b);
    let totalCost = 0;
    while (files.length > 1) {
        const first = files.shift();
        const second = files.shift();
        const sum = first + second;
        totalCost += sum;
        let low = 0, high = files.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (files[mid] < sum) low = mid + 1;
            else high = mid;
        }
        files.splice(low, 0, sum);
    }
    console.log(totalCost);
}

main();
