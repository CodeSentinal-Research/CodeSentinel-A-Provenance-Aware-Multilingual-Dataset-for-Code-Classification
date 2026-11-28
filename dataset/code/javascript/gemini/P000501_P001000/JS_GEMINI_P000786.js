const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const total = nums.reduce((a, b) => a + b, 0);
        let left = 0;
        const ans = [];
        for (const x of nums) {
            const right = total - left - x;
            ans.push(Math.abs(left - right));
            left += x;
        }
        console.log(ans.join(' '));
    }
}
main();