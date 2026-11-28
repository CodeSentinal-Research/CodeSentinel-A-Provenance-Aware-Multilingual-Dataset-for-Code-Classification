// P000226 - Count Inversions
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
function mergeSort(arr) {
    if (arr.length < 2) return { arr, inv: 0 };
    const mid = Math.floor(arr.length / 2);
    const left = mergeSort(arr.slice(0, mid));
    const right = mergeSort(arr.slice(mid));
    let i = 0, j = 0, inv = left.inv + right.inv;
    const merged = [];
    while (i < left.arr.length && j < right.arr.length) {
        if (left.arr[i] <= right.arr[j]) merged.push(left.arr[i++]);
        else { merged.push(right.arr[j++]); inv += left.arr.length - i; }
    }
    return { arr: merged.concat(left.arr.slice(i)).concat(right.arr.slice(j)), inv };
}
console.log(mergeSort(a).inv);
