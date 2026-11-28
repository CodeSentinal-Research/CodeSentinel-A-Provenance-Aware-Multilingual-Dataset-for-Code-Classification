const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const pivot = vals[n - 1];
        const less = vals.slice(0, n - 1).filter(x => x < pivot);
        const greater = vals.slice(0, n - 1).filter(x => x >= pivot);
        console.log([...less, pivot, ...greater].join(' '));
    }
}
main();