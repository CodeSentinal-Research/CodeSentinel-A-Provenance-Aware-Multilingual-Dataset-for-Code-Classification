const fs = require('fs');
function isPal(arr, l, r) {
    if (l >= r) return true;
    if (arr[l] !== arr[r]) return false;
    return isPal(arr, l + 1, r - 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n);
        console.log(isPal(nums, 0, n - 1) ? "true" : "false");
    }
}
main();