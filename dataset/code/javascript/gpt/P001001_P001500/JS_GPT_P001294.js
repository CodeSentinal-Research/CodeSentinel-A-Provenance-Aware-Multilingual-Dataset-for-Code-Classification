// P001294 - Rearrange Array to Maximize Prefix Score
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    nums.sort((a, b) => b - a);
    let prefix = 0n, score = 0;
    for (const x of nums) {
        prefix += BigInt(x);
        if (prefix > 0n) score++;
        else break;
    }
    console.log(score);
}

main();
