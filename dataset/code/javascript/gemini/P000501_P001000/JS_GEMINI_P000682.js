const fs = require('fs');
function factRec(n) {
    if (n <= 1) return 1n;
    return BigInt(n) * factRec(n - 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        console.log(factRec(n).toString());
    }
}
main();