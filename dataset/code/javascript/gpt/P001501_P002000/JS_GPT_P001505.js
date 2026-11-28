// P001505 - Number of Subarrays With Product Less Than K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    if (k <= 1) {
        console.log(0);
        return;
    }
    let prod = 1, l = 0, ans = 0;
    for (let r = 0; r < n; r++) {
        prod *= nums[r];
        while (prod >= k && l <= r) {
            prod /= nums[l];
            l++;
        }
        ans += r - l + 1;
    }
    console.log(ans);
}

main();
