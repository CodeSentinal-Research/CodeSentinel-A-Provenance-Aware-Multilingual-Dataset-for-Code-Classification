const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const target = Number(tokens[1]);
        const arr = tokens.slice(2, 2 + n).map(Number);
        let l = 0, r = n - 1, ans = n;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = (l + r) >> 1;
            if (arr[mid] >= target) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        console.log(ans);
    }
}
main();