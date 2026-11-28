const fs = require('fs');
function canSplit(arr, m, maxSum) {
    let count = 1, curr = 0;
    for (const v of arr) {
        if (curr + v > maxSum) { count++; curr = v; }
        else curr += v;
    }
    return count <= m;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const m = parseInt(tokens[1], 10);
        const arr = tokens.slice(2, 2 + n).map(Number);
        let l = Math.max(...arr), r = arr.reduce((a, b) => a + b, 0), ans = r;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (canSplit(arr, m, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        console.log(ans);
    }
}
main();