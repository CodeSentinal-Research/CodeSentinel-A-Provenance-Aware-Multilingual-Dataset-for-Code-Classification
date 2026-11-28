const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        const seen = new Map();
        seen.set(0, -1);
        let cur = 0, maxLen = 0;
        for (let i = 0; i < n; i++) {
            cur += nums[i];
            if (seen.has(cur - k)) {
                maxLen = Math.max(maxLen, i - seen.get(cur - k));
            }
            if (!seen.has(cur)) seen.set(cur, i);
        }
        console.log(maxLen);
    }
}
main();