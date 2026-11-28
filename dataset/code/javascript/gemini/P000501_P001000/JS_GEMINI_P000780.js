const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(BigInt);
        let cur = 0n;
        const res = [];
        for (const x of nums) {
            cur += x;
            res.push(cur);
        }
        console.log(res.join(' '));
    }
}
main();