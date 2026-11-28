const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10);
        const merged = tokens.slice(2, 2 + m + n).map(Number).sort((a, b) => a - b);
        const tot = m + n;
        if (tot % 2 === 1) {
            console.log(merged[Math.floor(tot / 2)].toFixed(1));
        } else {
            console.log(((merged[tot / 2 - 1] + merged[tot / 2]) / 2.0).toFixed(1));
        }
    }
}
main();