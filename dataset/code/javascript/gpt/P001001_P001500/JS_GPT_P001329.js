// P001329 - Permutations II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    nums.sort((a, b) => a - b);
    const results = [];
    const used = new Array(n).fill(false);
    function backtrack(path) {
        if (path.length === n) {
            results.push([...path]);
            return;
        }
        for (let i = 0; i < n; i++) {
            if (used[i]) continue;
            if (i > 0 && nums[i] === nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            path.push(nums[i]);
            backtrack(path);
            path.pop();
            used[i] = false;
        }
    }
    backtrack([]);
    for (const perm of results) console.log(perm.join(" "));
}

main();
