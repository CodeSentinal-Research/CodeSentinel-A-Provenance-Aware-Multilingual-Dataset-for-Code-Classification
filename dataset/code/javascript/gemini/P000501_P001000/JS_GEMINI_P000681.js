const fs = require('fs');
function sumRec(n) {
    if (n <= 0) return 0;
    return n + sumRec(n - 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        console.log(sumRec(n));
    }
}
main();