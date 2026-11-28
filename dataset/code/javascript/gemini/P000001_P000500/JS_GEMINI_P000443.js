const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, 1 + n).map(Number);
        let l = 0, r = n - 1;
        while (l < r) {
            // Calculate midpoint to prevent potential overflow
            const mid = (l + r) >> 1;
            if (arr[mid] > arr[mid + 1]) r = mid;
            else l = mid + 1;
        }
        console.log(l);
    }
}
main();