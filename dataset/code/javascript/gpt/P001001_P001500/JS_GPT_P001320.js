// P001320 - Generate Parentheses
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    const results = [];
    function backtrack(curr, open, close) {
        if (curr.length === 2 * n) {
            results.push(curr);
            return;
        }
        if (open < n) backtrack(curr + "(", open + 1, close);
        if (close < open) backtrack(curr + ")", open, close + 1);
    }
    backtrack("", 0, 0);
    for (const s of results) console.log(s);
}

main();
