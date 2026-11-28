const fs = require('fs');
function print1ToN(n) {
    if (n <= 0) return [];
    return [...print1ToN(n - 1), n];
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        console.log(print1ToN(parseInt(tokens[0], 10)).join(' '));
    }
}
main();