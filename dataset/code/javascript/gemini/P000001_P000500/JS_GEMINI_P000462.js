const fs = require('fs');
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const arr = tokens.slice(1, n).map(Number);
        const diff = Math.floor((arr[arr.length - 1] - arr[0]) / (n - 1));
        for (let i = 0; i < arr.length - 1; i++) {
            if (arr[i + 1] - arr[i] !== diff) {
                console.log(arr[i] + diff);
                return;
            }
        }
        console.log(arr[arr.length - 1] + diff);
    }
}
main();