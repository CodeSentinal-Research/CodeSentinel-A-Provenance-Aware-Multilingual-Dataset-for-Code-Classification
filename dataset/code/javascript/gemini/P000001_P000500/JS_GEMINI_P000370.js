const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, n + 1).map(Number);
        const seen = new Set();
        let dup = -1;
        for (const v of arr) {
            if (seen.has(v)) {
                dup = v;
                break;
            }
            seen.add(v);
        }
        console.log(dup);
    }
}

main();