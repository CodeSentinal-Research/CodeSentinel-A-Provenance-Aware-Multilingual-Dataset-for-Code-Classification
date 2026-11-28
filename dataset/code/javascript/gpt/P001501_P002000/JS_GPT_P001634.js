const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], m = d[p++], k = d[p++];
const a = Array.from({ length: n }, () => {
    const row = d.slice(p, p + m);
    p += m;
    return row;
});

function lowerBound(arr, x) {
    let l = 0, r = arr.length;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (arr[mid] < x) l = mid + 1;
        else r = mid;
    }
    return l;
}

let answer = -Infinity;
for (let top = 0; top < n; top++) {
    const col = new Array(m).fill(0);
    for (let bottom = top; bottom < n; bottom++) {
        for (let c = 0; c < m; c++) col[c] += a[bottom][c];

        const sorted = [0];
        let sum = 0;
        for (const x of col) {
            sum += x;
            const idx = lowerBound(sorted, sum - k);
            if (idx < sorted.length) answer = Math.max(answer, sum - sorted[idx]);
            const pos = lowerBound(sorted, sum);
            sorted.splice(pos, 0, sum);
        }
    }
}
console.log(answer === -Infinity ? "0" : answer);
