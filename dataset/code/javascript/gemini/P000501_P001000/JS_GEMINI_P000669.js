const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        if (n === 0) console.log(-1);
        else {
            const vals = tokens.slice(1, 1 + n).map(Number);
            console.log(Math.min(...vals));
        }
    } else {
        console.log(-1);
    }
}
main();