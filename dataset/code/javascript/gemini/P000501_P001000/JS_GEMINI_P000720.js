const fs = require('fs');
function addOps(num, target, idx, curExpr, curVal, prevOp, res) {
    if (idx === num.length) {
        if (curVal === target) res.push(curExpr);
        return;
    }
    for (let i = idx; i < num.length; i++) {
        if (i > idx && num[idx] === '0') break;
        const part = num.slice(idx, i + 1);
        const v = BigInt(part);
        if (idx === 0) {
            addOps(num, target, i + 1, part, v, v, res);
        } else {
            addOps(num, target, i + 1, curExpr + "+" + part, curVal + v, v, res);
            addOps(num, target, i + 1, curExpr + "-" + part, curVal - v, -v, res);
            addOps(num, target, i + 1, curExpr + "*" + part, curVal - prevOp + prevOp * v, prevOp * v, res);
        }
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const num = tokens[0], target = BigInt(tokens[1]);
        const res = [];
        addOps(num, target, 0, "", 0n, 0n, res);
        res.sort();
        for (const s of res) console.log(s);
    }
}
main();