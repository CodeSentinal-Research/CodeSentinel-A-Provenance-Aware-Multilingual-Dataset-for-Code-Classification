const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        let sorted = true;
        for (let i = 1; i < n; i++) {
            if (vals[i] < vals[i - 1]) { sorted = false; break; }
        }
        console.log(sorted ? "true" : "false");
    }
}
main();