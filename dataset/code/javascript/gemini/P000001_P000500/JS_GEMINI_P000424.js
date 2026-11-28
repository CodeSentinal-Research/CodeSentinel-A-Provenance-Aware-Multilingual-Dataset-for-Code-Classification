const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const emails = tokens.slice(1, n + 1);
        const count = {};
        for (const e of emails) count[e] = (count[e] || 0) + 1;
        const seen = new Set();
        for (const e of emails) {
            if (count[e] > 1 && !seen.has(e)) {
                console.log(e);
                seen.add(e);
            }
        }
    }
}
main();