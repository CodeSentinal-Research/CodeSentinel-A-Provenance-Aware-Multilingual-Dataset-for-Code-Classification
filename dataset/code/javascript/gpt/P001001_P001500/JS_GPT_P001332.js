// P001332 - Restore Valid Parentheses
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    let lRem = 0, rRem = 0;
    for (const c of s) {
        if (c === "(") lRem++;
        else if (c === ")") {
            if (lRem > 0) lRem--;
            else rRem++;
        }
    }
    const results = new Set();
    function backtrack(idx, left, right, lCount, rCount, expr) {
        if (idx === s.length) {
            if (left === 0 && right === 0) results.add(expr);
            return;
        }
        const c = s[idx];
        if (c === "(" && left > 0) backtrack(idx + 1, left - 1, right, lCount, rCount, expr);
        if (c === ")" && right > 0) backtrack(idx + 1, left, right - 1, lCount, rCount, expr);
        if (c !== "(" && c !== ")") {
            backtrack(idx + 1, left, right, lCount, rCount, expr + c);
        } else if (c === "(") {
            backtrack(idx + 1, left, right, lCount + 1, rCount, expr + "(");
        } else if (rCount < lCount) {
            backtrack(idx + 1, left, right, lCount, rCount + 1, expr + ")");
        }
    }
    backtrack(0, lRem, rRem, 0, 0, "");
    for (const res of Array.from(results).sort()) console.log(res);
}

main();
