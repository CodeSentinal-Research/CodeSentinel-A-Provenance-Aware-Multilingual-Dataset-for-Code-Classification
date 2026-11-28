// P001424 - Unique Number of Occurrences
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    if (n < 2) {
        console.log(0);
        return;
    }
    const score = nums[0] + nums[1];
    let ops = 1;
    for (let i = 2; i + 1 < n; i += 2) {
        if (nums[i] + nums[i + 1] === score) {
            ops++;
        } else {
            break;
        }
    }
    console.log(ops);
}

main();
