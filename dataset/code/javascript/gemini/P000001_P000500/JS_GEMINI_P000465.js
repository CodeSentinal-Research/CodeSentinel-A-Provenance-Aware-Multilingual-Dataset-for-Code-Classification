const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const diff = Math.abs(Number(tokens[1]));
        const arr = tokens.slice(2, 2 + n).map(Number);
        const seen = new Set();
        let found = false;
        for (const v of arr) {
            if (seen.has(v - diff) || seen.has(v + diff)) { found = true; break; }
            seen.add(v);
        }
        console.log(found ? "Yes" : "No");
    }
}
main();