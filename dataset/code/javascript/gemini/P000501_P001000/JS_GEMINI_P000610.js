const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const vals = tokens.slice(1, 1 + n).map(Number);
        const res = [];
        let curSum = 0;
        for (let i = 1; i < n; i++) {
            if (vals[i] === 0) {
                res.push(curSum);
                curSum = 0;
            } else {
                curSum += vals[i];
            }
        }
        console.log(res.join(' '));
    }
}
main();