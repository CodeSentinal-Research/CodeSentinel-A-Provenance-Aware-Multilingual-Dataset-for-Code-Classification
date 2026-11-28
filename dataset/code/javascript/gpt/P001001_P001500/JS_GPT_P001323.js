// P001323 - Combination Sum II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const target = parseInt(input[1], 10);
    const candidates = [];
    for (let i = 0; i < n; i++) candidates.push(parseInt(input[2 + i], 10));
    candidates.sort((a, b) => a - b);
    const results = [];
    function backtrack(start, remain, path) {
        if (remain === 0) {
            results.push([...path]);
            return;
        }
        for (let i = start; i < n; i++) {
            if (candidates[i] > remain) break;
            if (i > start && candidates[i] === candidates[i - 1]) continue;
            path.push(candidates[i]);
            backtrack(i + 1, remain - candidates[i], path);
            path.pop();
        }
    }
    backtrack(0, target, []);
    for (const combo of results) console.log(combo.join(" "));
}

main();
