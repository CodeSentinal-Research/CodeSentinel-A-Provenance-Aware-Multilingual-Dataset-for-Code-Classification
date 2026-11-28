const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10), k = parseInt(tokens[1], 10);
        let ans = 0;
        for (let i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }
        console.log(ans + 1);
    }
}
main();