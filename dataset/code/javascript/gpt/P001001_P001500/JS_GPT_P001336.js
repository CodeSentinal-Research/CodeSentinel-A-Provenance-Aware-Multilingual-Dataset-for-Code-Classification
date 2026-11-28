// P001336 - Partition into K Equal Sum Subsets
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    let sum = 0;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[2 + i], 10);
        nums.push(x);
        sum += x;
    }
    if (sum % k !== 0) { console.log("NO"); return; }
    const target = sum / k;
    nums.sort((a, b) => b - a);
    if (nums[0] > target) { console.log("NO"); return; }
    const subsets = new Array(k).fill(0);
    function backtrack(idx) {
        if (idx === n) return true;
        for (let i = 0; i < k; i++) {
            if (subsets[i] + nums[idx] <= target) {
                subsets[i] += nums[idx];
                if (backtrack(idx + 1)) return true;
                subsets[i] -= nums[idx];
            }
            if (subsets[i] === 0) break;
        }
        return false;
    }
    console.log(backtrack(0) ? "YES" : "NO");
}

main();
