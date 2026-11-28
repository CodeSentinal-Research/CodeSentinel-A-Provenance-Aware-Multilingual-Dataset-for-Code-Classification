const fs = require('fs');

function diffWaysToCompute(expr) {
    const memo = new Map();
    function dfs(s) {
        if (memo.has(s)) return memo.get(s);
        const res = [];
        for (let i = 0; i < s.length; i++) {
            const c = s[i];
            if (c === '+' || c === '-' || c === '*') {
                const left = dfs(s.slice(0, i));
                const right = dfs(s.slice(i + 1));
                for (const l of left) {
                    for (const r of right) {
                        if (c === '+') res.push(l + r);
                        else if (c === '-') res.push(l - r);
                        else if (c === '*') res.push(l * r);
                    }
                }
            }
        }
        if (res.length === 0) res.push(parseInt(s, 10));
        memo.set(s, res);
        return res;
    }
    return dfs(expr);
}

function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 1 && input[0] !== '') {
        const res = diffWaysToCompute(input[0]);
        res.forEach(v => console.log(v));
    }
}

main();