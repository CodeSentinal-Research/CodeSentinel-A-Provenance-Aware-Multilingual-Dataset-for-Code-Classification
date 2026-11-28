const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const goal = parseInt(tokens[1 + n], 10);
        const counts = new Map();
        counts.set(0, 1);
        let cur = 0, ans = 0;
        for (const x of nums) {
            cur += x;
            ans += (counts.get(cur - goal) || 0);
            counts.set(cur, (counts.get(cur) || 0) + 1);
        }
        console.log(ans);
    }
}
main();