const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const m = parseInt(tokens[0], 10), n = parseInt(tokens[1], 10), k = parseInt(tokens[2], 10);
        const merged = tokens.slice(3, 3 + m + n).map(Number).sort((a, b) => a - b);
        console.log(merged[k - 1]);
    }
}
main();