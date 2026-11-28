const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, n + 1).map(Number);
        const x = Number(tokens[n + 1]);
        console.log(arr.includes(x) ? "Found" : "Not Found");
    }
}

main();