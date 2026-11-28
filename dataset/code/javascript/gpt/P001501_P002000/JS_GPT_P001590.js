// P001590 - Maximum Robots Within Budget
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const budget = BigInt(input[1]);
    let ptr = 2;
    const chargeTimes = [];
    for (let i = 0; i < n; i++) chargeTimes.push(BigInt(input[ptr++]));
    const runningCosts = [];
    for (let i = 0; i < n; i++) runningCosts.push(BigInt(input[ptr++]));

    const maxQ = [];
    let l = 0, costSum = 0n, maxRobots = 0;
    for (let r = 0; r < n; r++) {
        while (maxQ.length > 0 && chargeTimes[r] > maxQ[maxQ.length - 1]) maxQ.pop();
        maxQ.push(chargeTimes[r]);
        costSum += runningCosts[r];
        while (l <= r && (maxQ[0] + BigInt(r - l + 1) * costSum > budget)) {
            if (chargeTimes[l] === maxQ[0]) maxQ.shift();
            costSum -= runningCosts[l];
            l++;
        }
        maxRobots = Math.max(maxRobots, r - l + 1);
    }
    console.log(maxRobots);
}

main();
