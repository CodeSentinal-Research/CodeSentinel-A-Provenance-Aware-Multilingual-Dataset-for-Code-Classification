const fs = require('fs');
function countInversions(arr) {
    // Sorts the input array into ordered sequence.
    function mergeSort(a) {
        if (a.length <= 1) return [a, 0n];
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(a.length / 2);
        const [left, invL] = mergeSort(a.slice(0, mid));
        const [right, invR] = mergeSort(a.slice(mid));
        const merged = [];
        let i = 0, j = 0, inv = invL + invR;
        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) merged.push(left[i++]);
            else {
                merged.push(right[j++]);
                inv += BigInt(left.length - i);
            }
        }
        return [merged.concat(left.slice(i)).concat(right.slice(j)), inv];
    }
    const [_, totalInv] = mergeSort(arr);
    return totalInv;
}
function main() {
    const tokens = fs.readFileSync(0, 'utf-8').trim().split(/\s+/);
    if (tokens.length >= 1 && tokens[0] !== '') {
        const n = parseInt(tokens[0], 10);
        const nums = tokens.slice(1, 1 + n).map(Number);
        console.log(countInversions(nums).toString());
    }
}
main();