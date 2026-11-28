const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const l1 = tokens.slice(1, 1 + n).map(Number);
        const m = parseInt(tokens[1 + n], 10);
        const l2 = tokens.slice(2 + n, 2 + n + m).map(Number);
        const res = [...l1, ...l2].sort((a, b) => a - b);
        console.log(res.join(' '));
    }
}
main();