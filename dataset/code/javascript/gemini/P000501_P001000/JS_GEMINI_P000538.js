const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(BigInt);
        const k = BigInt(tokens[1 + n]);
        const prefix = new Array(n + 1).fill(0n);
        for (let i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        const q = [];
        let minLen = n + 1;
        for (let i = 0; i <= n; i++) {
            while (q.length > 0 && prefix[i] - prefix[q[0]] >= k) {
                minLen = Math.min(minLen, i - q.shift());
            }
            while (q.length > 0 && prefix[q[q.length - 1]] >= prefix[i]) {
                q.pop();
            }
            q.push(i);
        }
        console.log(minLen <= n ? minLen : -1);
    }
}
main();