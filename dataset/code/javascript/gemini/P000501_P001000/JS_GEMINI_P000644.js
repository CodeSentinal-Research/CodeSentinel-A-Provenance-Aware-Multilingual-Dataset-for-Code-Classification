const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const x = parseInt(tokens[1 + n], 10);
        const y = parseInt(tokens[2 + n], 10);
        const ix = vals.indexOf(x), iy = vals.indexOf(y);
        if (ix !== -1 && iy !== -1) {
            [vals[ix], vals[iy]] = [vals[iy], vals[ix]];
        }
        console.log(vals.join(' '));
    }
}
main();