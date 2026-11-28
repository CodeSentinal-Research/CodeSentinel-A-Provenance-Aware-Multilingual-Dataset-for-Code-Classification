// P000224 - Job Sequencing Problem
const fs = require("fs");
const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
let p = 0;
const n = Number(input[p++]);
const jobs = [];
for (let i = 0; i < n; i++) {
    const id = input[p++], deadline = Number(input[p++]), profit = Number(input[p++]);
    jobs.push({id, deadline, profit});
}
jobs.sort((a, b) => b.profit - a.profit);
const maxD = Math.max(...jobs.map(j => j.deadline), 0);
const slot = Array(maxD + 1).fill(false);
let totalProfit = 0, count = 0;
for (const job of jobs) {
    for (let t = Math.min(job.deadline, maxD); t > 0; t--) {
        if (!slot[t]) {
            slot[t] = true;
            totalProfit += job.profit;
            count++;
            break;
        }
    }
}
console.log(`${totalProfit} ${count}`);
