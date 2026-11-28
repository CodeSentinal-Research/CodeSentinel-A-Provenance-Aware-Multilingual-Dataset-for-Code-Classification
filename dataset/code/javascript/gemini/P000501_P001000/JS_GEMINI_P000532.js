const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const t = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        let time = 0;
        for (let i = 0; i < n; i++) {
            time += (i <= k) ? Math.min(t[i], t[k]) : Math.min(t[i], t[k] - 1);
        }
        console.log(time);
    }
}
main();