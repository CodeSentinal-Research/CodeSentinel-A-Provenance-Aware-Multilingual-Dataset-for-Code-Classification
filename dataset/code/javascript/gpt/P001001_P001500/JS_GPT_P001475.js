// P001475 - Sort Colors
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const target = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    nums.sort((a, b) => a - b);
    let closestSum = nums[0] + nums[1] + nums[2];
    for (let i = 0; i < n - 2; i++) {
        let l = i + 1, r = n - 1;
        while (l < r) {
            const sum = nums[i] + nums[l] + nums[r];
            if (Math.abs(target - sum) < Math.abs(target - closestSum)) {
                closestSum = sum;
            }
            if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    console.log(closestSum);
}

main();
