const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n);
        let isPal = true;
        for (let i = 0; i < Math.floor(n / 2); i++) {
            if (vals[i] !== vals[n - 1 - i]) { isPal = false; break; }
        }
        console.log(isPal ? "true" : "false");
    }
}
main();