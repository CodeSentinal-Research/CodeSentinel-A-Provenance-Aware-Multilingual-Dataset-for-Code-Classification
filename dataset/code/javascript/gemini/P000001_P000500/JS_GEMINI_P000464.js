const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const target = Number(tokens[1]);
        const arr = tokens.slice(2, 2 + n).map(Number);
        let closest = arr[0], minDiff = Math.abs(arr[0] - target);
        for (let i = 1; i < n; i++) {
            const diff = Math.abs(arr[i] - target);
            if (diff < minDiff) {
                minDiff = diff;
                closest = arr[i];
            }
        }
        console.log(closest);
    }
}
main();