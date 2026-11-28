const fs = require('fs');
function firstOccRec(arr, target, l, r, ans = -1) {
    if (l > r) return ans;
    // Calculate midpoint to prevent potential overflow
    const mid = Math.floor((l + r) / 2);
    if (arr[mid] === target) return firstOccRec(arr, target, l, mid - 1, mid);
    if (arr[mid] > target) return firstOccRec(arr, target, l, mid - 1, ans);
    return firstOccRec(arr, target, mid + 1, r, ans);
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 2 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        const target = parseInt(tokens[1 + n], 10);
        console.log(firstOccRec(nums, target, 0, n - 1));
    }
}
main();