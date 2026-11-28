const fs = require('fs');
function main() {
    const input = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (input.length >= 2) {
        const n = parseInt(input[0], 10);
        const arr = input.slice(1, n + 1).map(Number);
        let maxSoFar = arr[0], currMax = arr[0];
        for (let i = 1; i < n; i++) {
            currMax = Math.max(arr[i], currMax + arr[i]);
            maxSoFar = Math.max(maxSoFar, currMax);
        }
        console.log(maxSoFar);
    }
}
main();