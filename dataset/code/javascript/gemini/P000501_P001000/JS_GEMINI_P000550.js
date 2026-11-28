const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const p = tokens.slice(1, 1 + n).map(Number);
        const d = tokens.slice(1 + n, 1 + 2 * n).map(Number);
        let total = 0, curr = 0, start = 0;
        for (let i = 0; i < n; i++) {
            const diff = p[i] - d[i];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        console.log(total >= 0 ? start : -1);
    }
}
main();