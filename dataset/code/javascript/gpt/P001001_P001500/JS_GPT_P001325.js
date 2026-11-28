// P001325 - Combinations
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const results = [];
    function backtrack(start, path) {
        if (path.length === k) {
            results.push([...path]);
            return;
        }
        for (let i = start; i <= n; i++) {
            path.push(i);
            backtrack(i + 1, path);
            path.pop();
        }
    }
    backtrack(1, []);
    for (const combo of results) console.log(combo.join(" "));
}

main();
