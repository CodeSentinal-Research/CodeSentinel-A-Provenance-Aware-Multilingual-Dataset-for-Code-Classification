// P001364 - K-Partition Problem
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    let sum = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[2 + i], 10);
        nums.push(val);
        sum += val;
    }
    if (sum % k !== 0) { console.log("NO"); return; }
    const target = sum / k;
    nums.sort((a, b) => b - a);
    if (nums[0] > target) { console.log("NO"); return; }
    const buckets = new Array(k).fill(0);
    function backtrack(idx) {
        if (idx === n) return true;
        for (let i = 0; i < k; i++) {
            if (buckets[i] + nums[idx] <= target) {
                buckets[i] += nums[idx];
                if (backtrack(idx + 1)) return true;
                buckets[i] -= nums[idx];
            }
            if (buckets[i] === 0) break;
        }
        return false;
    }
    console.log(backtrack(0) ? "YES" : "NO");
}

main();
