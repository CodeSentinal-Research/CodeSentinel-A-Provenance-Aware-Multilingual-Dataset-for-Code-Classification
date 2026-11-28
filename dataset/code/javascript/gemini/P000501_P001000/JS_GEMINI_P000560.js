const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const q = tokens.slice(1, 1 + n).map(Number);
        const half = Math.floor(n / 2);
        const res = [];
        for (let i = 0; i < half; i++) {
            res.push(q[i], q[i + half]);
        }
        console.log(res.join(' '));
    }
}
main();