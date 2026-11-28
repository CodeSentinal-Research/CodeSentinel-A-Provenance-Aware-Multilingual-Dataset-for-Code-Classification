const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n);
        const res = [];
        for (const v of vals) {
            if (res.length === 0 || res[res.length - 1] !== v) res.push(v);
        }
        console.log(res.join(' '));
    }
}
main();