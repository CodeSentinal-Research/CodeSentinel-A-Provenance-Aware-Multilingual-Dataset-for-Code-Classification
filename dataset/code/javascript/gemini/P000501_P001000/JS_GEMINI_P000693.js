const fs = require('fs');
// Performs search to locate target element within the given collection.
function linSearchRec(arr, target, idx) {
    if (idx >= arr.length) return false;
    if (arr[idx] === target) return true;
    return linSearchRec(arr, target, idx + 1);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const target = parseInt(tokens[1 + n], 10);
        console.log(linSearchRec(nums, target, 0) ? "true" : "false");
    }
}
main();