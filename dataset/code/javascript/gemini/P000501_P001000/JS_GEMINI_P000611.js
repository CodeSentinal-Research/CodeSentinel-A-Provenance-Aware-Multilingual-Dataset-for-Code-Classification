const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        let maxSum = 0;
        for (let i = 0; i < Math.floor(n / 2); i++) {
            maxSum = Math.max(maxSum, vals[i] + vals[n - 1 - i]);
        }
        console.log(maxSum);
    }
}
main();