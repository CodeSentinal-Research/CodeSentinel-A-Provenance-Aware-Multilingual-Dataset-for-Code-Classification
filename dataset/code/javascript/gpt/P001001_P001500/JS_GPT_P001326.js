// P001326 - Subsets
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[1 + i], 10));
    const results = [];
    function backtrack(start, path) {
        results.push([...path]);
        for (let i = start; i < n; i++) {
            path.push(nums[i]);
            backtrack(i + 1, path);
            path.pop();
        }
    }
    backtrack(0, []);
    for (const subset of results) console.log(subset.join(" "));
}

main();
