const fs = require('fs');
function print1ToN(n) {
    if (n <= 0) return [];
    return [...print1ToN(n - 1), n];
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        console.log(print1ToN(n).join(' '));
    }
}
main();