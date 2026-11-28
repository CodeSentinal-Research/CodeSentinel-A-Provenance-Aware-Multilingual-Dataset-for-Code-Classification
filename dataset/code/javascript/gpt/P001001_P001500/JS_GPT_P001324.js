// P001324 - Combination Sum III
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const k = parseInt(input[0], 10);
    const n = parseInt(input[1], 10);
    const results = [];
    function backtrack(start, count, remain, path) {
        if (count === k) {
            if (remain === 0) results.push([...path]);
            return;
        }
        for (let i = start; i <= 9; i++) {
            if (i > remain) break;
            path.push(i);
            backtrack(i + 1, count + 1, remain - i, path);
            path.pop();
        }
    }
    backtrack(1, 0, n, []);
    for (const combo of results) console.log(combo.join(" "));
}

main();
