const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const size = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + size).map(Number);
        const n = parseInt(tokens[1 + size], 10);
        if (n >= 1 && n <= size) console.log(vals[n - 1]);
        else console.log(-1);
    }
}
main();