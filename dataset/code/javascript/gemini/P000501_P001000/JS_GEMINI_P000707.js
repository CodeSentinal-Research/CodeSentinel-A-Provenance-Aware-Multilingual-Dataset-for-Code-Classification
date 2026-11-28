const fs = require('fs');
function genPar(n, o, c, cur) {
    if (cur.length === 2 * n) {
        console.log(cur);
        return;
    }
    if (o < n) genPar(n, o + 1, c, cur + "(");
    if (c < o) genPar(n, o, c + 1, cur + ")");
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        genPar(parseInt(tokens[0], 10), 0, 0, "");
    }
}
main();