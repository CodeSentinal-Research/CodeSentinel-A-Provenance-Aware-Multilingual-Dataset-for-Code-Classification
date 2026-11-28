const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const x = parseInt(tokens[1 + n], 10);
        const less = vals.filter(v => v < x);
        const greater = vals.filter(v => v >= x);
        console.log([...less, ...greater].join(' '));
    }
}
main();