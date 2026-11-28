const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const odd = vals.filter((_, i) => i % 2 === 0);
        const even = vals.filter((_, i) => i % 2 === 1);
        console.log([...odd, ...even].join(' '));
    }
}
main();