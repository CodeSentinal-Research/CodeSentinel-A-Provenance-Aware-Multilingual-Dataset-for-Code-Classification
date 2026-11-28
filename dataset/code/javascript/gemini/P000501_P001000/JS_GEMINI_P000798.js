const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const seen = new Map();
        seen.set(0, -1);
        let cur = 0, maxLen = 0;
        for (let i = 0; i < n; i++) {
            cur += (nums[i] === 1 ? 1 : -1);
            if (seen.has(cur)) {
                maxLen = Math.max(maxLen, i - seen.get(cur));
            } else {
                seen.set(cur, i);
            }
        }
        console.log(maxLen);
    }
}
main();