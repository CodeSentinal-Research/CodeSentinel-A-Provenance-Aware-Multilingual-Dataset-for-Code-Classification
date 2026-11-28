// P001579 - Maximum Count of Negative Numbers in a Window
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const q = parseInt(input[1], 10);
    let ptr = 2;
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(BigInt(input[ptr++]));
    nums.sort((a, b) => (a < b ? -1 : a > b ? 1 : 0));
    const prefix = new Array(n + 1).fill(0n);
    for (let i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

    const res = [];
    for (let qi = 0; qi < q; qi++) {
        const x = BigInt(input[ptr++]);
        let low = 0, high = n - 1, idx = n;
        while (low <= high) {
            const mid = (low + high) >> 1;
            if (nums[mid] >= x) {
                idx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        const leftCost = x * BigInt(idx) - prefix[idx];
        const rightCost = (prefix[n] - prefix[idx]) - x * BigInt(n - idx);
        res.push((leftCost + rightCost).toString());
    }
    console.log(res.join(" "));
}

main();
