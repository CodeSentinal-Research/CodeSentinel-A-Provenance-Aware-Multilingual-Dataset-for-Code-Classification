const fs = require('fs');
function casePerm(s, idx, cur, res) {
    if (idx === s.length) {
        res.push(cur);
        return;
    }
    const ch = s[idx];
    if (/[a-zA-Z]/.test(ch)) {
        casePerm(s, idx + 1, cur + ch.toLowerCase(), res);
        casePerm(s, idx + 1, cur + ch.toUpperCase(), res);
    } else {
        casePerm(s, idx + 1, cur + ch, res);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const res = [];
        casePerm(tokens[0], 0, "", res);
        res.sort();
        for (const p of res) console.log(p);
    }
}
main();