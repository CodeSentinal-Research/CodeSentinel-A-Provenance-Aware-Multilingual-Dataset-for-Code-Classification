// P001333 - Expression Add Operators
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const num = input[0];
    const target = BigInt(input[1]);
    const results = [];
    function backtrack(idx, path, val, mult) {
        if (idx === num.length) {
            if (val === target) results.push(path);
            return;
        }
        for (let i = idx + 1; i <= num.length; i++) {
            const part = num.substring(idx, i);
            if (part.length > 1 && part[0] === "0") break;
            const curVal = BigInt(part);
            if (idx === 0) {
                backtrack(i, part, curVal, curVal);
            } else {
                backtrack(i, path + "+" + part, val + curVal, curVal);
                backtrack(i, path + "-" + part, val - curVal, -curVal);
                backtrack(i, path + "*" + part, val - mult + mult * curVal, mult * curVal);
            }
        }
    }
    backtrack(0, "", 0n, 0n);
    results.sort();
    for (const expr of results) console.log(expr);
}

main();
