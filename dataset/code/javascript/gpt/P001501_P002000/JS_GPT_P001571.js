// P001571 - Maximum Difference Between First and Last Element in Every Window
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let totalOnes = 0;
    for (const x of nums) if (x === 1) totalOnes++;
    if (totalOnes <= 1 || totalOnes === n) {
        console.log(0);
        return;
    }
    let curOnes = 0;
    for (let i = 0; i < totalOnes; i++) if (nums[i] === 1) curOnes++;
    let maxOnes = curOnes;
    for (let i = 1; i < n; i++) {
        if (nums[(i + totalOnes - 1) % n] === 1) curOnes++;
        if (nums[i - 1] === 1) curOnes--;
        maxOnes = Math.max(maxOnes, curOnes);
    }
    console.log(totalOnes - maxOnes);
}

main();
