const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, 1 + n).map(Number);
        let maxVal = arr[0];
        for (let i = 1; i < n; i++) if (arr[i] > maxVal) maxVal = arr[i];
        console.log(maxVal);
    }
}
main();