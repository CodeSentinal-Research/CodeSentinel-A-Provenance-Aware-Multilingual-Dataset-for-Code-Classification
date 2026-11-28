const fs = require('fs');
function comb(n, k, start, cur) {
    if (cur.length === k) {
        console.log(cur.join(' '));
        return;
    }
    for (let i = start; i <= n; i++) {
        comb(n, k, i + 1, [...cur, i]);
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        comb(parseInt(tokens[0], 10), parseInt(tokens[1], 10), 1, []);
    }
}
main();