const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const deck = tokens.slice(1, 1 + n).map(Number).sort((a, b) => a - b);
        const q = Array.from({length: n}, (_, i) => i);
        const res = new Array(n);
        for (const card of deck) {
            res[q.shift()] = card;
            if (q.length > 0) q.push(q.shift());
        }
        console.log(res.join(' '));
    }
}
main();