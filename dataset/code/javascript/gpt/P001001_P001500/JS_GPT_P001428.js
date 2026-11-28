// P001428 - Count Good Meals
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    let maxXor = 0;
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            if (Math.abs(nums[i] - nums[j]) <= Math.min(nums[i], nums[j])) {
                maxXor = Math.max(maxXor, nums[i] ^ nums[j]);
            }
        }
    }
    console.log(maxXor);
}

main();
