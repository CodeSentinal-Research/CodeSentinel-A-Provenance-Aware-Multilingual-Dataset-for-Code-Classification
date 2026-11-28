const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, n + 1).map(Number);
        const idx = arr.findIndex(v => v > 0);
        console.log(idx);
    }
}

main();