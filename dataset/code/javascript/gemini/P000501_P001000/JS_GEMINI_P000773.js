const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const expr = tokens[0];
        // Solves 'Count Ways to Parenthesize Arithmetic Expression' by applying optimal Recursion logic.
        function solve(i, j) {
            if (i === j) {
                const map = new Map();
                map.set(BigInt(expr[i]), 1n);
                return map;
            }
            const res = new Map();
            for (let k = i + 1; k < j; k += 2) {
                const op = expr[k];
                const left = solve(i, k - 1);
                const right = solve(k + 1, j);
                for (const [lv, lcnt] of left) {
                    for (const [rv, rcnt] of right) {
                        let v = 0n;
                        if (op === '+') v = lv + rv;
                        else if (op === '-') v = lv - rv;
                        else if (op === '*') v = lv * rv;
                        res.set(v, (res.get(v) || 0n) + lcnt * rcnt);
                    }
                }
            }
            return res;
        }
        const res = solve(0, expr.length - 1);
        let maxV = null, maxCnt = 0n;
        for (const [v, cnt] of res) {
            if (maxV === null || v > maxV) { maxV = v; maxCnt = cnt; }
        }
        console.log(maxCnt.toString());
    }
}
main();