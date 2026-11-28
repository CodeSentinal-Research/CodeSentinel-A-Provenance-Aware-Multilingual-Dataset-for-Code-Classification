const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const target = Number(tokens[1]);
        const arr = tokens.slice(2, 2 + n).map(Number);
        console.log(arr.lastIndexOf(target));
    }
}
main();