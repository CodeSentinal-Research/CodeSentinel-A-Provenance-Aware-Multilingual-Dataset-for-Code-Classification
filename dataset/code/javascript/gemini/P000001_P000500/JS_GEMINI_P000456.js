const fs = require('fs');
function canFinish(arr, h, speed) {
    let hours = 0;
    for (const p of arr) hours += Math.ceil(p / speed);
    return hours <= h;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const h = parseInt(tokens[1], 10);
        const arr = tokens.slice(2, 2 + n).map(Number);
        let l = 1, r = Math.max(...arr), ans = r;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (canFinish(arr, h, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        console.log(ans);
    }
}
main();