const fs = require('fs');
function getAbbrevs(word) {
    const res = [];
    function backtrack(idx, cur, count) {
        if (idx === word.length) {
            res.push(cur + (count > 0 ? String(count) : ""));
            return;
        }
        backtrack(idx + 1, cur, count + 1);
        backtrack(idx + 1, cur + (count > 0 ? String(count) : "") + word[idx], 0);
    }
    backtrack(0, "", 0);
    return res.sort();
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        for (const s of getAbbrevs(tokens[0])) console.log(s);
    }
}
main();