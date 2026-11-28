const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const calls = tokens.slice(1, 1 + n).map(Number);
        const q = [];
        for (const t of calls) {
            q.push(t);
            while (q.length > 0 && q[0] < t - 3000) q.shift();
            console.log(q.length);
        }
    }
}
main();