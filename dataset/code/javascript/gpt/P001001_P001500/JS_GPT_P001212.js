// P001212 - Boolean Parenthesization
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const x = parseInt(input[0], 10);
    const target = parseInt(input[1], 10);
    const memo = new Map();
    function dp(i, t) {
        const code = i + "," + t;
        if (memo.has(code)) return memo.get(code);
        let res;
        if (t === 0) res = 0;
        else if (t === 1) res = i === 0 ? 2 : i;
        else if (i >= 30) res = t * 2;
        else {
            const r = t % x;
            const q = Math.floor(t / x);
            const cost = i === 0 ? 2 : i;
            res = Math.min(
                r * cost + dp(i + 1, q),
                (x - r) * cost + dp(i + 1, q + 1)
            );
        }
        memo.set(code, res);
        return res;
    }
    console.log(dp(0, target) - 1);
}

main();
