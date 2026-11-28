const fs = require('fs');
function genNoConsOnes(n, cur) {
    if (cur.length === n) {
        console.log(cur);
        return;
    }
    genNoConsOnes(n, cur + "0");
    if (cur.length === 0 || cur[cur.length - 1] !== '1') {
        genNoConsOnes(n, cur + "1");
    }
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        genNoConsOnes(parseInt(tokens[0], 10), "");
    }
}
main();