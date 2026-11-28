const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        const seen = new Map();
        seen.set(0, -1);
        let cur = 0, ans = false;
        for (let i = 0; i < n; i++) {
            cur = (cur + nums[i]) % k;
            if (seen.has(cur)) {
                if (i - seen.get(cur) >= 2) { ans = true; break; }
            } else {
                seen.set(cur, i);
            }
        }
        console.log(ans ? "true" : "false");
    }
}
main();