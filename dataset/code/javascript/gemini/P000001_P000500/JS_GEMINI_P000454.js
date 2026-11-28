const fs = require('fs');
function isValid(arr, n, m, maxPages) {
    let students = 1, curr = 0;
    for (const p of arr) {
        if (p > maxPages) return false;
        if (curr + p > maxPages) {
            students++;
            curr = p;
            if (students > m) return false;
        } else {
            curr += p;
        }
    }
    return true;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const m = parseInt(tokens[1], 10);
        const arr = tokens.slice(2, 2 + n).map(Number);
        if (m > n) { console.log(-1); return; }
        let l = Math.max(...arr), r = arr.reduce((a, b) => a + b, 0), ans = r;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (isValid(arr, n, m, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        console.log(ans);
    }
}
main();