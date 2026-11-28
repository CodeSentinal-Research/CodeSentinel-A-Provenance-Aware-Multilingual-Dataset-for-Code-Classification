// P001233 - Fractional Knapsack
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const jobs = [];
    let maxDeadline = 0;
    for (let i = 0; i < n; i++) {
        const id = input[ptr++];
        const deadline = parseInt(input[ptr++], 10);
        const profit = parseInt(input[ptr++], 10);
        jobs.push({ id, deadline, profit });
        if (deadline > maxDeadline) maxDeadline = deadline;
    }
    jobs.sort((a, b) => b.profit - a.profit);
    const slots = new Array(maxDeadline + 1).fill(false);
    let count = 0, totalProfit = 0;
    for (const job of jobs) {
        for (let t = job.deadline; t > 0; t--) {
            if (!slots[t]) {
                slots[t] = true;
                count++;
                totalProfit += job.profit;
                break;
            }
        }
    }
    console.log(count + " " + totalProfit);
}

main();
