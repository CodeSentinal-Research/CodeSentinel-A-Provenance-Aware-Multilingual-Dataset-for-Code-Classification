// P001293 - Maximum Product After K Increments
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    nums.sort((a, b) => a - b);
    for (let step = 0; step < k; step++) {
        nums[0]++;
        let i = 0;
        while (i < n - 1 && nums[i] > nums[i + 1]) {
            const temp = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = temp;
            i++;
        }
    }
    const MOD = 1000000007n;
    let prod = 1n;
    for (const x of nums) {
        prod = (prod * BigInt(x)) % MOD;
    }
    console.log(prod.toString());
}

main();
