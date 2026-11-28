const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = BigInt(tokens[0]);
        let l = 1n, r = n, isSq = false;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            const mid = (l + r) / 2n;
            const sq = mid * mid;
            if (sq === n) { isSq = true; break; }
            else if (sq < n) l = mid + 1n;
            else r = mid - 1n;
        }
        console.log(isSq ? "Yes" : "No");
    }
}
main();