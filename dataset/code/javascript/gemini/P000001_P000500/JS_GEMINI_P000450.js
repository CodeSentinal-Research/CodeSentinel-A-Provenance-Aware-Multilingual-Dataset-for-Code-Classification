const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const k = parseInt(tokens[1], 10);
        const arr = tokens.slice(2, 2 + n).map(Number);
        let l = 0, r = n - 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = (l + r) >> 1;
            const missing = arr[mid] - (mid + 1);
            if (missing < k) l = mid + 1;
            else r = mid - 1;
        }
        console.log(l + k);
    }
}
main();