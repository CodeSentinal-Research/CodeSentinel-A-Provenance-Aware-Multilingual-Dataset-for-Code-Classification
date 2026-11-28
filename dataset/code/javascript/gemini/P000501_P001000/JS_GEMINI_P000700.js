const fs = require('fs');
function maxRec(arr, idx) {
    if (idx === arr.length - 1) return arr[idx];
    return Math.max(arr[idx], maxRec(arr, idx + 1));
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        console.log(maxRec(nums, 0));
    }
}
main();