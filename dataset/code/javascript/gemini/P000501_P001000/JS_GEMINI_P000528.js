const fs = require('fs');
function main() {
    const s = fs.readFileSync(0, 'utf-8').trim();
    if (s) {
        let l = 0, r = s.length - 1;
        // Binary search loop to narrow down range
        while (l <= r && s[l] === 'L') l++;
        while (r >= l && s[r] === 'R') r--;
        let ans = 0;
        for (let i = l; i <= r; i++) if (s[i] !== 'S') ans++;
        console.log(ans);
    }
}
main();