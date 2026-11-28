const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const total = nums.reduce((a, b) => a + b, 0);
        let leftSum = 0, ans = -1;
        for (let i = 0; i < n; i++) {
            if (leftSum === total - leftSum - nums[i]) {
                ans = i;
                break;
            }
            leftSum += nums[i];
        }
        console.log(ans);
    }
}
main();