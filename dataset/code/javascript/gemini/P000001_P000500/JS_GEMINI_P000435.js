const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const target = Number(tokens[1]);
        const arr = tokens.slice(2, 2 + n).map(Number);
        let count = 0;
        for (const v of arr) if (v === target) count++;
        console.log(count);
    }
}
main();