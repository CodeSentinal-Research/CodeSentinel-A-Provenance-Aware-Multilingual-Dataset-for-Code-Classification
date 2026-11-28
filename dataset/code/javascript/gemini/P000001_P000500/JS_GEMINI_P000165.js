const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const n = parseInt(input[0], 10);
        const arr = input.slice(1, n + 1).map(Number);
        let maxP = arr[0], minP = arr[0], ans = arr[0];
        for (let i = 1; i < n; i++) {
            if (arr[i] < 0) {
                const t = maxP; maxP = minP; minP = t;
            }
            maxP = Math.max(arr[i], maxP * arr[i]);
            minP = Math.min(arr[i], minP * arr[i]);
            ans = Math.max(ans, maxP);
        }
        console.log(ans);
    }
}
main();