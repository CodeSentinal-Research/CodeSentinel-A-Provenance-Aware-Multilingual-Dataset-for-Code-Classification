const fs = require('fs');
function genSubseq(s, idx, cur, res) {
    if (idx === s.length) {
        res.push(cur);
        return;
    }
    genSubseq(s, idx + 1, cur, res);
    genSubseq(s, idx + 1, cur + s[idx], res);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const s = tokens[0];
        const res = [];
        genSubseq(s, 0, "", res);
        res.sort();
        for (const str of res) console.log(str);
    }
}
main();