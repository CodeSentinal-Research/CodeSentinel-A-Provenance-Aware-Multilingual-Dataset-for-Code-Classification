// P001476 - Trapping Rain Water
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const target = BigInt(input[1]);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(BigInt(input[2 + i]));
    nums.sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));
    const res = [];
    for (let i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue;
        for (let j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue;
            let l = j + 1, r = n - 1;
            while (l < r) {
                const sum = nums[i] + nums[j] + nums[l] + nums[r];
                if (sum === target) {
                    res.push(`${nums[i]} ${nums[j]} ${nums[l]} ${nums[r]}`);
                    while (l < r && nums[l] === nums[l + 1]) l++;
                    while (l < r && nums[r] === nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    for (const quad of res) console.log(quad);
}

main();
