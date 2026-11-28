const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const total = nums.reduce((a, b) => a + b, 0);
        let minDiff = Infinity;
        let bestPart = [];
        const half = Math.floor(n / 2);
        function backtrack(idx, count, curSum, curPart) {
            if (count === half) {
                const diff = Math.abs(total - 2 * curSum);
                if (diff < minDiff) {
                    minDiff = diff;
                    bestPart = curPart;
                }
                return;
            }
            if (idx === n || (half - count) > (n - idx)) return;
            backtrack(idx + 1, count + 1, curSum + nums[idx], [...curPart, nums[idx]]);
            backtrack(idx + 1, count, curSum, curPart);
        }
        backtrack(0, 0, 0, []);
        console.log(minDiff);
        console.log(bestPart.join(' '));
    }
}
main();