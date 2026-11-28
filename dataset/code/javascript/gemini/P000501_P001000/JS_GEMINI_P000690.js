const fs = require('fs');
function decToBin(n) {
    if (n === 0n) return "0";
    if (n === 1n) return "1";
    return decToBin(n / 2n) + (n % 2n).toString();
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = BigInt(tokens[0]);
        console.log(decToBin(n));
    }
}
main();