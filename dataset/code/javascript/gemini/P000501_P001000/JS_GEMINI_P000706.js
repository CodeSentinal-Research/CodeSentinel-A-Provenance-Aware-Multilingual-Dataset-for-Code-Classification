const fs = require('fs');
function genBin(n, cur) {
    if (cur.length === n) {
        console.log(cur);
        return;
    }
    genBin(n, cur + "0");
    genBin(n, cur + "1");
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        genBin(parseInt(tokens[0], 10), "");
    }
}
main();