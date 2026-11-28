const fs = require('fs');
function printNTo1(n) {
    if (n <= 0) return [];
    return [n, ...printNTo1(n - 1)];
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        console.log(printNTo1(n).join(' '));
    }
}
main();