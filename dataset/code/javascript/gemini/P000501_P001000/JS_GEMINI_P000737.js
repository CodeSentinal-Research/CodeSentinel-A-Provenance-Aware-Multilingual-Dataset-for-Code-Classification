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
                    if (c === '+') res.push(l + r);
                    else if (c === '-') res.push(l - r);
                    else if (c === '*') res.push(l * r);
                }
            }
        }
    }
    if (res.length === 0) res.push(parseInt(expr, 10));
    return res;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const res = diffWays(tokens[0]).sort((a, b) => a - b);
        console.log(res.join(' '));
    }
}
main();