const fs = require('fs');
function sumDigits(n) {
    if (n === 0n) return 0n;
    return (n % 10n) + sumDigits(n / 10n);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = BigInt(tokens[0]);
        console.log(sumDigits(n < 0n ? -n : n).toString());
    }
}
main();