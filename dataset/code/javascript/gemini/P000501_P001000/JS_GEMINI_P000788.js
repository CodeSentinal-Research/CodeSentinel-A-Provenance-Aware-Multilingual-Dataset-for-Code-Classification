const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const k = parseInt(tokens[1 + n], 10);
        let cur = 0;
        for (let i = 0; i < k; i++) cur += nums[i];
        let maxSum = cur;
        for (let i = k; i < n; i++) {
            cur += nums[i] - nums[i - k];
            maxSum = Math.max(maxSum, cur);
        }
        console.log((maxSum / k).toFixed(5));
    }
}
main();