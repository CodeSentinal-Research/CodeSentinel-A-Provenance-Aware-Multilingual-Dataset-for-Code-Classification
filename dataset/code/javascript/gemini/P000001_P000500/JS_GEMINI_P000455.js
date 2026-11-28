const fs = require('fs');
function canShip(arr, d, cap) {
    let days = 1, curr = 0;
    for (const w of arr) {
        if (curr + w > cap) { days++; curr = w; }
        else curr += w;
    }
    return days <= d;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const d = parseInt(tokens[1], 10);
        const arr = tokens.slice(2, 2 + n).map(Number);
        let l = Math.max(...arr), r = arr.reduce((a, b) => a + b, 0), ans = r;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (canShip(arr, d, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        console.log(ans);
    }
}
main();