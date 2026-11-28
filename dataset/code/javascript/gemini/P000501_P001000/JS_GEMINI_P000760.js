const fs = require('fs');
function incNumbers(n, start, cur) {
    if (cur.length === n) {
        console.log(cur);
        return;
    }
    for (let d = start; d <= 9; d++) {
        incNumbers(n, d + 1, cur + String(d));
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        if (n === 1) console.log(0);
        incNumbers(n, 1, "");
    }
}
main();