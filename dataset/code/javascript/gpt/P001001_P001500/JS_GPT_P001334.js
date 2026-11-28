// P001334 - Different Ways to Add Parentheses
const fs = require("fs");

function main() {
    const expr = fs.readFileSync(0, "utf8").trim();
    if (!expr) return;
    const memo = new Map();
    function compute(s) {
        if (memo.has(s)) return memo.get(s);
        const res = [];
        for (let i = 0; i < s.length; i++) {
            const op = s[i];
            if (op === "+" || op === "-" || op === "*") {
                const left = compute(s.slice(0, i));
                const right = compute(s.slice(i + 1));
                for (const l of left) {
                    for (const r of right) {
                        if (op === "+") res.push(l + r);
                        else if (op === "-") res.push(l - r);
                        else if (op === "*") res.push(l * r);
                    }
                }
            }
        }
        if (res.length === 0) res.push(parseInt(s, 10));
        memo.set(s, res);
        return res;
    }
    const ans = compute(expr).sort((a, b) => a - b);
    console.log(ans.join(" "));
}

main();
