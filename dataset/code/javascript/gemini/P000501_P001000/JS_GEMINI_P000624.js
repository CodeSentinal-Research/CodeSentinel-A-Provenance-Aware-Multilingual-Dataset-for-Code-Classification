const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const even = vals.filter(x => x % 2 === 0);
        const odd = vals.filter(x => x % 2 !== 0);
        console.log([...even, ...odd].join(' '));
    }
}
main();