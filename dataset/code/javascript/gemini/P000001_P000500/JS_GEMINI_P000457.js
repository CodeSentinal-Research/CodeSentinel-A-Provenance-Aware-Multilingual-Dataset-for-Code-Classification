const fs = require('fs');
function check(arr, thresh, div) {
    let sum = 0;
    for (const v of arr) sum += Math.ceil(v / div);
    return sum <= thresh;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const thresh = parseInt(tokens[1], 10);
        const arr = tokens.slice(2, 2 + n).map(Number);
        let l = 1, r = Math.max(...arr), ans = r;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (check(arr, thresh, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        console.log(ans);
    }
}
main();