const fs = require('fs');
function countDigits(n) {
    if (n < 10n) return 1;
    return 1 + countDigits(n / 10n);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = BigInt(tokens[0]);
        console.log(countDigits(n < 0n ? -n : n));
    }
}
main();