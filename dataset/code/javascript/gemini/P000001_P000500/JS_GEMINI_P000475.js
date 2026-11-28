const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const target = Number(tokens[0]);
        const arr = tokens.slice(1).map(Number);
        console.log(arr.indexOf(target));
    }
}
main();