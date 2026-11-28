const fs = require('fs');
function canPlace(arr, c, dist) {
    let count = 1, last = arr[0];
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] - last >= dist) {
            count++;
            last = arr[i];
            if (count >= c) return true;
        }
    }
    return count >= c;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const c = parseInt(tokens[1], 10);
        const arr = tokens.slice(2, 2 + n).map(Number).sort((a, b) => a - b);
        let l = 1, r = arr[arr.length - 1] - arr[0], ans = 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = Math.floor((l + r) / 2);
            if (canPlace(arr, c, mid)) { ans = mid; l = mid + 1; }
            else r = mid - 1;
        }
        console.log(ans);
    }
}
main();