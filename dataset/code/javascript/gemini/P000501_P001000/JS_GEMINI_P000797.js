const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const counts = new Map();
        counts.set(0, 1);
        let cur = 0, ans = 0;
        for (const x of nums) {
            cur += (x === 1 ? 1 : -1);
            ans += (counts.get(cur) || 0);
            counts.set(cur, (counts.get(cur) || 0) + 1);
        }
        console.log(ans);
    }
}
main();