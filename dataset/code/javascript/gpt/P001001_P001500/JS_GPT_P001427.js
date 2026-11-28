// P001427 - Count Largest Group
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[ptr++], 10));
    const divisors = [];
    for (let i = 0; i < m; i++) divisors.push(parseInt(input[ptr++], 10));
    let bestDiv = divisors[0], maxScore = -1;
    for (const d of divisors) {
        let score = 0;
        for (const num of nums) {
            if (num % d === 0) score++;
        }
        if (score > maxScore || (score === maxScore && d < bestDiv)) {
            maxScore = score;
            bestDiv = d;
        }
    }
    console.log(bestDiv);
}

main();
