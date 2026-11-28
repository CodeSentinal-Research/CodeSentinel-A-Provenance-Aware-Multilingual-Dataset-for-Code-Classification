const fs = require('fs');

function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, n + 1).map(Number);
        const q = parseInt(tokens[n + 1], 10);
        const queries = tokens.slice(n + 2, n + 2 + q).map(Number);
        for (const target of queries) {
            let found = false;
            for (const val of arr) {
                if (val === target) { found = true; break; }
            }
            console.log(found ? "Found" : "Not Found");
        }
    }
}

main();