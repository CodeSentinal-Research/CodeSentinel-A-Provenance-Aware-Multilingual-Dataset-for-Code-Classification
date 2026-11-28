const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const evens = vals.filter((_, i) => i % 2 === 1).reverse();
        let eIdx = 0;
        const res = vals.map((v, i) => i % 2 === 1 ? evens[eIdx++] : v);
        console.log(res.join(' '));
    }
}
main();