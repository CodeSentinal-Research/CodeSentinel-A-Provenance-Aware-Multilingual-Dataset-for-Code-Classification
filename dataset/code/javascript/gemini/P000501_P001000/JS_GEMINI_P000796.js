const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(BigInt);
        const p = BigInt(tokens[1 + n]);
        const total = nums.reduce((a, b) => a + b, 0n);
        const target = total % p;
        if (target === 0n) { console.log(0); return; }
        const seen = new Map();
        seen.set(0n, -1);
        let cur = 0n, minLen = n;
        for (let i = 0; i < n; i++) {
            cur = (cur + nums[i]) % p;
            const needed = (cur - target + p) % p;
            if (seen.has(needed)) {
                minLen = Math.min(minLen, i - seen.get(needed));
            }
            seen.set(cur, i);
        }
        console.log(minLen < n ? minLen : -1);
    }
}
main();