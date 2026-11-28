const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const sorted = [...nums].sort((a, b) => a - b);
        let l = 0, r = n - 1;
        while (l < n && nums[l] === sorted[l]) l++;
        while (r > l && nums[r] === sorted[r]) r--;
        console.log(r >= l ? r - l + 1 : 0);
    }
}
main();