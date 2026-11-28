const fs = require('fs');
function combSum2(cands, target, idx, cur) {
    if (target === 0) {
        console.log(cur.join(' '));
        return;
    }
    for (let i = idx; i < cands.length; i++) {
        if (i > idx && cands[i] === cands[i - 1]) continue;
        if (cands[i] > target) break;
        combSum2(cands, target - cands[i], i + 1, [...cur, cands[i]]);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const cands = tokens.slice(1, 1 + n).map(Number).sort((a, b) => a - b);
        const target = parseInt(tokens[1 + n], 10);
        combSum2(cands, target, 0, []);
    }
}
main();