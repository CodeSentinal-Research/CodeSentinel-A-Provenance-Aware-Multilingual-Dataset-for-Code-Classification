const fs = require('fs');
function diffWays(expr) {
    const res = [];
    for (let i = 0; i < expr.length; i++) {
        const c = expr[i];
        if (c === '+' || c === '-' || c === '*') {
            const left = diffWays(expr.slice(0, i));
            const right = diffWays(expr.slice(i + 1));
            for (const l of left) {
                for (const r of right) {
                    res.push(`(${l}${c}${r})`);
                }
            }
        }
    }
    if (res.length === 0) res.push(expr);
    return res;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const res = Array.from(new Set(diffWays(tokens[0]))).sort();
        for (const s of res) console.log(s);
    }
}
main();