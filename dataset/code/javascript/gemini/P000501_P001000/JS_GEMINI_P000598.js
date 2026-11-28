const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 3 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const left = parseInt(tokens[1 + n], 10) - 1;
        const right = parseInt(tokens[2 + n], 10) - 1;
        const sub = vals.slice(left, right + 1).reverse();
        vals.splice(left, right - left + 1, ...sub);
        console.log(vals.join(' '));
    }
}
main();